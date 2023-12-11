#include "../../include/sensors/sensor.h";

namespace sensors {

Sensor::~Sensor() {
    delete room_;
}

} // namespace devices