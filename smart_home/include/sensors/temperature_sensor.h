#ifndef SMART_HOME_SENSORS_TEMPERATURE_SENSOR_H_
#define SMART_HOME_SENSORS_TEMPERATURE_SENSOR_H_

#include "sensor.h"
#include "../rooms/room.h"

namespace sensors {

// Rule of Five

class TemperatureSensor: public Sensor {
  public:
    TemperatureSensor(rooms::Room* room): Sensor(room) {}

    inline rooms::Room* room() override {
      return room_;
    }

    inline float current_temperature() {
        return current_temperature_;
    }

    inline void set_current_temperature(float value) {
        current_temperature_ = value;
    }

    ~TemperatureSensor() override = default;

  private:
    float current_temperature_;
};

} // namespace sensors

#endif // SMART_HOME_SENSORS_TEMPERATURE_SENSOR_H_