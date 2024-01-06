#ifndef PRESSURE_H
#define PRESSURE_H
#include "Sensor.h"
#include <string>

class Pressure: public Sensor
{
    Pressure(double temperature = 0, bool presence = false, double light = 0, float humidity = 0, char name[20] = (char*)"")
    :Sensor(temperature,presence,light,humidity,name)
    {

    }
    std::string typeName()
    {
        return "Pressure";
    }

};

#endif