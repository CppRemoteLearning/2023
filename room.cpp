#include "room.h"

Room::Room(const std::string &name): name_{name} {}

void Room::AddSensor(Sensor &sensor)
{
    sensors_.insert({sensor.GetName(), sensor});
}

void Room::DeleteSensor(const std::string &name)
{
    sensors_.erase(sensors_.find(name));
}

Sensor Room::GetSensor(const std::string &name)
{
    return sensors_.find(name)->second;
}

void Room::AddDevice(Device &device)
{
    devices_.insert({device.GetName(), device});
}

void Room::DeleteDevice(const std::string &name)
{
    devices_.erase(devices_.find(name));
}

Device Room::GetDevice(const std::string &name)
{
    return devices_.find(name)->second;
}

std::string Room::GetName()
{
    return name_;
}

void Room::SetName(const std::string &name)
{
    name_ = name;
}

std::unordered_map<std::string, Sensor> Room::GetSensors()
{
    return sensors_;
}

std::unordered_map<std::string, Device> Room::GetDevices()
{
    return devices_;
}
