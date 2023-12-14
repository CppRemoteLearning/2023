#include "SmartHomeManager.h"

int main()
{
    SmartHomeManager smartHomeManager;
    smartHomeManager.addRoom("Living Room");
    smartHomeManager.addDevice("Living Room", Device("Light"));
    smartHomeManager.addDevice("Living Room", Device("TV"));
    smartHomeManager.addSensor("Living Room", Sensor("Temperature"));
    smartHomeManager.addSensor("Living Room", Sensor("Humidity"));
    smartHomeManager.addRoom("Bedroom");
    smartHomeManager.addDevice("Bedroom", Device("Light"));
    smartHomeManager.addDevice("Bedroom", Device("TV"));
    smartHomeManager.addSensor("Bedroom", Sensor("Temperature"));
    smartHomeManager.addSensor("Bedroom", Sensor("Humidity"));
    smartHomeManager.saveToFile("smartHome.txt");
    smartHomeManager.loadFromFile("smartHome.txt");
    return 0;
}