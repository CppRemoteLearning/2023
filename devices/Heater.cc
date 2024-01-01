#include "Heater.h"

namespace SmartHome {
    Heater::Heater() : Device(DeviceType::HEATER), temperature(0) {}

    void Heater::setTemperature(int temperature) {
        this->temperature = temperature;
    }

    int Heater::getTemperature() const {
        return temperature;
    }

    void Heater::displayStatuses() const {
        std::cout << "Heater status: " << getDeviceStatus() << ", Temperature: " << temperature << std::endl;
    }
}
