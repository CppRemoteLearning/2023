#ifndef SMART_HOME_DEVICES_AC_UNIT_H_
#define SMART_HOME_DEVICES_AC_UNIT_H_

#include "../rooms/room.h"
#include "device.h"

namespace devices {

// Rule of Five

class AcUnit : public Device {
  public:
    AcUnit(rooms::Room* room): Device(room), is_on_(false), fan_speed_(0) {}

    rooms::Room* room() override {
        return room_;
    }

    inline bool is_on() {
        return is_on_;
    }

    inline void set_is_on(bool value) {
        is_on_ = value;
    }

    inline int fan_speed() {
        return fan_speed_;
    }

    inline void set_fan_speed(int value) {
        fan_speed_ = value;
    }

    inline float desired_temperature() {
        return desired_temperature_;
    }

    inline void set_desired_temperature(float value) {
        desired_temperature_ = value;
    }

    ~AcUnit() override = default;

  private:
    bool is_on_;
    int fan_speed_;
    float desired_temperature_;
};

} // namespace devices

#endif // SMART_HOME_DEVICES_AC_UNIT_H_