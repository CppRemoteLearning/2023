#ifndef XML_WRITE_VISITOR_H_
#define XML_WRITE_VISITOR_H_

#include "../visitor.hpp"

class XMLWriteVisitor : public Visitor {
 public:
  void Visit(const SmartHome *home) override;
  void Visit(const Room *room) override;
  void Visit(const Device *device) override;
  void Visit(const Sensor *sensor) override;
};


#endif  // XML_WRITE_VISITOR_H_