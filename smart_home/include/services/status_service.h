#ifndef SMART_HOME_SERVICES_STATUS_SERVICE_H_
#define SMART_HOME_SERVICES_STATUS_SERVICE_H_

#include <vector>
#include "sensors/sensor.h"
#include "devices/device.h"

namespace services {

// Rule of Zero

class StatusService {
    public:
      std::vector<std::shared_ptr<sensors::Sensor>> GetSensors() {
        return sensors;
      }

      std::vector<std::shared_ptr<devices::Device>> GetDevices() {
        return devices;
      }

      void AddSensor(std::shared_ptr<sensors::Sensor> sensor);

      void AddDevice(std::shared_ptr<devices::Device> device);

      void PrintStatus();

    private:
      std::vector<std::shared_ptr<sensors::Sensor>> sensors;
      std::vector<std::shared_ptr<devices::Device>> devices;
};

} // namespace services

#endif // SMART_HOME_SERVICES_STATUS_SERVICE_H_