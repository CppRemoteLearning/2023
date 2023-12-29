#ifndef DEVICE_H
#define DEVICE_H

#include <string>

#include "devicestatus.h"

namespace smart_home {

class Device
{
public:
    Device(const std::string &name = "", DeviceStatus status = DeviceStatus::kOff);

    std::string& GetName();
    void SetName(const std::string &name);

    DeviceStatus GetStatus();
    void SetStatus(DeviceStatus status);

    virtual ~Device() = default;

private:
    std::string name_;
    DeviceStatus status_;
};

}
#endif