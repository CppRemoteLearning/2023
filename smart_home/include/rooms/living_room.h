#ifndef SMART_HOME_ROOMS_LIVING_ROOM_H_
#define SMART_HOME_ROOMS_LIVING_ROOM_H_
#include "room.h"

namespace rooms {

// Rule of Zero

class LivingRoom : public Room {
  public:
    LivingRoom(const float size): rooms::Room(size) {}
    
    inline float size() override {
        return size_;
    }
};

} // namespace rooms

#endif // SMART_HOME_ROOMS_LIVING_ROOM_H_