#include "Light.h"

namespace SmartHome {
    Light::Light() : Device(DeviceType::LIGHT), brightness(0) {}

    void Light::setBrightness(int brightness) {
        this->brightness = brightness;
    }

    int Light::getBrightness() const {
        return brightness;
    }

    void Light::displayStatuses() const {
        std::cout << "Light status: " << getDeviceStatus() << ", Brightness: " << brightness << std::endl;
    }
}