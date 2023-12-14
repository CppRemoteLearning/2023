#include "Room.h"
#include <iostream>

Room::Room(std::string name)
{
    this->name = name;
}

void Room::addDevice(Device device)
{
    devices.push_back(device);
}

void Room::addSensor(Sensor sensor)
{
    sensors.push_back(sensor);
}

void Room::getDevices()
{
    for (auto device : devices)
    {
        std::cout << device.getType() << std::endl;
    }
}

void Room::getSensors()
{
    for (auto sensor : sensors)
    {
        std::cout << sensor.getType() << " : " << sensor.getData() << std::endl;
    }
}

std::string Room::getName()
{
    return name;
}

void Room::setName(std::string name)
{
    this->name = name;
}