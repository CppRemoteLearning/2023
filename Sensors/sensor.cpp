#include "sensor.h"

namespace smart_home
{

std::string& Sensor::GetName()
{
    return name_;
}

void Sensor::SetName(const std::string &name)
{
    name_ = name;
}
    

Sensor::Sensor(const std::string &name): name_{name} {};

} // namespace smart_home
