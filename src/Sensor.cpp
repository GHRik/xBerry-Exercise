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

void Sensor::routine()
{
    logger->logInfo("Start routine in sensor object");
    while(actual_status == Status::PROCESSING)
    {
        std::chrono::milliseconds timespan(1000);
        std::this_thread::sleep_for(timespan);
        networkListener->writeToBuffor(rand() % 100);
    }
}

ErrorCodes Sensor::run()
{
    logger->logInfo("Start sensor");
    actual_status = Status::PROCESSING;
    this->t1 =std::thread(&Sensor::routine,this);
    return ErrorCodes::OK;
}

void Sensor::stop()
{
    actual_status = Status::STOP;
    t1.join();
}

