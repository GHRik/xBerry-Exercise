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

ErrorCodes Logger::logError(std::string log)
{
    std::cout << "ERROR: " << log << std::endl;
    return ErrorCodes::OK;
}

ErrorCodes Logger::logWarrning(std::string log)
{
    #ifdef LOG_LEVEL
    std::cout << "WARRNING: " << log << std::endl;
    #endif // LOG_LEVEL
    return ErrorCodes::OK;
}

ErrorCodes Logger::logInfo(std::string log)
{
    #ifdef LOG_LEVEL
    std::cout << "INFO: " << log << std::endl;
    #endif // LOG_LEVEL
    return ErrorCodes::OK;
}


ErrorCodes Logger::logEvent(std::string prefix,std::string log)
{
    std::cout << prefix <<": " << log << std::endl;
    return ErrorCodes::OK;
}

