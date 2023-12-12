#include "./sensor.hpp"
#include "../../visitors/visitor.hpp"

void Sensor::Accept(Visitor *visitor) {
  visitor->Visit(this);
}