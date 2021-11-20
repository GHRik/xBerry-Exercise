#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "iSensor.hpp"
#include "SensorMenager.hpp"
#include "iLogger.hpp"
#include "iMainNetworkListener.hpp"

class Sensor : public iSensor
{
    public:
        Sensor( iSensorMenager *sensorMenager, iLogger *logger, iMainNetworkListener *networkListener);
        virtual ~Sensor();
        ErrorCodes run();
        ErrorCodes routine(){return ErrorCodes::NOT_OK;};

    private:
        iSensorMenager *sensorMenager;
        iLogger *logger;
        iMainNetworkListener *networkListener;
};

#endif // SENSOR_HPP
