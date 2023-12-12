#include "room.hpp"
#include "../../visitors/visitor.hpp"

void Room::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

void Room::AddDevice(const Device& device) {
  devices.push_back(device);
}

void Room::SetDevices(const std::vector<Device>& devices) {
  this->devices = devices;
}

std::vector<Device> Room::GetDevices() const {
  return devices;
}

void Room::AddSensor(const Sensor& sensor) {
  sensors.push_back(sensor);
}

void Room::SetSensors(const std::vector<Sensor>& sensors) {
  this->sensors = sensors;
}

std::vector<Sensor> Room::GetSensors() const {
  return sensors;
}