#include <iostream>
#include "user/User.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    smart_home::User& user = smart_home::User::getInstance();
    smart_home::User::getUserHouse().writeDataToFile();
    std::cout << "Demo Control Devices\n";
    user.controlDevicesDemo();
    std::cout << std::endl;
    std::cout << "Demo Read Sensor Data From Room\n";
    smart_home::User::readSensorDataFromRoomDemo();
    std::cout << std::endl;
    std::cout << "Demo Get Devices Status\n";
    user.getDevicesStatus();

    return 0;
}
