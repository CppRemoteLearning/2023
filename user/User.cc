#include "User.h"
#include "../utils/StatusPrinter.h"
#include "../devices/AirConditioner.h"
#include "../devices/Heater.h"
#include "../devices/Light.h"

namespace SmartHome {
    User::User(int numRooms) : userHouse(numRooms) {
        devices.push_back(new Light());
        devices.push_back(new Heater());
        devices.push_back(new AirConditioner());
    }

    void User::controlDevicesDemo() {
        while (true) {
            std::cout << "Enter a device type (0 = Light, 1 = Heater, 2 = AirConditioner): ";
            int deviceType;
            std::cin >> deviceType;

            switch(deviceType) {
                case 0: {
                    Light* light = dynamic_cast<Light*>(devices[deviceType]);
                    if (light) {
                        std::cout << "Enter brightness level (0-100): ";
                        int brightness;
                        std::cin >> brightness;
                        light->setBrightness(brightness);
                    }
                    break;
                }
                case 1: {
                    Heater* heater = dynamic_cast<Heater*>(devices[deviceType]);
                    if (heater) {
                        std::cout << "Enter temperature: ";
                        int temperature;
                        std::cin >> temperature;
                        heater->setTemperature(temperature);
                    }
                    break;
                }
                case 2: {
                    AirConditioner* ac = dynamic_cast<AirConditioner*>(devices[deviceType]);
                    if (ac) {
                        std::cout << "Enter temperature: ";
                        int temperature;
                        std::cin >> temperature;
                        ac->setTemperature(temperature);
                        std::cout << "Enter mode (1 COOLING, 2 HEATING): ";
                        int mode;
                        std::cin >> mode;
                        if (mode == 1)
                            ac->setMode(ACMode::COOLING);
                        if (mode == 2)
                            ac->setMode(ACMode::HEATING);
                        if (mode != 1 && mode != 2)
                            std::cout << "Invalid mode." << std::endl;
                    }
                    break;
                }
                default:
                    std::cout << "Invalid device type." << std::endl;
                    continue;
            }

            std::cout << "Device settings updated." << std::endl;
            break;
        }
    }

    void User::getDevicesStatus() {
        SmartHome::StatusPrinter::printDeviceStatus(devices);
    }

    void User::readSensorDataFromRoomDemo() {
        while (true) {
            std::cout << "Enter a room type (0 = Living Room, 1 = Bedroom, 2 = Kitchen): ";
            int roomType;
            std::cin >> roomType;
            if (roomType == 0 || roomType == 1 || roomType == 2) {
                StatusPrinter::printSensorDataFromRoom(static_cast<RoomType>(roomType));
                break;
            } else {
                std::cout << "Invalid room type." << std::endl;
            }
        }
    }

    House User::getUserHouse() const {
        return House(3);
    }
}