#include "HumiditySensor.h"
#include <cstdlib>

namespace SmartHome {
    HumiditySensor::HumiditySensor(const std::string &name)
            : Sensor(name, MeasureUnit::PERCENT) {}

    void HumiditySensor::generateRandomValue() {
        *value = std::rand() % 100;
    }

    double HumiditySensor::getHumidityPercentage() const {
        return static_cast<double>(*value);
    }
}