#include "DHT_Sensor.h"

DHT_Sensor::DHT_Sensor(int DHT_PIN) : PIN(DHT_PIN), dht(DHT_PIN, DHT11) {}

void DHT_Sensor::begin() {
    dht.begin();
}

float DHT_Sensor::readTemperature() {
    return dht.readTemperature();
}

float DHT_Sensor::readHumidity() {
    return dht.readHumidity();
}

void DHT_Sensor::showData(float temperature, float humidity) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
}