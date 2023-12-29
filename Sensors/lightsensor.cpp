#include "lightsensor.h"

namespace smart_home
{

LightSensor::LightSensor(const std::string &name, float intensity): Sensor(name), intensity_{intensity} {}

float LightSensor::GetIntensity()
{
    return intensity_;
}

void LightSensor::SetIntensity(float intensity)
{
    intensity_ = intensity;
}

bool LightSensor::ActionNeeded()
{
    if (intensity_ <= 200)
    {
        return true;
    }
    return false;
}


    
} // namespace smart_home