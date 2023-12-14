#ifndef DEVICE_H
#define DEVICE_H

#include <cstring>
#include <set>
#include "Sensor.h"
class Device
{
private:
std::set<Sensor*> sensors;
bool isWorking;
float voltage;
char name[20];
const int nummberID;
static int value;

public:
Device(bool isWorking = false, float voltage = 0, char name[20] = "",std::set<Sensor*> sensors);
Device(const Device& dev);
~Device();
std::set<Sensor*> getSensors();
bool getIsWorking();
float getVoltage();
char* getName();
int getID();

void addSensor(Sensor *s);
};

#endif