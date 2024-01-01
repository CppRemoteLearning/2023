#ifndef NAGARROREMOTELEARNING_USER_H
#define NAGARROREMOTELEARNING_USER_H

#include <fstream>
#include <vector>
#include <ctime>
#include "../house/House.h"
#include "../devices/Device.h"

namespace SmartHome {
    class User {
    public:
        explicit User(int numRooms);
        void readSensorDataFromRoomDemo();
        void controlDevicesDemo();
        void getDevicesStatus();
        House getUserHouse() const;
    private:
        std::vector<Device *> devices;
        SmartHome::House userHouse;

    };
}

#endif