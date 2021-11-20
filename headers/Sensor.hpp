#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "iSensor.hpp"
#include "SensorMenager.hpp"

class Sensor : iSensor
{
    public:
        Sensor( SensorMenager *sensorMenager ) : sensorMenager(sensorMenager){};
        virtual ~Sensor();
        ErrorCodes run(){return ErrorCodes::NOT_OK;};
        ErrorCodes routine(){return ErrorCodes::NOT_OK;};

    private:
        SensorMenager *sensorMenager;
};

#endif // SENSOR_HPP
