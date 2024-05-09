#include "HardwareSerial.h"
#include "esp32-hal-gpio.h"
#include "Flame_Sensor.h"

Flame_Sensor::Flame_Sensor(int FlameSensor_PIN) : PIN(FlameSensor_PIN) {}

int Flame_Sensor::checkingFire() {
  return digitalRead(this -> PIN);
}