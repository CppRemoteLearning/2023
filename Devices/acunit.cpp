#include "acunit.h"

namespace smart_home
{

AcUnit::AcUnit(const std::string &name, DeviceStatus status): Device(name, status){}

} // namespace smart_home