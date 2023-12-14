#include "Device.h"

Device::Device(bool isWorking, float voltage, char name[20]):nummberID(this->value++)
{
    this->isWorking = isWorking;
    this->voltage =voltage;
    strcpy(this->name,name);
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