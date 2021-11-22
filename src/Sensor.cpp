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
    srand(time( NULL ));
    while(actual_status == Status::PROCESSING)
    {


        networkListener->writeToBuffor(rand() % 100);
    }
    std::chrono::milliseconds timespan(1);
    std::this_thread::sleep_for(timespan);
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

