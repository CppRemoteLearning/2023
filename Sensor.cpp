#include "Sensor.h"

Sensor::Sensor(double temperature = 0, bool presence = false, double light=0,float humidity=0,char name[20]):nummberID(this->value++){
    this->temperature = temperature;
    this->presence = presence;
    this->light =light;
    this-> humidity = humidity;
    strcpy(this->name,name);
}
int Sensor::value = 0;
double Sensor::getTemperature()
{
    return this->temperature;
}
bool Sensor::getPresence()
{
    return this->presence;
}
double Sensor::getLight()
{
    return this->light;
}
float Sensor::getHumidity()
{
return this->humidity;
}
char* Sensor::getName()
{
    return this->name;
}
int Sensor::getID()
{
    return this->nummberID;
}