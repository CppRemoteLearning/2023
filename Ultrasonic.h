#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include "Sensor.h"
#include <string>

class Ultrasonic: public Sensor
{
    Ultrasonic(double temperature = 0, bool presence = false, double light = 0, float humidity = 0, char name[20] = (char*)"")
    :Sensor(temperature,presence,light,humidity,name)
    {

    }
    std::string typeName()
    {
        return "Ultrasonic";
    }

};

#endif