#include "device.hpp"
#include "../../visitors/visitor.hpp"

void Device::Accept(Visitor *visitor) {
  visitor->Visit(this);
}