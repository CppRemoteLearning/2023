#include "presencesensor.h"

namespace smart_home
{

PresenceSensor::PresenceSensor(const std::string &name, bool is_presence) : Sensor(name), is_presence_{is_presence} {}

bool PresenceSensor::GetIsPresence()
{
    return is_presence_;
}

void PresenceSensor::SetIsPresence(bool is_presence)
{
    is_presence_ = is_presence;
}

bool PresenceSensor::ActionNeeded()
{
    return is_presence_;
}

} // namespace smart_home