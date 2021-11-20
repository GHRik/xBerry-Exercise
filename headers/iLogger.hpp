#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include "utils.hpp"
#include <string>

class iLogger
{
    public:
        iLogger();
        virtual ~iLogger();
        virtual ErrorCodes logError(std::string log) = 0;
        virtual ErrorCodes logInfo(std::string log) = 0;
        virtual ErrorCodes logWarrning(std::string log) = 0;
        virtual ErrorCodes logEvent( std::string prefix ,std::string log) = 0;
};

#endif // ILOGGER_HPP
