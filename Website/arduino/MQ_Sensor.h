#ifndef MQ_SENSOR_H
#define MQ_SENSOR_H

class MQ_Sensor {
    private:
        int PIN;

    public: 
        MQ_Sensor(int MQ_PIN);
        int checkAir();
};

#endif