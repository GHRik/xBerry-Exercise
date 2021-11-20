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
    Sensor sensorFirst(&sensorMenager);
    Sensor sensorSecond(&sensorMenager);
    Sensor sensorThird(&sensorMenager);

    lifeCycle.run();

    return 0;
}
