#ifndef SMART_HOME_SERVICES_SERVICE_H_
#define SMART_HOME_SERVICES_SERVICE_H_

#include <vector>
#include "../sensors/sensor.h"
#include "../devices/device.h"

namespace services {

// Rule of Zero

class Service {
    public:
      virtual std::vector<sensors::Sensor*> sensors() = 0;
      
      virtual std::vector<devices::Device*> devices() = 0;

    protected:
      std::vector<sensors::Sensor*> sensors_;
      std::vector<devices::Device*> devices_;
};

}

#endif // SMART_HOME_SERVICES_SERVICE_H_