#include "SmartHomeManager.h"
#include <iostream>
#include "FileRepo.h"

SmartHomeManager::SmartHomeManager()
{
}

void SmartHomeManager::addRoom(std::string name)
{
    Room room(name);
    rooms.insert(std::pair<std::string, Room>(name, room));
}

void SmartHomeManager::addDevice(std::string roomName, Device device)
{
    rooms[roomName].addDevice(device);
}

void SmartHomeManager::addSensor(std::string roomName, Sensor sensor)
{
    rooms[roomName].addSensor(sensor);
}

void SmartHomeManager::saveToFile(std::string fileName)
{
    FileRepo fileRepo;
    fileRepo.saveToFile(fileName, rooms);
}

void SmartHomeManager::loadFromFile(std::string fileName)
{
    FileRepo fileRepo;
    fileRepo.loadFromFile(fileName, rooms);
}
