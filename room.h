#ifndef ROOM_H
#define ROOM_H

#include <unordered_map>
#include "sensor.h"
#include "device.h"

class Room
{
public:
    Room(const std::string &name = "");

    void AddSensor(Sensor &sensor);
    void DeleteSensor(const std::string &name);
    Sensor GetSensor(const std::string &name);

    void AddDevice(Device &device);
    void DeleteDevice(const std::string &name);
    Device GetDevice(const std::string &name);

    std::string GetName();
    void SetName(const std::string &name);

    std::unordered_map<std::string, Sensor> GetSensors();
    std::unordered_map<std::string, Device> GetDevices();


private:
    std::string name_;
    std::unordered_map<std::string, Sensor> sensors_;
    std::unordered_map<std::string, Device> devices_;
    // I choosed unordered_map because I have instant acces to elements, for example:
    // If I have to look for a humidity sensor, I look for the element with that key
    // In the others containers like list or vector I should iterate over it until I find my sensor with that name  
};

#endif