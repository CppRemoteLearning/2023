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
        ~User();
        User(const User& other);
        User(User&& other) noexcept;
        User& operator=(const User& other);
        User& operator=(User&& other) noexcept;

        void readSensorDataFromRoomDemo();
        void controlDevicesDemo();
        void getDevicesStatus();
        House getUserHouse() const;
    private:
        std::vector<Device*> devices;
        SmartHome::House userHouse;
        void copyDevices(const User& other);
        void moveDevices(User& other);
    
    };
}

#endif