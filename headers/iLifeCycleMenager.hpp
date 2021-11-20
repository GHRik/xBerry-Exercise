#ifndef ILIFECYCLEMENAGER_HPP
#define ILIFECYCLEMENAGER_HPP

#include "iSensorMenager.hpp"
#include "iLogger.hpp"
#include "iLifeCycle.hpp"
#include <vector>

class iLifeCycleMenager
{
    public:
        iLifeCycleMenager();
        virtual ~iLifeCycleMenager();
        //iSensorMenager & sensorMenager, iLogger & logger
        virtual void run( ) = 0;

};

#endif // ILIFECYCLEMENAGER_HPP
