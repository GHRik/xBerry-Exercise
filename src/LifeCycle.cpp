#include "../headers/LifeCycle.hpp"

LifeCycle::LifeCycle(iLogger *logger) : logger(logger)
{
}

LifeCycle::~LifeCycle()
{
}

ErrorCodes LifeCycle::registry( iLifeCycle *ptrToRegistry )
{
    if(ptrToRegistry != nullptr)
    {
        objectToLifeArray.push_back(ptrToRegistry);
        return ErrorCodes::OK;
    }
    else
    {
        logger->logError("Try to registry nullptr to lifeCycle");
        return ErrorCodes::NOT_OK;
    }
}

void LifeCycle::start()
{
    for(size_t i = 0; i < objectToLifeArray.size(); ++i)
    {
        objectToLifeArray[i]->run();
    }

    logger->logInfo("Life cycle start with: "+std::to_string(objectToLifeArray.size())+" services");
}

void LifeCycle::stop()
{
        for(size_t i = 0; i < objectToLifeArray.size(); ++i)
    {
        objectToLifeArray[i]->stop();
    }
    logger->logInfo("Life cycle STOP with: "+std::to_string(objectToLifeArray.size())+" services");
}
