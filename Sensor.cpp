#include "Sensor.h"
int Sensor::value = 0;
Sensor::Sensor(double temperature, bool presence, double light, float humidity, char *name) : nummberID(this->value++)
{
    this->temperature = temperature;
    this->presence = presence;
    this->light = light;
    this->humidity = humidity;
    strcpy(this->name, name);
}
Sensor::Sensor(const Sensor &ref) : nummberID(this->value++)
{
    if (this != &ref)
    {
        this->temperature = ref.getTemperature();
        this->presence = ref.getPresence();
        this->light = ref.getLight();
        this->humidity = ref.getHumidity();
        strcpy(this->name, ref.getName());
    }
}
Sensor &Sensor::operator=(const Sensor &ref) 
{
    if (this != &ref)
    {
        this->temperature = ref.getTemperature();
        this->presence = ref.getPresence();
        this->light = ref.getLight();
        this->humidity = ref.getHumidity();
        strcpy(this->name, ref.getName());
    }
    return *this;
}
Sensor::~Sensor(){}

Sensor &Sensor::operator=(const Sensor &&ref)
{
    if (this != &ref)
    {
        this->temperature = ref.getTemperature();
        this->presence = ref.getPresence();
        this->light = ref.getLight();
        this->humidity = ref.getHumidity();
        strcpy(this->name, ref.getName());
        
    }
    return *this;
}

const double Sensor::getTemperature() const
{
    return this->temperature;
}
const bool Sensor::getPresence() const
{
    return this->presence;
}
const double Sensor::getLight() const
{
    return this->light;
}
const float Sensor::getHumidity() const
{
    return this->humidity;
}
const char *Sensor::getName() const
{
    return this->name;
}
const int Sensor::getID() const
{
    return this->nummberID;
}