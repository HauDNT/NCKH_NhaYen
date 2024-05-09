// Khai báo chân động cơ:
int engine_PIN1 = 27;
int engine_PIN2 = 26;
int enable_PIN = 14;

// Thuộc tính kiểm soát tốc độ:
const int freq = 30000;   // Tín hiệu 30000hz
const int pwnChannel = 0; // Kênh số 0
const int resolution = 8; // Độ phân giải 8 bit
int dutyCycle = 200;      // Bắt đầu chu kỳ nhiệm vụ: 200 (Có khả năng nếu nhỏ hơn 200 thì động cơ không hoạt động được - phụ thuộc vào tần số động cơ)

void setup() {
  pinMode(engine_PIN1, OUTPUT);
  pinMode(engine_PIN2, OUTPUT);
  pinMode(enable_PIN, OUTPUT);

  // Định cấu hình tín hiệu PWM
  ledcSetup(pwnChannel, freq, resolution);  

  // Chọn GPIO sẽ nhận tín hiệu
  ledcAttachPin(enable_PIN, pwnChannel);

  Serial.begin(115200);
  Serial.println("Testing....");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Cho động cơ chuyển động về phía trước:
  Serial.println('Moving forward: ');
  digitalWrite(engine_PIN1, LOW);
  digitalWrite(engine_PIN2, HIGH);
  delay(2000);

  // Dừng động cơ:
  Serial.println('Stop: ');
  digitalWrite(engine_PIN1, LOW);
  digitalWrite(engine_PIN2, LOW);
  delay(1000);

  // Cho động cơ chuyển động ngược lại:
  Serial.println('Moving back: ');
  digitalWrite(engine_PIN1, HIGH);
  digitalWrite(engine_PIN2, LOW);
  delay(2000);

  // Cho động cơ chuyển động về sau với tốc độ tăng dần:
  digitalWrite(engine_PIN1, LOW);
  digitalWrite(engine_PIN2, HIGH);

  while(dutyCycle <= 255) {
    ledcWrite(pwnChannel, dutyCycle);
    Serial.println("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(1000);
  }

  dutyCycle = 200;    // Khi tốc độ vượt qua 255 thì đặt về trạng thái bình thường.
}