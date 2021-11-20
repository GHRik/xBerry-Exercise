#ifndef ISENSORMENAGER_HPP
#define ISENSORMENAGER_HPP

#include <vector>
#include <iostream>
#include "iSensor.hpp"

class iSensorMenager
{
    public:
        iSensorMenager();
        virtual ~iSensorMenager();
        virtual ErrorCodes registry() = 0;
    private:
        size_t numberOfSensors;
        std::vector<iSensor *> sensorsVect;

};

#endif // ISENSORMENAGER_HPP
