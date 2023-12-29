#ifndef DEVICESTATUS_H
#define DEVICESTATUS_H

namespace smart_home
{

enum class DeviceStatus{
    kOff = 0,
    kOn,
    kOutOfOrder,
};

} // namespace smart_home

#endif