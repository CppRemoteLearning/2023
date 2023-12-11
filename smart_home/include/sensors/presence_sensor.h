#ifndef SMART_HOME_SENSORS_PRESENCE_SENSOR_H_
#define SMART_HOME_SENSORS_PRESENCE_SENSOR_H_

namespace sensors {
  
// Rule of Five

class PresenceSensor {
  public:
    inline bool is_any_presence() {
        return is_any_presence_;
    }

    inline void set_is_any_presence(bool value) {
        is_any_presence_ = value;
    }

    ~PresenceSensor() override = default;

  private:
    bool is_any_presence_;
};

} // namespace sensors

#endif SMART_HOME_SENSORS_PRESENCE_SENSOR_H_