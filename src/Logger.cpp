#include "Logger.hpp"

Logger::Logger()
{
    //ctor
}

Logger::~Logger()
{
    //dtor
}

void Logger::passLifeCycle(iLifeCycle *lifeCycle)
{
    this->lifeCycle = lifeCycle;
}

ErrorCodes Logger::registry(iLifeCycle *ptrToRegistry)
{
    return lifeCycle->registry(this);
}
