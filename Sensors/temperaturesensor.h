#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include "sensor.h"

namespace smart_home
{

class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor(const std::string &name = "", float temperature = 0);

    float GetTemperature();
    void SetTemperature(float temperature);

    bool ActionNeeded();
private:
    float temperature_;
};
    
} // namespace smart_home

#endif