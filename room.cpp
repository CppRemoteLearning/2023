#include "room.h"

namespace smart_home
{

Room::Room(const std::string &name): name_{name} {}

// void Room::AddSensor(Sensor &sensor)
// {
//     sensors_.push_back(std::make_unique<Sensor>(sensor));
// }

void Room::DeleteSensor(const std::string &name)
{
    for (int i = 0; i < sensors_.size(); i++)
    {
        if (sensors_[i]->GetName() == name)
        {
            sensors_.erase(sensors_.begin() + i);
            return;
        }
        
    }
}

// std::shared_ptr<Sensor> Room::GetSensor(const std::string &name)
// {
//     for (auto &sensor : sensors_)
//     {
//         if (sensor->GetName() == name)
//         {
//             return std::make_shared<sensor>;
//         }
//     }

//     return nullptr;
// }

// void Room::AddDevice(Device &device)
// {
//     devices_.push_back(std::make_unique<Device>(device));
// }

void Room::DeleteDevice(const std::string &name)
{
    for (int i = 0; i < devices_.size(); i++)
    {
        if (devices_[i]->GetName() == name)
        {
            devices_.erase(devices_.begin() + i);
            return;
        }
    }
}

// std::shared_ptr<Device> Room::GetDevice(const std::string &name)
// {
//     for (auto &device : devices_)
//     {
//         if (device->GetName() == name)
//         {
//             return std::make_shared<Device>(device);
//         }
//     }
//     return nullptr;
// }

std::string& Room::GetName()
{
    return name_;
}

void Room::SetName(const std::string &name)
{
    name_ = name;
}

std::vector<std::unique_ptr<Sensor>>& Room::GetSensors()
{
    return sensors_;
}

std::vector<std::unique_ptr<Device>>& Room::GetDevices()
{
    return devices_;
}
} // namespace smart_home