#include <iostream>

#include "Logger.hpp"
#include "Sensor.hpp"
#include "SensorMenager.hpp"
#include "LifeCycle.hpp"
#include "MainNetworkNode.hpp"



int main()
{
    Logger logger;
    LifeCycle lifeCycle(&logger);
    logger.passLifeCycle(&lifeCycle);
    logger.registry(&logger);
    SensorMenager sensorMenager(&lifeCycle,&logger);
    sensorMenager.registry(&sensorMenager);
    Sensor sensorFirst(&sensorMenager, &logger);
    Sensor sensorSecond(&sensorMenager, &logger);
    Sensor sensorThird(&sensorMenager, &logger);
    MainNetworkNode networkNode(50,&lifeCycle, &logger);
    networkNode.registry(&networkNode);

    lifeCycle.start();


    return 0;
}
