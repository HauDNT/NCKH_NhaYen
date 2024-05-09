#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT_Sensor.h"
#include "Flame_Sensor.h"
#include "MQ_Sensor.h"

//---------------------------------------------------------Khai báo---------------------------------------------------------
#define DHT_1_PIN 18
DHT_Sensor dhtSensor_1(DHT_1_PIN);

#define FlameSensor_1_PIN 19
Flame_Sensor FlameSensor_1(FlameSensor_1_PIN);

#define MQ_PIN_1 21
MQ_Sensor MQSensor_1(MQ_PIN_1);

// Khai báo chân động cơ L298N:
int engine_PIN1 = 27;
int engine_PIN2 = 26;
int enable_PIN = 14;

// Thuộc tính kiểm soát tốc độ của L298N:
const int freq = 30000;   // Tín hiệu 30000hz
const int pwnChannel = 0; // Kênh số 0
const int resolution = 8; // Độ phân giải 8 bit
int dutyCycle = 200;      // Bắt đầu chu kỳ nhiệm vụ: 200 (Có khả năng nếu nhỏ hơn 200 thì động cơ không hoạt động được - phụ thuộc vào tần số động cơ)

// ESP32 send data properties:
const char* ssid = "47";
const char* password = "Trungkien123@";
const char* URL = "http://192.168.1.8/NCKH_NhaYen/KetNoi3CamBien/test_data.php";

//----------------------------------------------------------------------------------------------------------------------------







//---------------------------------------------------------Các hàm thành phần---------------------------------------------------------
void L298N_setup (int PIN1, int PIN2, int EnablePIN) {
  // Thiết lập các chân L298N:
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(EnablePIN, OUTPUT);

  // Định cấu hình tín hiệu PWM:
  ledcSetup(pwnChannel, freq, resolution);  

  // Thiết lập chân GPIO sẽ nhận tín hiệu:
  ledcAttachPin(EnablePIN, pwnChannel);
};

void L298N_Moving(int PIN1, int PIN2, int choice, int duration) {
  switch(choice) {
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

      while(dutyCycle <= 255) {
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

void ESP32_ConnectWifi() {
  WiFi.mode(WIFI_OFF);
  delay(1000);

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected to: ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
};

void ESP32_SendData(String data, int duration) {
  HTTPClient http;
  http.begin(URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(data);
  String payload = http.getString();

  Serial.println("---------------------------------------Info------------------------------------------");
  Serial.print("URL: ");
  Serial.println(URL);
  Serial.print("Data: ");
  Serial.println(data);
  Serial.print("httpCode: ");
  Serial.println(httpCode);
  Serial.print("payload: ");
  Serial.println(payload);
  Serial.println("----------------------------------------End------------------------------------------");
  delay(duration);  // Delay duration s rồi insert 1 lần
};

//---------------------------------------------------------Chương trình---------------------------------------------------------
void setup() {
  // Setup L298N:
  L298N_setup(engine_PIN1, engine_PIN2, enable_PIN);

  // DHT11 starts:
  dhtSensor_1.begin();

  // Connect wifi:
  ESP32_ConnectWifi();

  Serial.begin(115200);
}

void loop() {
  // DHT 11 - 1's working:
  float temperature = dhtSensor_1.readTemperature();
  float humidity = dhtSensor_1.readHumidity();
  dhtSensor_1.showData(temperature, humidity);

  // Flame sensors're working:
  int fireSignal = FlameSensor_1.checkingFire();
  Serial.print("- Fire signal: ");
  Serial.println(fireSignal);

  // MQ-6s're working:
  Serial.print("- Air checking: ");
  Serial.println(MQSensor_1.checkAir());

  // ESP32 sends data:
  ESP32_SendData(
    "temperature=" + String(temperature) + "&humidity=" + String(humidity) + "&fire=" + String(fireSignal) + "&air=" + String(MQSensor_1.checkAir()),
    2000
  );

  if (fireSignal == 0) {
    // Cho động cơ L298N chuyển động về sau với tốc độ tăng dần nếu có lửa:
    L298N_Moving(engine_PIN1, engine_PIN2, 3, 200);
  } else if (fireSignal == 1) {
    // Cho động cơ L298N ngừng lại nếu không có lửa:
    L298N_Moving(engine_PIN1, engine_PIN2, 0, 200);
  }


  delay(200);
}
