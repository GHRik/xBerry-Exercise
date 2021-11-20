#include "../headers/Sensor.hpp"
Sensor::~Sensor()
{
    //dtor
}

Sensor::Sensor(iSensorMenager *sensorMenager, iLogger *logger, iMainNetworkListener *networkListener)
: sensorMenager(sensorMenager), logger(logger), networkListener(networkListener)
{
    sensorMenager->registrySensor(this);
}

ErrorCodes Sensor::run()
{
    logger->logInfo("Start sensor");
    networkListener->writeToBuffor(rand() % 100);
    return ErrorCodes::OK;
}
