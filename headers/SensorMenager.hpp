#ifndef SENSORMENAGER_HPP
#define SENSORMENAGER_HPP

#include "iLifeCycle.hpp"
#include "iSensorMenager.hpp"
#include "Logger.hpp"
#include "LifeCycle.hpp"

class SensorMenager : iLifeCycle, iSensorMenager
{
    public:
        SensorMenager(LifeCycle *lifeCycle ,Logger *logger) : lifeCycle(lifeCycle), logger(logger){};
        virtual ~SensorMenager();

        ErrorCodes registry(){return ErrorCodes::NOT_OK;}
        ErrorCodes run(){return ErrorCodes::NOT_OK;}
    private:
        size_t numberOfSensors;
        std::vector<iSensor *> sensorsVect;
        LifeCycle *lifeCycle;
        Logger *logger;

};

#endif // SENSORMENAGER_HPP
