#include <iostream>
#include "../../include/services/temperature_service.h"
#include "../../include/sensors/temperature_sensor.h"
#include "../../include/devices/ac_unit.h"

namespace services {

void TemperatureService::AddSensor(sensors::Sensor* sensor) {
    sensors_.push_back(sensor);
}

void TemperatureService::AddDevice(devices::Device* device) {
    devices_.push_back(device);
}

void TemperatureService::Refresh() {
    for (sensors::Sensor* sensor : sensors_) {
        std::cout << "Refreshing..." << std::endl;
        sensors::TemperatureSensor* current_sensor = dynamic_cast<sensors::TemperatureSensor*>(sensor);
        std::vector<devices::Device*> devices = FindCorrespondingDevices(current_sensor);

        for (devices::Device* device : devices_) {
            if (typeid(*device) == typeid(devices::AcUnit)) {
                devices::AcUnit* ac_unit = dynamic_cast<devices::AcUnit*>(device);

                if (current_sensor->current_temperature() > 28) {
                    std::cout << "Turning AC unit on..." << std::endl;
                    ac_unit->set_is_on(true);
                    std::cout << "Setting fan speed to 50%." << std::endl;
                    ac_unit->set_fan_speed(100);
                    std::cout << "Setting desired temperature to 21 degrees." << std::endl;
                    ac_unit->set_desired_temperature(21);
                }
                else if (current_sensor->current_temperature() > 25) {
                    std::cout << "Turning AC unit on..." << std::endl;
                    ac_unit->set_is_on(true);
                    std::cout << "Setting fan speed to 50%." << std::endl;
                    ac_unit->set_fan_speed(50);
                    std::cout << "Setting desired temperature to 21 degrees." << std::endl;
                    ac_unit->set_desired_temperature(21);
                }
                else if (ac_unit->is_on()) {
                    std::cout << "Turning AC unit off..." << std::endl;
                    ac_unit->set_is_on(false);
                    std::cout << "Setting fan speed to 0%." << std::endl;
                    ac_unit->set_fan_speed(0);
                }
            }
        }
    }
}

std::vector<devices::Device*> TemperatureService::FindCorrespondingDevices(sensors::Sensor* sensor) {
    std::vector<devices::Device*> devices;

    for (devices::Device* device : devices_) {
        if (device->room() == sensor->room()) {
            devices.push_back(device);
        }
    }

    return devices;
}

} // namespace services

