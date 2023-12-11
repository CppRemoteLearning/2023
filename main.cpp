#include <iostream>
#include <fstream>
#include <vector>
#include "smart_home.h"

int main()
{
    SmartHome smartHome;

    smartHome.GetDataFromXml("data.xml");
    //smartHome.Add(Sensor("PresenceSensor", "Presence"));
    Sensor lightSensor = smartHome.GetRoom("LivingRoom").GetSensor("LightSensor");
    std::cout<<lightSensor.GetName()<<std::endl<<lightSensor.GetType()<<std::endl<<lightSensor.GetValue();

    smartHome.AddToXml("data.xml");


    return 0;
}