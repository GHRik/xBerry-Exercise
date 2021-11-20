#ifndef SENSORMENAGER_HPP
#define SENSORMENAGER_HPP

#include "iLifeCycle.hpp"
#include "iSensorMenager.hpp"
#include "iLogger.hpp"
#include "iLifeCycle.hpp"

class SensorMenager : public iLifeCycle, public iSensorMenager
{
    public:
        SensorMenager(iLifeCycle *lifeCycle ,iLogger *logger) : lifeCycle(lifeCycle), logger(logger){};
        virtual ~SensorMenager();

        ErrorCodes registry(iLifeCycle *ptrToRegistry);
        ErrorCodes run();
        void stop();
        ErrorCodes registrySensor(iSensor * ptrToRegistry);

    private:
        std::vector<iSensor *> sensorsVect;
        iLifeCycle *lifeCycle;
        iLogger *logger;

};

#endif // SENSORMENAGER_HPP
