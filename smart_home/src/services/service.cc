#include <iostream>
#include "services/service.h"
#include "sensors/sensor.h"
#include "devices/device.h"

namespace services {

std::vector<std::shared_ptr<sensors::Sensor>> Service::GetSensors() {
    std::vector<std::shared_ptr<sensors::Sensor>> sensors;

    for (auto& sensor_device : sensor_devices) {
        sensors.push_back(sensor_device.first);
    }

    return sensors;
}

std::vector<std::shared_ptr<devices::Device>> Service::GetDevices() {
    std::vector<std::shared_ptr<devices::Device>> devices;

    for (auto& sensor_device : sensor_devices) {
        for (auto& device : sensor_device.second) {
            devices.push_back(device);
        }
    }

    return devices;
}

void Service::AddSensor(std::shared_ptr<sensors::Sensor> sensor) {
    if (!sensor) {
            return;
    }

    for (auto& sensor_device : sensor_devices) {
        if (sensor_device.first == sensor or sensor_device.first->GetRoom() == sensor->GetRoom()) {
            std::cout << "Sensor already exists in the same room." << std::endl;
            return;
        }
    }

    sensor_devices.insert({sensor, std::vector<std::shared_ptr<devices::Device>>()});
}

void Service::AddDevice(std::shared_ptr<devices::Device> device) {
    if (!device) {
        return;
    }

    for (auto& sensor_device : sensor_devices) {
        if (sensor_device.first->GetRoom() == device->GetRoom()) {
            sensor_device.second.push_back(device);
            return;
        }
    }
}

void Service::SetDevicesOnAuto() {
    for (auto& sensor_device : sensor_devices) {
        for (auto& device : sensor_device.second) {
            device->SetOnAuto(sensor_device.first);
        }
    }
}

} // namespace services

