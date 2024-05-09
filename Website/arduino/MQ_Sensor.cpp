#include "esp32-hal-gpio.h"
#include <Arduino.h>
#include "MQ_Sensor.h"


MQ_Sensor::MQ_Sensor(int MQ_PIN) : PIN(MQ_PIN) {}

int MQ_Sensor::checkAir() {
    return digitalRead(this -> PIN);
}