#include "../headers/Sensor.hpp"
Sensor::~Sensor()
{
    //dtor
}

Sensor::Sensor(iSensorMenager *sensorMenager, iLogger *logger) : sensorMenager(sensorMenager), logger(logger)
{
    sensorMenager->registrySensor(this);
}

ErrorCodes Sensor::run()
{
    logger->logInfo("Start sensor");
    return ErrorCodes::OK;
}
