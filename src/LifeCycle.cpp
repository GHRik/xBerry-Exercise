#include "../headers/LifeCycle.hpp"

LifeCycle::LifeCycle(iLogger *logger)
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
    for(int i = 0; i < objectToLifeArray.size(); ++i)
    {
        objectToLifeArray[i].run();
    }
}


