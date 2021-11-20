#include "../headers/SensorMenager.hpp"


SensorMenager::~SensorMenager()
{
    //dtor
}

ErrorCodes SensorMenager::registry(iLifeCycle *ptrToRegistry)
{
    ErrorCodes code;
    code = lifeCycle->registry(this);
    if(code != ErrorCodes ::NOT_OK)
    {
        return code;
    }
    return code;
}

ErrorCodes SensorMenager::registrySensor(iSensor* ptrToRegistry)
{
    if(ptrToRegistry != nullptr)
    {
        sensorsVect.push_back(ptrToRegistry);
        return ErrorCodes::OK;
    }
    else
    {
        logger->logError("Try to registry nullptr to sensorMenager");
        return ErrorCodes::NOT_OK;
    }
}

ErrorCodes SensorMenager::run()
{
    ErrorCodes code = ErrorCodes::NOT_OK;
    for(size_t i = 0; i < sensorsVect.size(); ++i)
    {
        code = sensorsVect[i]->run();
        if(code != ErrorCodes::OK)
        {
            return code;
        }
    }
    logger->logInfo("Start "+std::to_string(sensorsVect.size())+"sensors");
    return code;
}

void SensorMenager::stop()
{
    for(size_t i = 0; i < sensorsVect.size(); ++i)
    {
        sensorsVect[i]->stop();
    }
    logger->logInfo("STOP "+std::to_string(sensorsVect.size())+"sensors");
    actual_status = Status::STOP;
}
