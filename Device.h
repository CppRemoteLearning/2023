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
Device(std::set<Sensor*> sensors,bool isWorking, float voltage, char name[20]);
std::set<Sensor*> getSensors();
bool getIsWorking();
float getVoltage();
char* getName();
int getID();
};

#endif