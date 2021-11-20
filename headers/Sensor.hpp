#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "iSensor.hpp"
#include "SensorMenager.hpp"
#include "iLogger.hpp"

class Sensor : public iSensor
{
    public:
        Sensor( iSensorMenager *sensorMenager, iLogger *logger);
        virtual ~Sensor();
        ErrorCodes run();
        ErrorCodes routine(){return ErrorCodes::NOT_OK;};

    private:
        iSensorMenager *sensorMenager;
        iLogger *logger;
};

#endif // SENSOR_HPP
