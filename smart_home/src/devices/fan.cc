#include <iostream>
#include "../../include/devices/fan.h"

namespace devices {

void Fan::SetIsOn(bool value) {
    if (is_on != value) {
        std::cout << "Turning fan " << (value ? "on" : "off") << "..." << std::endl;
        is_on = value;
    }
    else {
        std::cout << "Fan already turned " << (value ? "on" : "off") << "." << std::endl;
    }
}

void Fan::SetSpeed(unsigned char value) {
    if (speed != value) {
        std::cout << "Setting speed to " << (int)value << "%." << std::endl;
        speed = value;
    }
    else {
        std::cout << "Speed already set to " << (int)value << "%." << std::endl;
    }
}

void Fan::SetIsRotating(bool value) {
    if (is_rotating != value) {
        std::cout << "Setting rotation to " << (value ? "on" : "off") << "." << std::endl;
        is_rotating = value;
    }
    else {
        std::cout << "Rotation already set to " << (value ? "on" : "off") << "." << std::endl;
    }
}

void Fan::SetOnAuto(sensors::Sensor* sensor) {

    if (std::any_cast<float>(sensor->GetData()) > 28) {
        SetIsOn(true);
        SetSpeed((unsigned char)100);
        SetIsRotating(true);
    }
    else if (std::any_cast<float>(sensor->GetData()) > 25) {
        SetIsOn(true);
        SetSpeed((unsigned char)50);
        SetIsRotating(false);
    }
    else if (is_on) {
        SetIsOn(false);
        SetSpeed((unsigned char)0);
        SetIsRotating(false);
    }
}   

} // namespace devices