#include "Room.h"

namespace SmartHome {
    Room::Room() : type(LIVING_ROOM) {}

    Room::Room(RoomType roomType) : type(roomType) {}

    RoomType Room::getType() const {
        return type;
    }

    void Room::addTemperatureSensor(const std::string& name) {
        sensors.emplace_back(std::make_unique<TemperatureSensor>(name));
    }

    void Room::addHumiditySensor(const std::string& name) {
        sensors.emplace_back(std::make_unique<HumiditySensor>(name));
    }

    void Room::addMonoxideSensor(const std::string& name) {
        sensors.emplace_back(std::make_unique<MonoxideSensor>(name));
    }

    void Room::generateRandomSensorValues() {
        for (auto& sensor : sensors) {
            sensor->generateRandomValue();
        }
    }

    const std::vector<std::unique_ptr<Sensor>>& Room::getSensors() const {
        return sensors;
    }
}
