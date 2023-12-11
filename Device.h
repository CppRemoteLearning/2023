#ifndef NAGARROREMOTELEARNING_DEVICE_H
#define NAGARROREMOTELEARNING_DEVICE_H

#include <iostream>
#include "enums.h"

class Device {
public:
    int status = 0;
    DeviceType type;

    explicit Device(DeviceType deviceType) : type(deviceType) {}

    void turnOn(){
        printf("Turning on %s\n", getDeviceType().c_str());
        status = 1;
    };
    void turnOff(){
        printf("Turning off %s\n", getDeviceType().c_str());
        status = 0;
    };
    std::string getDeviceType() const{
        switch (type) {
            case LIGHT:
                return "Light";
            case HEATER:
                return "Heater";
            default:
                return "ERROR";    
        }
    };

    std::string getDeviceStatus() const{
        if (status == 1)
            return "On";
        else if (status == 0)
            return "Off";
        else 
            return "ERROR";    
    };
    void displayStatus() const{
        std::cout << "Device Type: " << getDeviceType() << std::endl;
        std::cout << "Device Status: " << getDeviceStatus() << std::endl;
    };
};

#endif
