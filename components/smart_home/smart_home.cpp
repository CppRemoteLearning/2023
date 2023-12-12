#include "smart_home.hpp"
#include "../../visitors/visitor.hpp"

void SmartHome::Accept(Visitor *visitor) {
  visitor->Visit(this);
}

void SmartHome::AddRoom(const Room& room) {
  rooms.push_back(room);
}

void SmartHome::SetRooms(const std::vector<Room>& rooms) {
  this->rooms = rooms;
}

std::vector<Room> SmartHome::GetRooms() const {
  return rooms;
}