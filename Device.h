#ifndef DEVICE_H
#define DEVICE_H

#include <cstring>
#include <set>
#include "Sensor.h"
#include <string>

class Device
{
private:
    std::set<Sensor *> sensors;
    bool isWorking;
    float voltage;
    char name[20];
    const int nummberID;
    static int value;
public:
    virtual std::string typeName() = 0;    
    Device(std::set<Sensor *> sensors = {}, bool isWorking = false, float voltage = 0, char name[20] = (char*)"");
    Device(const Device &dev);
    std::set<Sensor *> getSensors();
    bool getIsWorking();
    float getVoltage();
    char *getName();
    int getID();
    void addSensor(Sensor *s);
    
};

#endif