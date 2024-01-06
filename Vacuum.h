#ifndef VACUUM_H
#define VACUUM_H

#include "Device.h"
#include <string>

class Vacuum : public Device
{
public:
    Vacuum(std::set<Sensor *> sensors = {}, bool isWorking = false, float voltage = 0, char name[20] = (char*)"")
    :Device(sensors,isWorking,voltage,name)
    {
        
    }
    std::string typeName()
    {
        return "Vacuum";
    }
};
#endif