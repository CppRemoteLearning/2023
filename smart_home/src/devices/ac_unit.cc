#include <iostream>
#include "../../include/devices/ac_unit.h"

namespace devices {

void AcUnit::SetIsOn(bool value) {
    if (is_on != value) {
        std::cout << "Turning AC unit " << (value ? "on" : "off") << "..." << std::endl;
        is_on = value;
    }
    else {
        std::cout << "AC unit already turned " << (value ? "on" : "off") << "." << std::endl;
    }
}

void AcUnit::SetFanSpeed(unsigned char value) {
    if (fan_speed != value) {
        std::cout << "Setting fan speed to " << (int)value << "%." << std::endl;
        fan_speed = value;
    }
    else {
        std::cout << "Fan speed already set to " << (int)value << "%." << std::endl;
    }
}

void AcUnit::SetDesiredTemperature(float value) {
    if (desired_temperature != value) {
        std::cout << "Setting desired temperature to " << value << " degrees." << std::endl;
        desired_temperature = value;
    }
    else {
        std::cout << "Desired temperature already set to " << value << " degrees." << std::endl;
    }
}

void AcUnit::SetOnAuto(sensors::Sensor* sensor) {

    if (std::any_cast<float>(sensor->GetData()) > 28) {
        SetIsOn(true);
        SetFanSpeed((unsigned char)100);
        SetDesiredTemperature(21);
    }
    else if (std::any_cast<float>(sensor->GetData()) > 25) {
        SetIsOn(true);
        SetFanSpeed((unsigned char)50);
        SetDesiredTemperature(21);
    }
    else if (is_on) {
        SetIsOn(false);
        SetFanSpeed((unsigned char)0);
    }
}   

} // namespace devices