#ifndef VISITOR_H_
#define VISITOR_H_

class SmartHome;
class Room;
class Device;
class Sensor;

class Visitor {
 public:
  virtual void Visit(const SmartHome *) = 0;
  virtual void Visit(const Room *) = 0;
  virtual void Visit(const Device *) = 0;
  virtual void Visit(const Sensor *) = 0;
};

#endif // VISITOR_H_