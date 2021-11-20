#include "../headers/Sensor.hpp"
Sensor::~Sensor()
{
    //dtor
}

Sensor::Sensor(iSensorMenager *sensorMenager, iLogger *logger, iMainNetworkListener *networkListener)
: sensorMenager(sensorMenager), logger(logger), networkListener(networkListener)
{
    sensorMenager->registrySensor(this);
    actual_status = Status::START;
}

ErrorCodes Sensor::run()
{
    logger->logInfo("Start sensor");
    actual_status = Status::PROCESSING;
    std::thread t1(routine);
    return ErrorCodes::OK;
}

ErrorCodes Sensor::routine()
{
    ErrorCodes code = ErrorCodes::OK;
    while(actual_status == Status::PROCESSING)
    {
        code = networkListener->writeToBuffor(rand() % 100);
    }
    return code;
}
