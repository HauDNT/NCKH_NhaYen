#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// For connect and send data:
const char* ssid = "Trong Nghia";
const char* password = "0949496465@";
String URL = "http://192.168.1.84/Embedded-Projects/ESP32_DHT11_XAMPP/WebData.php";

// For DHT11:
#define DHTPIN 19
#define DHTTYPE DHT11
DHT dht_sensor(DHTPIN, DHTTYPE); 

int temperature = 0;
int humidity = 0;

void setup() {
  Serial.begin(115200);
  dht_sensor.begin();
  connectWiFi();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  Get_DHT11_Data();

  String data = "temperature=" + String(temperature) + "&humidity=" + String(humidity);

  // Send data to server with HTTP post request:
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
  Serial.print("httpCode: ");- 
  Serial.println(httpCode);
  Serial.print("payload: ");
  Serial.println(payload);
  Serial.println("----------------------------------------End------------------------------------------");
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

void Get_DHT11_Data() {
  temperature = dht_sensor.readTemperature(); // C
  humidity = dht_sensor.readHumidity();

  if(isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor");
    temperature = 0;
    humidity = 0;
  }

  Serial.println("Temperature: " + String(temperature) + " C");
  Serial.println("Humidity: " + String(humidity) + " %%");
}

