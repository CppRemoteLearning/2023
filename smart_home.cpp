#include "smart_home.h"

namespace smart_home
{

// void SmartHome::GetDataFromXml(const char* filename) {
//     tinyxml2::XMLDocument xmlDoc;
//     tinyxml2::XMLError err = xmlDoc.LoadFile(filename);
//     if (err != tinyxml2::XML_SUCCESS) {
//         throw std::invalid_argument("Error loading file!");
//     }

//     MyUniquePtr<tinyxml2::XMLNode, StandardDeleter<>> pRoot(xmlDoc.RootElement());
//     if (pRoot->Value() == nullptr) {
//         throw std::invalid_argument("Invalid XML format!");
//     }

//     MyUniquePtr<tinyxml2::XMLElement> pRoomElement(pRoot->FirstChildElement());
    
//     if (pRoomElement->Value() == nullptr) {
//         throw std::invalid_argument("Room element is null!");
//     }

//     for (pRoomElement; pRoomElement->Value() != nullptr; pRoomElement.reset(pRoomElement->NextSiblingElement("Room"))) {
//         MyUniquePtr<Room> room;
        
//         if(const char* roomName = pRoomElement->Attribute("name")){
//             room->SetName(roomName);
//         }
//         else
//         {
//             throw std::invalid_argument("Room name wasn't found!");
//         }

//         for (MyUniquePtr<tinyxml2::XMLElement> sensorElement(pRoomElement->FirstChildElement("LightSensor")); sensorElement->Value() != nullptr; sensorElement.reset(sensorElement->NextSiblingElement("Sensor"))) {
//             //room->AddSensor(std::move(MyUniquePtr<Sensor>(LightSensor(std::move(sensorElement)))));
//         }

//         // for (tinyxml2::XMLElement* deviceElement = pRoomElement->FirstChildElement("Device"); deviceElement != nullptr; deviceElement = deviceElement->NextSiblingElement("Device")) {
//         //     room.AddDevice(getDeviceFromXml(deviceElement));
//         // }

//         rooms_.push_back(std::move(room));
//     }
// }


// void SmartHome::AddToXml(const std::string &filename)
// {
//     tinyxml2::XMLDocument xmlDoc;
//         tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("SmartHome");
//         xmlDoc.InsertFirstChild(pRoot);

//         for (auto& room : rooms_) {
//             tinyxml2::XMLElement* pRoomElement = xmlDoc.NewElement("Room");
//             pRoomElement->SetAttribute("name", room.GetName().c_str());

//             for (auto& sensor : room.GetSensors()) {
//                 tinyxml2::XMLElement* sensorElement = xmlDoc.NewElement("Sensor");
//                 sensorElement->SetAttribute("name", sensor.GetName().c_str());
//                 sensorElement->SetAttribute("type", sensor.GetType().c_str());
//                 sensorElement->SetAttribute("value", sensor.GetValue());
//                 pRoomElement->InsertEndChild(sensorElement);
//             }

//             for (auto& device : room.GetDevices()) {
//                 tinyxml2::XMLElement* deviceElement = xmlDoc.NewElement("Device");
//                 deviceElement->SetAttribute("name", device.GetName().c_str());
//                 deviceElement->SetAttribute("type", device.GetType().c_str());
//                 deviceElement->SetAttribute("status", device.GetStatus());
//                 pRoomElement->InsertEndChild(deviceElement);
//             }

//             pRoot->InsertEndChild(pRoomElement);
//         }

//         tinyxml2::XMLError eResult = xmlDoc.SaveFile(filename.c_str());
//         if (eResult != tinyxml2::XML_SUCCESS) {
//             throw std::invalid_argument("Error saving to file!");
//         }
// }

std::vector<MyUniquePtr<Room>>& SmartHome::GetRooms()
{
    return rooms_;
}

std::optional<MyUniquePtr<Room>> SmartHome::GetRoom(const std::string &roomName)
{
    for (auto &room : rooms_)
    {
        if (room->GetName() == roomName)
        {
            return std::move(room);
        }
    }
    return std::nullopt;
}

// Sensor& SmartHome::getSensorFromXml(tinyxml2::XMLElement* sensorElement)
// {
//     const char* sensorName = sensorElement->Attribute("name");
//     const char* sensorType = sensorElement->Attribute("type");
//     float sensorValue;
//     sensorElement->QueryFloatAttribute("value", &sensorValue);
//     Sensor* sensor = new Sensor(sensorName, sensorType, sensorValue);
    
//     return *sensor;
// }

// Device& SmartHome::getDeviceFromXml(tinyxml2::XMLElement* deviceElement)
// {
//     const char* deviceName = deviceElement->Attribute("name");
//     const char* deviceType = deviceElement->Attribute("type");
//     bool deviceStatus;
//     deviceElement->QueryBoolAttribute("status", &deviceStatus);
//     Device *device = new Device(deviceName, deviceType, deviceStatus);
    
//     return *device;
// }

} // namespace smart_home
