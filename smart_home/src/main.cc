#include <iostream>
#include "../include/rooms/bedroom.h"
#include "../include/sensors/temperature_sensor.h"
#include "../include/services/temperature_service.h"
#include "../include/devices/ac_unit.h"

int main() {

    rooms::Bedroom* bedroom = new rooms::Bedroom(5.2f);
    
    std::cout << "Bedroom size: " << bedroom->size() << std::endl;

    sensors::TemperatureSensor* temperature_sensor = new sensors::TemperatureSensor(bedroom);

    std::cout << "Temperature sensor's room's size: " << temperature_sensor->room()->size() << std::endl;

    std::cout << "Current temperature before initialization: " << temperature_sensor->current_temperature() << std::endl;

    temperature_sensor->set_current_temperature(27);

    std::cout << "Current temperature after initialization: " << temperature_sensor->current_temperature() << std::endl;

    devices::AcUnit* ac_unit = new devices::AcUnit(bedroom);

    services::TemperatureService* temperature_service = new services::TemperatureService();

    temperature_service->AddSensor(temperature_sensor);
    temperature_service->AddDevice(ac_unit);

    std::cout << "Number of sensors of temperature service: " << temperature_service->sensors().size() << std::endl;
    std::cout << "Number of devices of temperature service: " << temperature_service->devices().size() << std::endl;

    temperature_service->Refresh();

    temperature_sensor->set_current_temperature(23);

    std::cout << "Current temperature after cooling: " << temperature_sensor->current_temperature() << std::endl;

    temperature_service->Refresh();

    delete temperature_service;
    // delete ac_unit;
    // delete temperature_sensor;
    delete bedroom;

    return 0;
}