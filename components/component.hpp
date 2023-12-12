#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

class Visitor;

class Component {
 public:
  Component(const std::string& name) : name(name) {}

  void SetName(const std::string& name);
  std::string GetName() const;

  virtual ~Component() {}
  virtual void Accept(Visitor *visitor) = 0;

 private:
  std::string name{};
};

#endif // COMPONENT_H_
