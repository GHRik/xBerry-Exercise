#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "iSensor.hpp"
#include "SensorMenager.hpp"

class Sensor : public iSensor
{
    public:
        Sensor( iSensorMenager *sensorMenager );
        virtual ~Sensor();
        ErrorCodes run(){return ErrorCodes::NOT_OK;};
        ErrorCodes routine(){return ErrorCodes::NOT_OK;};

    private:
        iSensorMenager *sensorMenager;
};

#endif // SENSOR_HPP
