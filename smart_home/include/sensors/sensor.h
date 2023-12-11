#ifndef SMART_HOME_SENSORS_SENSOR_H_
#define SMART_HOME_SENSORS_SENSOR_H_

#include "../rooms/room.h"

namespace sensors {

// Rule of Five

class Sensor {
  public:
    virtual rooms::Room* room() = 0;

  protected:
    Sensor(rooms::Room* room): room_(room) {}

    virtual ~Sensor();

    rooms::Room* room_;
};

} // namespace sensors

#endif // SMART_HOME_SENSORS_SENSOR_H_