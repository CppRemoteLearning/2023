#ifndef SENSOR_H
#define SENSOR_H

#include <cstring>
#include <string>
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
    virtual std::string typeName() = 0; 
    Sensor(double temperature = 0, bool presence = false, double light = 0, float humidity = 0, char name[20] = (char*)"");
    Sensor(const Sensor &ref);
    ~Sensor();
    Sensor& operator=(const Sensor &&ref);
    Sensor& operator=(const Sensor &ref);
    const double getTemperature() const;
    const bool getPresence() const;
    const double getLight() const;
    const float getHumidity() const;
    const char *getName() const;
    const int getID() const;
};


#endif