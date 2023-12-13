#ifndef NAGARROREMOTELEARNING_ROOM_H
#define NAGARROREMOTELEARNING_ROOM_H

#include <vector>
#include "../devices/Sensor.h"

namespace SmartHome {
    class Room {
    private:
        RoomType type;
        std::vector<Sensor> sensors;

    public:
        Room();

        Room(int numSensors, RoomType roomType);

        RoomType getType() const;

        const std::vector<Sensor> &getSensors() const;

        void generateRandomSensorValues();
    };
}

#endif