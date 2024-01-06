#ifndef BEDROOM_H
#define BEDROOM_H
#include "Room.h"
#include <string>

class Bedroom: public Room
{
    Bedroom(std::vector<Device *> devices = {}, float area = 0, char name[20] = (char*)"")
    :Room(devices,area,name)
    {

    }
    std::string typeName()
    {
        return "Bedroom";
    }

};

#endif