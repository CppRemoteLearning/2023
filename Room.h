#ifndef ROOM_H
#define ROOM_H

#include <cstring>
#include <vector>
#include "Device.h"
class Room
{
private:

std::vector<Device*> devices;
float area;
char name[20];
const int nummberID;
static int value;
public:
Room(float area = 0,char name[20] = "",std::vector<Device*> devices);
std::vector<Device*> getDEvices();
float getArea();
char* getName();
int getID();

void addDevice(Device *d);
};

#endif