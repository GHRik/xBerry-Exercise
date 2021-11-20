#include "../headers/SensorMenager.hpp"


SensorMenager::~SensorMenager()
{
    //dtor
}

ErrorCodes SensorMenager::registry(iLifeCycle *ptrToRegistry)
{
    return lifeCycle->registry(this);
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
            break;
        }
    }
    return code;
}
