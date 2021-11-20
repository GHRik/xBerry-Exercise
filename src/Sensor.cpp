#include "../headers/Sensor.hpp"
Sensor::~Sensor()
{
    //dtor
}

Sensor::Sensor(iSensorMenager *sensorMenager) : sensorMenager(sensorMenager)
{
    sensorMenager->registrySensor(this);
}
