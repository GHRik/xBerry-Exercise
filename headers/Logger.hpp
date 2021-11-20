#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "iLifeCycle.hpp"
#include "iLogger.hpp"

class Logger : public iLogger, public iLifeCycle
{
    public:
        Logger();
        virtual ~Logger();
        ErrorCodes logError(std::string log){return ErrorCodes::NOT_OK;}
        ErrorCodes logInfo(std::string log){return ErrorCodes::NOT_OK;}
        ErrorCodes logWarrning(std::string log){return ErrorCodes::NOT_OK;}
        ErrorCodes logEvent( std::string prefix ,std::string log){return ErrorCodes::NOT_OK;}
        ErrorCodes registry(iLifeCycle *ptrToRegistry){return ErrorCodes::NOT_OK;}
        ErrorCodes run(){return ErrorCodes::NOT_OK;}
};

#endif // LOGGER_HPP
