#ifndef ISENSORMENAGER_HPP
#define ISENSORMENAGER_HPP

#include <vector>
#include <iostream>
#include "iSensor.hpp"
#include "iLifeCycle.hpp"

class iSensorMenager
{
    public:
        iSensorMenager();
        virtual ~iSensorMenager();
        virtual ErrorCodes registrySensor(iSensor * ptrToRegistry) = 0;

};

#endif // ISENSORMENAGER_HPP
