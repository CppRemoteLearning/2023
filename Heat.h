#ifndef HEAT_H
#define HEAT_H
#include "Sensor.h"
#include <string>

class Heat: public Sensor
{
public:
    Heat(double temperature = 0, bool presence = false, double light = 0, float humidity = 0, char name[20] = (char*)"")
    :Sensor(temperature,presence,light,humidity,name)
    {

    }
    std::string typeName()
    {
        return "Heat";
    }

};

#endif
