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
        virtual void run( iSensorMenager & sensorMenager, iLogger & logger) = 0;
    private:
        std::vector<iLifeCycle *> objectToLifeArray;
        size_t amountOfObject;

};

#endif // ILIFECYCLEMENAGER_HPP
