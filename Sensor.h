#ifndef SENSOR_H
#define SENSOR_H

#include <cstring>

class Sensor
{
private:
double temperature;
bool presence;
double light;
float humidity;
char name[20];
const int nummberID;
static int value;
public:
Sensor(double temperature = 0, bool presence = false, double light=0,float humidity=0,char name[20]);
double getTemperature();
bool getPresence();
double getLight();
float getHumidity();
char* getName();
int getID();
};

#endif