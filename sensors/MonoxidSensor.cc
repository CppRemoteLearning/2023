#include "MonoxidSensor.h"
#include <cstdlib>

namespace SmartHome {
    MonoxideSensor::MonoxideSensor(const std::string &name)
            : Sensor(name, MeasureUnit::UNKNOWN) {}

    void MonoxideSensor::generateRandomValue() {
        *value = std::rand() % 100;
    }

    double MonoxideSensor::getMonoxideLevel() const {
        return static_cast<double>(*value);
    }

    bool MonoxideSensor::isDangerousLevel() const {
        return getMonoxideLevel() > DANGER_LEVEL;
    }
}
