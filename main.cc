#include <iostream>
#include "User.h"


int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    User user(3, 2);
    user.userHouse.writeDataToFile();
    std::cout << "Demo Control Devices\n";
    user.controlDevicesDemo();
    std::cout << std::endl;
    std::cout << "Demo Read Sensor Data From Room\n";
    user.readSensorDataFromRoomDemo();
    std::cout << std::endl;
    std::cout << "Demo Get Devices Status\n";
    user.getDevicesStatus();

    return 0;
}
