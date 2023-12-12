#ifndef XML_READ_VISITOR_H_
#define XML_READ_VISITOR_H_

#include "../visitor.hpp"

class XMLReadVisitor : public Visitor {
 public:
  void Visit(const SmartHome *) override;
  void Visit(const Room *) override;
  void Visit(const Device *) override;
  void Visit(const Sensor *) override;
};

#endif  // XML_READ_VISITOR_H_