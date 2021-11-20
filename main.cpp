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
    MainNetworkNode networkNode(50,&lifeCycle, &logger);
    SensorMenager sensorMenager(&lifeCycle,&logger);
    sensorMenager.registry(&sensorMenager);;
    Sensor sensorFirst(&sensorMenager, &logger, &networkNode);
    Sensor sensorSecond(&sensorMenager, &logger, &networkNode);
    Sensor sensorThird(&sensorMenager, &logger, &networkNode);
    networkNode.registry(&networkNode);

    lifeCycle.start();
    int a = -1;
    while(std::cin >> a)
    {
        if (a == 0)
        {
            break;
        }
    }
    lifeCycle.stop();

    return 0;
}
