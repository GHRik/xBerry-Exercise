#include <iostream>

#include "Logger.hpp"
#include "Sensor.hpp"
#include "SensorMenager.hpp"
#include "LifeCycle.hpp"

int main()
{
    Logger logger;
    LifeCycle lifeCycle(&logger);
    SensorMenager sensorMenager(&lifeCycle,&logger);
    sensorMenager.registry(&sensorMenager);
    Sensor sensorFirst(&sensorMenager);
    Sensor sensorSecond(&sensorMenager);
    Sensor sensorThird(&sensorMenager);

    lifeCycle.start();

    return 0;
}
