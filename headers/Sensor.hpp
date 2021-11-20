#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "iSensor.hpp"
#include "SensorMenager.hpp"
#include "iLogger.hpp"
#include "iMainNetworkListener.hpp"
#include <thread>

class Sensor : public iSensor
{
    public:
        Sensor( iSensorMenager *sensorMenager, iLogger *logger, iMainNetworkListener *networkListener);
        virtual ~Sensor();
        ErrorCodes run();
        ErrorCodes routine();

    private:
        iSensorMenager *sensorMenager;
        iLogger *logger;
        iMainNetworkListener *networkListener;
       // std::thread t1;
};

#endif // SENSOR_HPP
