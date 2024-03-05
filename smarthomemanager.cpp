#include "smarthomemanager.h"

namespace smart_home
{

    SmartHomeManager::SmartHomeManager(SmartHome &smart_home): smartHome_{smart_home} {}

    void SmartHomeManager::Start()
    {
        try
        {
            std::string filename = "../data_files/data0.xml";
            std::cout<<filename<<std::endl<<std::endl;
            smartHome_.GetDataFromXml( filename.c_str());

            smart_home::SmartHomeStatus status;
            
            std::thread statusThread([this, &status]() {
                    status.PrintSmartHomeStatus(this->smartHome_);

                });

            std::thread doChangesThread([this]() {
                    this->DoChanges();

                });

            statusThread.join();
            doChangesThread.join();
        
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    void SmartHomeManager::DoChanges()
    {
        std::this_thread::sleep_for(std::chrono::seconds(10));

        smart_home::Room *room = smartHome_.GetRoom("LivingRoom").value();
        room->AddDevice(smart_home::MyUniquePtr<smart_home::Device>(new smart_home::Door("MainDoor", smart_home::DeviceStatus::kOn)));
        room->DeleteSensor("LightSensor");
            
        smart_home::Device* ac = room->GetDevice("Cooler").value();
        ac->SetName("AC UNIT");

        std::this_thread::sleep_for(std::chrono::seconds(30));
    }

} // namespace smart_home
