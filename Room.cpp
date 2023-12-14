#include "Room.h"

Room::Room(std::vector<Device*> devices, float area,char name[20]):nummberID(this->value++)
{
    for(auto x:devices)
    {
        this->devices.push_back(x);
    }
    this->area = area;
    strcpy(this->name,name);
}
std::vector<Device*> Room::getDEvices()
{
    return this->devices;
}
float Room::getArea()
{
    return this->area;
}
char* Room::getName(){
    return this->name;
}
int Room::getID()
{
    return this->nummberID;
}