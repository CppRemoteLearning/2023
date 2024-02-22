#include <vector>

#include "Sensors/lightsensor.h"
#include "Devices/acunit.h"
#include "smarthomestatus.h"

#include "uniqueptr.h"
#include "andreea_unique_ptr"

int main()
{
    smart_home::SmartHome smartHome;
    try
    {
        smartHome.GetDataFromXml("../data.xml");
        
        smart_home::MyUniquePtr<smart_home::Room> room = smartHome.GetRoom("LivingRoom").value();
        smart_home::SmartHomeStatus::PrintStatus(std::move(room->GetSensors()));
        smart_home::SmartHomeStatus::PrintStatus(std::move(room->GetDevices()));
        

        //smart_home::Device device("BathroomDoor", "Door", true);
        //smart_home::Sensor presence("PresenceSensor", "Presence", 0);
        
        // smart_home::Room *living = smartHome.GetRoom("LivingRoom");
        // living->AddSensor(presence);
        // living->AddDevice(device);

        //smartHome.GetRoom("LivingRoom")->DeleteSensor("PresenceSensor");

        // smart_home::Sensor *lightSensor = smartHome.GetRoom("LivingRoom")->GetSensor("LightSensor");
        // if (lightSensor != nullptr)
        // {
        //     float val = lightSensor->GetValue();
        //     std::cout<< val;
        //     lightSensor->SetValue(200);
        //     std::cout<<smartHome.GetRoom("LivingRoom")->GetSensor("LightSensor")->GetValue();
        // }

        // smartHome.AddToXml("../data.xml");

        // smart_home::MyUniquePtr<smart_home::Sensor> light(new smart_home::LightSensor("Light", 600));
        // smart_home::MyUniquePtr<smart_home::Device> ac(new smart_home::AcUnit("ac"));

        // smart_home::Room room("Room");

        // room.AddDevice(std::move(ac));
        // room.AddSensor(std::move(light));

        // room.GetDevices();
        // room.GetSensors();

        // std::cout<<room.GetName();

        // room.DeleteDevice("ac");
        // room.DeleteSensor("Light");

        // std::vector<smart_home::StatusObject*> obj;

        // obj.push_back(&light);
        // obj.push_back(&ac);

        // smart_home::SmartHomeStatus::PrintSensorsStatus(obj);

    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}