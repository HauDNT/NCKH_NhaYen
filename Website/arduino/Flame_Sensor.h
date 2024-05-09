#ifndef FLAME_SENSOR_H
#define FLAME_SENSOR_H

class Flame_Sensor {
  private:
    int PIN;

  public:
    Flame_Sensor(int FlameSensor_PIN);
    int checkingFire();
};

#endif