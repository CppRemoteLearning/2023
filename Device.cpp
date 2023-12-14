#include "Device.h"

Device::Device(std::string type)
{
    this->type = type;
}

std::string Device::getType()
{
    return type;
}

void Device::setType(std::string type)
{
    this->type = type;
}