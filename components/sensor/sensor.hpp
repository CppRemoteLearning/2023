#ifndef SENSOR_H_
#define SENSOR_H_

#include <string>

#include "../component.hpp"

class Sensor: public Component {
 public:
  Sensor(const std::string& name) : Component(name) {}
  void Accept(Visitor *visitor) override;
};

#endif  // SENSOR_H_