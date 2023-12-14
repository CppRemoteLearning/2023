#include "Sensor.h"

Sensor::Sensor(std::string type)
{
    this->type = type;
}

std::string Sensor::getType()
{
    return type;
}

void Sensor::setType(std::string type)
{
    this->type = type;
}
