#ifndef DEVICE_H_
#define DEVICE_H_

#include <string>

#include "../component.hpp"

class Device: public Component {
 public:
  Device(const std::string& name) : Component(name) {}
  void Accept(Visitor *visitor) override;
};

#endif  // DEVICE_H_
