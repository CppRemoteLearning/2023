#ifndef ACUNIT_H
#define ACUNIT_H

#include "device.h"

namespace smart_home
{

class AcUnit : public Device
{
public:
    AcUnit(const std::string &name = "", DeviceStatus status = DeviceStatus::kOff);

private:

};
    
} // namespace smart_home

#endif