#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "sensor.h"

namespace smart_home
{ 

class LightSensor : public Sensor
{
public:
    LightSensor(const std::string &name = "", float intensity = 0);
    float GetIntensity();
    void SetIntensity(float intensity);

    bool ActionNeeded();

private:
    float intensity_;
};

} // namespace smart_home

#endif