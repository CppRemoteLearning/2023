#ifndef NAGARROREMOTELEARNING_HOUSE_H
#define NAGARROREMOTELEARNING_HOUSE_H

#include <vector>
#include "Room.h"
#include "../devices/Device.h"

namespace SmartHome {
    class House {
    private:
        static const int MAX_ROOMS = 3;
        std::array<SmartHome::Room, MAX_ROOMS> rooms;

    public:
        House(int numRooms, int numSensorsPerRoom);
        void writeDataToFile();
    };
}

#endif