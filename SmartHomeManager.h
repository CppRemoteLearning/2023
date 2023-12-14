#include <string>
#include <unordered_map>
#include "Room.h"

class SmartHomeManager
{
public:
    SmartHomeManager();
    void addRoom(std::string name);
    void addDevice(std::string roomName, Device device);
    void addSensor(std::string roomName, Sensor sensor);
    void saveToFile(std::string fileName);
    void loadFromFile(std::string fileName);

private:
    std::unordered_map<std::string, Room> rooms;
};