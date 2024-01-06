#ifndef BATHROOM_H
#define BATHROOM_H
#include "Room.h"
#include <string>

class Bathroom: public Room
{
    Bathroom(std::vector<Device *> devices = {}, float area = 0, char name[20] = (char*)""):Room(devices,area,name)
    {

    }
    std::string typeName()
    {
        return "Bathroom";
    }

};

#endif