#ifndef HOME_H_
#define HOME_H_

#include <vector>

#include "../component.hpp"

#include "../room/room.hpp"

class SmartHome: public Component {
 public:
  SmartHome(const std::string& name) : Component(name) {}
  void Accept(Visitor *visitor) override;

  void AddRoom(const Room& room);
  void SetRooms(const std::vector<Room>& rooms);
  std::vector<Room> GetRooms() const;

 private:
  std::vector<Room> rooms{};
};

#endif  // HOME_H_
