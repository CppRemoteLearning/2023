#ifndef NAGARROREMOTELEARNING_STATUSPRINTER_H
#define NAGARROREMOTELEARNING_STATUSPRINTER_H

#include <vector>
#include "../devices/Device.h"
#include "../sensors/Sensor.h"

namespace SmartHome {
    class StatusPrinter {
    public:
        static void printDeviceStatus(std::vector<Device*> &devices);
        static void printSensorDataFromRoom(RoomType roomType);
    };
}

#endif
