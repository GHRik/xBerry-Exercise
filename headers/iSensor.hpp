#ifndef ISENSOR_HPP
#define ISENSOR_HPP

#include "utils.hpp"

class iSensor
{
    public:
        iSensor();
        virtual ~iSensor();
        virtual ErrorCodes run() = 0;
        virtual ErrorCodes routine() = 0;
        Status actual_status;
};

#endif // ISENSOR_HPP
