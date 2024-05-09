#include <DHT.h>

// Khai báo chân động cơ:
int engine_PIN1 = 27;
int engine_PIN2 = 26;
int enable_PIN = 14;

// Thuộc tính kiểm soát tốc độ:
const int freq = 30000;   // Tín hiệu 30000hz
const int pwnChannel = 0; // Kênh số 0
const int resolution = 8; // Độ phân giải 8 bit
int dutyCycle = 200;      // Bắt đầu chu kỳ nhiệm vụ: 200 (Có khả năng nếu nhỏ hơn 200 thì động cơ không hoạt động được - phụ thuộc vào tần số động cơ)


// Khai báo DHT11 và các biến đo lường:
#define DHTPIN 19
#define DHTTYPE DHT11
DHT dht_sensor(DHTPIN, DHTTYPE); 

int temperature = 0;
int humidity = 0;


void setup() {
  pinMode(engine_PIN1, OUTPUT);
  pinMode(engine_PIN2, OUTPUT);
  pinMode(enable_PIN, OUTPUT);

  // Định cấu hình tín hiệu PWM
  ledcSetup(pwnChannel, freq, resolution);  

  // Chọn GPIO sẽ nhận tín hiệu
  ledcAttachPin(enable_PIN, pwnChannel);

  // DHT11 bắt đầu đo:
  dht_sensor.begin();


  Serial.begin(115200);
  Serial.println("Testing....");
}

// Hàm đo môi trường của DHT11:
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

  delay(2000);
}

void loop() {
  // Get_DHT11_Data();

  // Nếu nhiệt độ vượt qua ngưỡng 30 độ thì tăng nhanh tốc độ quay của quạt:
  // Cho động cơ chuyển động về sau với tốc độ tăng dần:
  digitalWrite(engine_PIN1, LOW);
  digitalWrite(engine_PIN2, HIGH);

  delay(2000);

  // while (temperature >= 35) {
  //   ledcWrite(pwnChannel, dutyCycle);
  //   dutyCycle = dutyCycle + 5;
  // }

  // // Khi het nong thi ngung:
  // digitalWrite(engine_PIN1, LOW);
  // digitalWrite(engine_PIN2, LOW);
}





