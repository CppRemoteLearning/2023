#ifndef NAGARROREMOTELEARNING_USER_H
#define NAGARROREMOTELEARNING_USER_H

#include <fstream>
#include <vector>
#include <ctime>
#include "../house/House.h"
#include "../devices/Device.h"

namespace SmartHome {
    class User {
    private:
        std::vector<Device *> devices;
        SmartHome::House userHouse;

    public:
        User(int numRooms, int numSensorsPerRoom);
        ~User();
        User(const User& other);
        User& operator=(const User& other);
        User(User&& other);
        User& operator=(User&& other);
        void readSensorDataFromRoom(RoomType roomType);
        void readSensorDataFromRoomDemo();
        void controlDevicesDemo();
        void getDevicesStatus();
        House getUserHouse() const;
        void setUserHouse(const House &house);
    };
}

#endif