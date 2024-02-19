#ifndef SMART_HOME_SERVICES_SERVICE_H_
#define SMART_HOME_SERVICES_SERVICE_H_

#include <vector>
#include <unordered_map>
#include "memory"
#include "sensors/sensor.h"
#include "devices/device.h"

namespace services {

// Rule of Zero

class Service {
    public:
      std::vector<std::shared_ptr<sensors::Sensor>> GetSensors();

      std::vector<std::shared_ptr<devices::Device>> GetDevices();

      void AddSensor(std::shared_ptr<sensors::Sensor> sensor);

      void AddDevice(std::shared_ptr<devices::Device> device);

      virtual void Refresh() = 0;

    protected:
      std::unordered_map<std::shared_ptr<sensors::Sensor>, std::vector<std::shared_ptr<devices::Device>>> sensor_devices;

      void SetDevicesOnAuto();
};

} // namespace services

#endif // SMART_HOME_SERVICES_SERVICE_H_