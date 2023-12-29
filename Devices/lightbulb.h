#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include "device.h"

namespace smart_home
{

class LightBulb : public Device
{
public:
    LightBulb(const std::string &name = "", DeviceStatus status = DeviceStatus::kOff);

private:

};

} // namespace smart_home

#endif