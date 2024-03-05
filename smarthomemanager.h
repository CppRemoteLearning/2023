#ifndef SMARTHOMEMANAGER_H
#define SMARTHOMEMANAGER_H

#include <vector>

#include "smart_home.h"
#include "Sensors/lightsensor.h"
#include "Devices/acunit.h"
#include "smarthomestatus.h"

namespace smart_home
{

class SmartHomeManager
{
public:
    SmartHomeManager(SmartHome &smart_home);
    void Start();

private:
    void DoChanges();
    SmartHome& smartHome_;
};
    
} // namespace smart_home

#endif