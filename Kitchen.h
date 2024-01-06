#ifndef KITCHEN_H
#define KITCHEN_H
#include "Room.h"
#include <string>

class Kitchen: public Room
{
    Kitchen(std::vector<Device *> devices = {}, float area = 0, char name[20] = (char*)"")
    :Room(devices,area,name)
    {

    }
    std::string typeName()
    {
        return "Kitchen";
    }

};

#endif