#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include "DHT_Sensor.h"
#include "Flame_Sensor.h"
#include "MQ_Sensor.h"

//---------------------------------------------------------Khai báo---------------------------------------------------------
#define DHT_1_PIN 18
DHT_Sensor dhtSensor_1(DHT_1_PIN);

#define FlameSensor_1_PIN 19
Flame_Sensor FlameSensor_1(FlameSensor_1_PIN);

// Mã id của các cảm biến trong tầng chiếu theo DB (VD 1 tầng 1 bộ gồm: 1 DHT 11, 1 FlameSensor)
const int dht11_id = 1;
const int flame_id = 2;

// Khai báo chân động cơ L298N:
int engine_PIN1 = 27;
int engine_PIN2 = 26;
int enable_PIN = 14;

// Thuộc tính kiểm soát tốc độ của L298N:
const int freq = 30000;   // Tín hiệu 30000hz
const int pwnChannel = 0; // Kênh số 0
const int resolution = 8; // Độ phân giải 8 bit
int dutyCycle = 200;      // Bắt đầu chu kỳ nhiệm vụ: 200 (Có khả năng nếu nhỏ hơn 200 thì động cơ không hoạt động được - phụ thuộc vào tần số động cơ)

// Thiết lập thông tin ESP32: kết nối đến web và tạo webserver
const char *ssid = "ThuVien";
const char *password = "K@thuvien";
const char *URL = "http://10.188.99.74/NCKH_NhaYen/Website/index.php"; // Website cần gửi thông tin đến

// Tạo Webserver cho ESP32 để lắng nghe sự thay đổi:
WebServer server(80);

// Các tham số sẽ được cập nhật thông qua ESP32 Server:
unsigned long previousMillis = 0;
unsigned long interval = 2000;  // Mặc định là 2s gửi dữ liệu
unsigned long temperature = 35; // Mặc định 35 độ C thì quạt sẽ quay tản nhiệt

//---------------------------------------------------------Các hàm thành phần---------------------------------------------------------
void L298N_setup(int PIN1, int PIN2, int EnablePIN)
{
  // Thiết lập các chân L298N:
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(EnablePIN, OUTPUT);

  // Định cấu hình tín hiệu PWM:
  ledcSetup(pwnChannel, freq, resolution);

  // Thiết lập chân GPIO sẽ nhận tín hiệu:
  ledcAttachPin(EnablePIN, pwnChannel);
};

void L298N_Moving(int PIN1, int PIN2, int choice, int duration)
{
  switch (choice)
  {
  case 0:
    Serial.println('Stop! ');
    digitalWrite(PIN1, LOW);
    digitalWrite(PIN2, LOW);
    delay(duration);

    break;
  case 1:
    Serial.println('Moving forward...');
    digitalWrite(PIN1, HIGH);
    digitalWrite(PIN2, LOW);
    delay(duration);

    break;
  case 2:
    Serial.println('Moving back...');
    digitalWrite(PIN1, LOW);
    digitalWrite(PIN2, HIGH);
    delay(duration);

    break;
  case 3:
    digitalWrite(PIN1, HIGH);
    digitalWrite(PIN2, LOW);

    while (dutyCycle <= 255)
    {
      ledcWrite(pwnChannel, dutyCycle);
      dutyCycle = dutyCycle + 5;
      delay(duration);
    }

    dutyCycle = 200;

    break;
  default:
    break;
  }
};

void ESP32_ConnectWifi()
{
  WiFi.mode(WIFI_OFF);
  delay(1000);

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected success!");
};

void ESP32_SendData(String data, int duration)
{
  HTTPClient http;
  http.begin(URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(data);
  String payload = http.getString();

  Serial.println("---------------------------------------Sender's info------------------------------------------");
  Serial.print("URL: ");
  Serial.println(URL);
  Serial.print("Data: ");
  Serial.println(data);
  Serial.print("httpCode: ");
  Serial.println(httpCode);
  Serial.print("payload: ");
  Serial.println(payload);
  delay(duration); // Delay duration s rồi insert 1 lần
};

void ESP32_WebServer() {
  String html = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\" />";
  html += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" />";
  html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />";
  html += "<title>Quản lý nhà yến</title>";
  html += "<link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css\" integrity=\"sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm\" crossorigin=\"anonymous\" />";
  html += "<link href=\"https://unpkg.com/boxicons@2.1.2/css/boxicons.min.css\" rel=\"stylesheet\" />";
  html += "<link rel=\"stylesheet\" href=\"css/style.css\" /></head>";
  html += "<body><div class=\"col-12 mainpage\">";
  html += "<form action=\"/update-settings\" method=\"POST\" class=\"col-sm-5\" style=\"background-color: white; padding: 30px 15px 0 15px;border: 1px solid #ccc;border-radius: 10px; margin: auto;\">";
  html += "<h2 class=\"text-center\" style=\"margin-bottom: 30px;\">Cập nhật thông số hệ thống</h2>";
  html += "<div class=\"mb-3 row\">";
  html += "<label for=\"interval\" class=\"col-sm-4 col-form-label\">Thời gian gửi dữ liệu:</label>";
  html += "<div class=\"col-sm-8\">";
  html += "<input type=\"number\" class=\"form-control\" id=\"interval\" name=\"interval\" min=\"1\" value=\"" + String(interval / 1000) + "\">";
  html += "</div></div>";
  html += "<div class=\"mb-3 row\">";
  html += "<label for=\"temperature\" class=\"col-sm-4 col-form-label\">Nhiệt độ nguy hiểm:</label>";
  html += "<div class=\"col-sm-8\">";
  html += "<input type=\"number\" class=\"form-control\" id=\"temperature\" name=\"temperature\" value=\"" + String(temperature) + "\">";
  html += "</div></div>";
  html += "<div class=\"mb-3 row\">";
  html += "<div class=\"col-sm-12\" style=\"text-align: right;\">";
  html += "<input type=\"submit\" value=\"Cập nhật\" class=\"btn btn-primary mb-3\">";
  html += "</div></div></form></div>";
  html += "<script src=\"https://code.jquery.com/jquery-3.2.1.slim.min.js\" integrity=\"sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN\" crossorigin=\"anonymous\"></script>";
  html += "<script src=\"https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js\" integrity=\"sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q\" crossorigin=\"anonymous\"></script>";
  html += "<script src=\"https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js\" integrity=\"sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl\" crossorigin=\"anonymous\"></script>";
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

void ESP32_UpdateParams() {
  if (server.hasArg("interval") && server.hasArg("temperature")) {
    String getInterval = server.arg("interval");
    String getTemp = server.arg("temperature");
    interval = getInterval.toInt() * 1000;        // Nhân cho 1000 vì Arduino chỉ dùng miliseconds
    temperature = getTemp.toFloat();              // Cập nhật giá trị nhiệt độ
    String message = "<script>alert('Settings Updated'); window.location.href = \"/\";</script>";
    server.send(200, "text/html", message);
  } else {
    String message = "<script>alert('Invalid Request'); window.location.href = \"/\";</script>";
    server.send(400, "text/html", message);
  }
}


void configESPServer()
{
  server.on("/", ESP32_WebServer);
  server.on("/update-settings", HTTP_POST, ESP32_UpdateParams);
  server.begin();
};

//---------------------------------------------------------Chương trình---------------------------------------------------------
void setup()
{
  // Setup L298N:
  L298N_setup(engine_PIN1, engine_PIN2, enable_PIN);

  // DHT11 starts:
  dhtSensor_1.begin();

  // Connect wifi:
  ESP32_ConnectWifi();

  // Config ESP32 Server:
  configESPServer();

  Serial.begin(115200);
}

void loop()
{
  Serial.println("---------------------------------------------------ESP32 Webserver info---------------------------------------------------");
  Serial.print("Connected to: ");
  Serial.println(ssid);
  Serial.print("ESP32's IP address: ");
  Serial.println(WiFi.localIP());

  // DHT 11 - 1's working:
  float temperatureDHT11 = dhtSensor_1.readTemperature();
  float humidity = dhtSensor_1.readHumidity();
  dhtSensor_1.showData(temperatureDHT11, humidity);

  // Flame sensors're working:
  int fireSignal = FlameSensor_1.checkingFire();
  Serial.print("- Fire signal: ");
  Serial.println(fireSignal);

  // L298N's working:
  if (temperatureDHT11 > temperature)
  {
    // Cho động cơ L298N chuyển động về sau với tốc độ tăng dần nếu nhiệt độ trên 33 độ C:
    L298N_Moving(engine_PIN1, engine_PIN2, 3, 200);
  }
  else
  {
    // Cho động cơ L298N ngừng lại:
    L298N_Moving(engine_PIN1, engine_PIN2, 0, 200);
  };

  // ESP32 Server:
  server.handleClient();
  unsigned long currentMillis = millis();

  // ESP32 sends data:
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    ESP32_SendData(
      "temperature=" + String(temperatureDHT11) +
      "&humidity=" + String(humidity) +
      "&fire=" + String(fireSignal),
      interval);
  };

  delay(200);
}
