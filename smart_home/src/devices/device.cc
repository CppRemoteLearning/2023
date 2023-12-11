#include "../../include/devices/device.h";

namespace devices {

Device::~Device() {
    delete room_;
}

} // namespace devices