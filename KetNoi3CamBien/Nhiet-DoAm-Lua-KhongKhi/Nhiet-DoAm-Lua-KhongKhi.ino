#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// For connect and send data:
const char* ssid = "Trong Nghia";
const char* password = "0949496465@";
String URL = "http://192.168.1.84/NCKH_NhaYen/KetNoi3CamBien/test_data.php";

// DHT11:
#define DHTPIN 19
#define DHTTYPE DHT11

// MQ Sensor:
#define AIRPIN 32

DHT dht_sensor(DHTPIN, DHTTYPE);

// Fire sensor:
int sensor = 13;

int fire = 1;
int temperature = 0;
int humidity = 0;
float air = 100;

void setup() {
  Serial.begin(115200);
  dht_sensor.begin();
  connectWiFi();
}

void connectWiFi() {
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
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  Get_Data();

  String data = "temperature=" + String(temperature) + "&humidity=" + String(humidity) + "&fire=" + String(fire) + "&air=" + String(air);

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
  delay(5000);  // Delay 5s rồi insert 1 lần
}

void Get_Data() {
  temperature = dht_sensor.readTemperature(); // C
  humidity = dht_sensor.readHumidity();
  fire = digitalRead(sensor);
  air = 100 - (analogRead(AIRPIN) * 0.01); 

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor");
    temperature = 0;
    humidity = 0;
  }

  Serial.println("Temperature: " + String(temperature) + " C");
  Serial.println("Humidity: " + String(humidity) + " %");
  if (fire == 1) {
    Serial.println("Fire alarm: No Fire");
  } else {
    Serial.println("Fire alarm: Fire");
  }

  Serial.println("Air: " + String(air) + "%");
}