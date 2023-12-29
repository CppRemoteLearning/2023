#include "humiditysensor.h"

namespace smart_home
{
    
HumiditySensor::HumiditySensor(const std::string &name, float humidity) : Sensor(name), humidity_{humidity} {}

float HumiditySensor::GetHumidity()
{
    return humidity_;
}

void HumiditySensor::SetHumidity(float humidity)
{
    humidity_ = humidity;
}

bool HumiditySensor::ActionNeeded()
{
    if (humidity_ >= 600)
    {
        return true;
    }
    
    return false;
}
    
} // namespace smart_home
