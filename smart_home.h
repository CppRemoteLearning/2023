#ifndef SMART_HOME_H
#define SMART_HOME_H

#include <stdexcept>
#include <unordered_map>
#include "room.h"
#include "TinyXml/tinyxml2.h"

class SmartHome
{
public:
    void GetDataFromXml(const char* filename);
    void AddToXml(const std::string &filename);

    std::unordered_map<std::string, Room>* GetRooms();
    Room* GetRoom(const std::string &roomName);

private:
    std::unordered_map<std::string, Room> rooms_;
    
};

#endif