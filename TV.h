#ifndef TV_H
#define TV_H

#include "Device.h"
#include <string>

class TV : public Device
{
public:
    TV(std::set<Sensor *> sensors = {}, bool isWorking = false, float voltage = 0, char name[20] = (char*)"")
    :Device(sensors,isWorking,voltage,name)
    {
        
    }
    std::string typeName()
    {
        return "TV";
    }
};
#endif