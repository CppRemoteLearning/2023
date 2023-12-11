#ifndef SMART_HOME_SERVICES_TEMPERATURE_SERVICE_H_
#define SMART_HOME_SERVICES_TEMPERATURE_SERVICE_H_

#include "service.h"

namespace services {

// Rule of Zero

class TemperatureService : public Service {
  public:
    inline std::vector<sensors::Sensor*> sensors() override {
        return sensors_;
    }

    inline std::vector<devices::Device*> devices() override {
        return devices_;
    }

    void AddSensor(sensors::Sensor* sensor);

    void AddDevice(devices::Device* device);

    void Refresh();

    private:
      std::vector<devices::Device*> FindCorrespondingDevices(sensors::Sensor* sensor);
};

}

#endif // SMART_HOME_SERVICES_TEMPERATURE_SERVICE_H_