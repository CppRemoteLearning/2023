#include "temperaturesensor.h"

namespace smart_home
{

TemperatureSensor::TemperatureSensor(const std::string &name, float temperature) : Sensor(name), temperature_{temperature} {};

float TemperatureSensor::GetTemperature()
{
    return temperature_;
}

void TemperatureSensor::SetTemperature(float temperature)
{
    temperature_ = temperature;
} 

bool TemperatureSensor::ActionNeeded() 
{
    if (temperature_ >= 28)
    {
        return true;
    }
    return false;
}
    
} // namespace smart_home
