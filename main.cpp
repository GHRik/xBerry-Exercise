#include <iostream>

#include "Logger.hpp"
#include "Sensor.hpp"
#include "SensorMenager.hpp"
#include "LifeCycle.hpp"



int main()
{
    Logger logger;
    LifeCycle lifeCycle(&logger);
    logger.passLifeCycle(&lifeCycle);
    SensorMenager sensorMenager(&lifeCycle,&logger);
    sensorMenager.registry(&sensorMenager);
    Sensor sensorFirst(&sensorMenager, &logger);
    Sensor sensorSecond(&sensorMenager, &logger);
    Sensor sensorThird(&sensorMenager, &logger);

    lifeCycle.start();


    return 0;
}
