#include "component.hpp"

void Component::SetName(const std::string& name) {
  this->name = name;
}

std::string Component::GetName() const {
  return name;
}