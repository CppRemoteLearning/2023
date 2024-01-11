#include <iostream>
#include "user/User.h"
#include "pointers/unique_ptr.h"

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

    std::cout << std::endl;
    std::cout << "Demo Unique Pointer\n";
    unique_ptr<int> ptr1(new int(10));
    unique_ptr<int> ptr2(new int(20));
    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;
    try {
        ptr1 = std::move(ptr2);
        std::cout << *ptr1 << std::endl;
        std::cout << *ptr2 << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
