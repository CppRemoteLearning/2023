#ifndef SMART_HOME_ROOMS_BEDROOM_H_
#define SMART_HOME_ROOMS_BEDROOM_H_

#include "room.h"

namespace rooms {

// Rule of Zero

class Bedroom : public Room {
  public:
    Bedroom(const float size): rooms::Room(size) {}
    
    inline float size() override {
        return size_;
    }
};

} // namespace rooms

#endif // SMART_HOME_ROOMS_BEDROOM_H_