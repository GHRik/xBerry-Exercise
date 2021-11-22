#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "iSensor.hpp"
#include "iLogger.hpp"
#include "iSensorMenager.hpp"
#include "iMainNetworkListener.hpp"
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cstdio>

class Sensor : public iSensor
{
    public:
        Sensor( iSensorMenager *sensorMenager, iLogger *logger, iMainNetworkListener *networkListener);
        virtual ~Sensor();
        ErrorCodes run();
        void stop();
        void routine();

    private:
        iSensorMenager *sensorMenager;
        iLogger *logger;
        iMainNetworkListener *networkListener;
        std::thread t1;
};

#endif // SENSOR_HPP
