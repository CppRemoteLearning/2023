#ifndef SMART_HOME_DEVICES_DEVICE_H_
#define SMART_HOME_DEVICES_DEVICE_H_

#include "../rooms/room.h"

namespace devices {

// Rule of Five

class Device {
  public:
    virtual rooms::Room* room() = 0;

  protected:
    Device(rooms::Room* room): room_(room) {}

    virtual ~Device();

    rooms::Room* room_;
};

} // namespace devices

#endif // SMART_HOME_DEVICES_DEVICE_H_