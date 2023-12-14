#include "Room.h"

Room::Room(float area = 0,char name[20] = "",std::vector<Device*> devices):nummberID(this->value++)
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
void Room::addDevice(Device *d)
{
    this->devices.push_back(d);
}