#include <vector>
#include <iostream>

#include "smart_home.h"

int main()
{
    SmartHome smartHome;
    try
    {
        smartHome.GetDataFromXml("../data.xml");
        
        //Device device("BathroomDoor", "Door", true);
        //Sensor presence("PresenceSensor", "Presence", 0);
        
        // Room *living = smartHome.GetRoom("LivingRoom");
        // living->AddSensor(presence);
        // living->AddDevice(device);

        //smartHome.GetRoom("LivingRoom")->DeleteSensor("PresenceSensor");

        Sensor *lightSensor = smartHome.GetRoom("LivingRoom")->GetSensor("LightSensor");
        if (lightSensor != nullptr)
        {
            float val = lightSensor->GetValue();
            std::cout<< val;
            lightSensor->SetValue(200);
            std::cout<<smartHome.GetRoom("LivingRoom")->GetSensor("LightSensor")->GetValue();
        }

        smartHome.AddToXml("../data.xml");

    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}