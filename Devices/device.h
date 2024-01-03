#ifndef DEVICE_H
#define DEVICE_H

#include "devicestatus.h"
#include "../statusobject.h"

namespace smart_home {

class Device : public StatusObject
{
public:
    Device(const std::string &name = "", DeviceStatus status = DeviceStatus::kOff);

    std::string& GetName();
    void SetName(const std::string &name);

    DeviceStatus GetStatus();
    void SetStatus(DeviceStatus status);
    const std::string Status() = 0;
    
    virtual ~Device() = default;

private:
    std::string name_;
    DeviceStatus status_;
};

}
#endif