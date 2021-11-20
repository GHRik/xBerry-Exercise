#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "iLifeCycle.hpp"
#include "iLogger.hpp"
#include <string>
#include <iostream>


#define LOG_LEVEL

class Logger : public iLogger, public iLifeCycle
{
    public:
        Logger();
        virtual ~Logger();
        ErrorCodes logError(std::string log);
        ErrorCodes logInfo(std::string log);
        ErrorCodes logWarrning(std::string log);
        ErrorCodes logEvent( std::string prefix ,std::string log);
        ErrorCodes registry(iLifeCycle *ptrToRegistry);
        ErrorCodes run(){return ErrorCodes::NOT_OK;}
        void stop(){}
        void passLifeCycle(iLifeCycle *lifeCycle);
    private:
        iLifeCycle *lifeCycle;
};

#endif // LOGGER_HPP
