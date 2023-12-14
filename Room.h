#include <string>
#include <vector>
#include "Device.h"
#include "Sensor.h"

class Room
{
public:
    Room(std::string name);
    void addDevice(Device device);
    void addSensor(Sensor sensor);
    void getDevices();
    void getSensors();
    std::string getName();
    void setName(std::string name);

private:
    std::string name;
    std::vector<Device> devices;
    std::vector<Sensor> sensors;
};