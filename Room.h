#ifndef NAGARROREMOTELEARNING_ROOM_H
#define NAGARROREMOTELEARNING_ROOM_H

#include <vector>
#include "Sensor.h"

class Room {
private:
    RoomType type;
    std::vector<Sensor> sensors;

public:
    Room() : type(LIVING_ROOM) {
        sensors.reserve(0);
    }

    Room(int numSensors, RoomType roomType) : type(roomType) {
        sensors.reserve(numSensors);
        sensors.emplace_back("Temperature", CELSIUS);
        sensors.emplace_back("Humidity", PERCENT);
    }

    RoomType getType() const {
        return type;
    }

    const std::vector<Sensor>& getSensors() const {
        return sensors;
    }

    void generateRandomSensorValues() {
        for (Sensor& sensor : sensors) {
            sensor.generateRandomValue();
        }
    }
};

#endif
