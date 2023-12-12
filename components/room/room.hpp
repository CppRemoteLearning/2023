#ifndef ROOM_H_
#define ROOM_H_

#include <vector>

#include "../component.hpp"

#include "../sensor/sensor.hpp"
#include "../device/device.hpp"

class Room: public Component {
 public:
  Room(const std::string& name) : Component(name) {}
  void Accept(Visitor *visitor) override;

  void AddSensor(const Sensor& sensor);
  void SetSensors(const std::vector<Sensor>& sensors);
  std::vector<Sensor> GetSensors() const;

  void AddDevice(const Device& device);
  void SetDevices(const std::vector<Device>& devices);
  std::vector<Device> GetDevices() const;

 private:
  std::vector<Sensor> sensors{};
  std::vector<Device> devices{};
};

#endif  // ROOM_H_