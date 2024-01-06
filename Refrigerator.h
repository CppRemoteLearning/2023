#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include "Device.h"
#include <string>

class Refrigerator : public Device
{
public:
    Refrigerator(std::set<Sensor *> sensors = {}, bool isWorking = false, float voltage = 0, char name[20] = (char*)"")
    :Device(sensors,isWorking,voltage,name)
    {
        
    }
    std::string typeName()
    {
        return "Refrigerator";
    }
};
#endif