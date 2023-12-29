#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "sensor.h"

namespace smart_home
{

class HumiditySensor: public Sensor
{
public:
    HumiditySensor(const std::string &name = "", float humidity = 0);
    float GetHumidity();
    void SetHumidity(float humidity);

    bool ActionNeeded();

private:
    float humidity_;

};
    
} // namespace smart_home

#endif