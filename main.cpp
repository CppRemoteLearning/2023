#include <vector>

#include "Sensors/lightsensor.h"
#include "Devices/acunit.h"
#include "smarthomestatus.h"

#include "andreea_unique_ptr"

int main()
{
    
    smart_home::SmartHome smartHome;

        try
        {
            std::string filename = "../data_files/data0.xml";
            std::cout<<filename<<std::endl<<std::endl;
            smartHome.GetDataFromXml( filename.c_str());
            

            // const std::vector<smart_home::StatusObject*> sensors = room->GetSensors();
            // const std::vector<smart_home::StatusObject*> devices = room->GetDevices();

            // smart_home::SmartHomeStatus status;

            // std::thread sensorsThread([&sensors, &status]() {
            //     status.PrintStatus(sensors, "Sensors");
            //     });

            // std::thread devicesThread([&devices, &status]() {
            //     status.PrintStatus(devices, "Devices");
            //     });

            // sensorsThread.detach();
            // devicesThread.detach();

            smart_home::SmartHomeStatus status;
            
            std::thread statusThread([&smartHome, &status]() {
                    status.PrintSmartHomeStatus(smartHome);

                });

            statusThread.detach();
            
            std::this_thread::sleep_for(std::chrono::seconds(10));

            smart_home::Room *room = smartHome.GetRoom("LivingRoom").value();
            room->AddDevice(smart_home::MyUniquePtr<smart_home::Device>(new smart_home::Door("MainDoor", smart_home::DeviceStatus::kOn)));
            room->DeleteSensor("LightSensor");
            
            smart_home::Device* ac = room->GetDevice("Cooler").value();
            ac->SetName("AC UNIT");

            std::this_thread::sleep_for(std::chrono::seconds(30));

        
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout<<std::endl<<std::endl;
    
    return 0;
}