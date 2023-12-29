#ifndef PRESENCESENSOR_H
#define PRESENCESENSOR_H

#include "sensor.h"

namespace smart_home
{

class PresenceSensor : public Sensor
{
public:
    PresenceSensor(const std::string &name = "", bool is_presence = "");

    bool GetIsPresence(); 
    void SetIsPresence(bool is_presence);

    bool ActionNeeded();
    
private:
    bool is_presence_;
    
};
    
} // namespace smart_home

#endif