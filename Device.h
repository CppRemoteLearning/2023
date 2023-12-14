#ifndef DEVICE_H
#define DEVICE_H

#include <cstring>

class Device
{
private:
bool isWorking;
float voltage;
char name[20];
const int nummberID;
static int value;

public:
Device(bool isWorking, float voltage, char name[20]);
bool getIsWorking();
float getVoltage();
char* getName();
int getID();
};

#endif