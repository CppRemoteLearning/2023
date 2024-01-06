#include "Device.h"
int Device::value = 0;
Device::Device(std::set<Sensor*> sensors, bool isWorking, float voltage,  char* name):nummberID(this->value++)
{
    for(auto x: sensors)
    {
        this->sensors.insert(x);
    }
    this->isWorking = isWorking;
    this->voltage =voltage;
    strcpy(this->name,name);
}

std::set<Sensor*> Device::getSensors()
{
    return this->sensors;
}
bool Device::getIsWorking()
{
    return this->isWorking;
}
float Device::getVoltage()
{
    return this->voltage;
}
char* Device::getName()
{
    return this->name;
}
int Device::getID()
{
    return this->nummberID;
}
void Device::addSensor(Sensor *s)
{
    this->sensors.insert(s);
}
