#ifndef SMART_HOME_ROOMS_ROOM_H_
#define SMART_HOME_ROOMS_ROOM_H_

namespace rooms {

// Rule of Zero

class Room {
  public:
    virtual float size() = 0;

  protected:
    Room(const float size): size_(size) {}

    const float size_;
};

} // namespace rooms

#endif // SMART_HOME_ROOMS_ROOM_H_