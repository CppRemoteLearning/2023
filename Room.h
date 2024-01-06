#ifndef ROOM_H
#define ROOM_H

#include <cstring>
#include <vector>
#include "Device.h"
#include <string>
class Room
{
private:
    std::vector<Device *> devices;
    float area;
    char name[20];
    const int nummberID;
    static int value;

public:
    virtual std::string typeName() = 0; 
    Room(std::vector<Device *> devices = {}, float area = 0, char name[20] = (char*)"");
    std::vector<Device *> getDEvices();
    float getArea();
    char *getName();
    int getID();

    void addDevice(Device *d);
};

#endif