#include "smart_home.h"

void SmartHome::GetDataFromXml(const char* filename) {
    tinyxml2::XMLDocument xmlDoc;
    tinyxml2::XMLError err = xmlDoc.LoadFile(filename);
    if (err != tinyxml2::XML_SUCCESS) {
        throw std::invalid_argument("Error loading file!");
    }

    tinyxml2::XMLNode* pRoot = xmlDoc.RootElement();
    if (pRoot == nullptr) {
        throw std::invalid_argument("Invalid XML format!");
    }

    tinyxml2::XMLElement* pRoomElement = pRoot->FirstChildElement();
    
    if (pRoomElement == nullptr) {
        throw std::invalid_argument("Room element is null!");
    }

    for (pRoomElement; pRoomElement != nullptr; pRoomElement = pRoomElement->NextSiblingElement("Room")) {
        const char* roomName = pRoomElement->Attribute("name");

        Room room(roomName);

        for (tinyxml2::XMLElement* sensorElement = pRoomElement->FirstChildElement("Sensor"); sensorElement != nullptr; sensorElement = sensorElement->NextSiblingElement("Sensor")) {
            const char* sensorName = sensorElement->Attribute("name");
            const char* sensorType = sensorElement->Attribute("type");
            float sensorValue;
            sensorElement->QueryFloatAttribute("value", &sensorValue);
            Sensor sensor(sensorName, sensorType, sensorValue);
            room.AddSensor(sensor);
        }

        for (tinyxml2::XMLElement* deviceElement = pRoomElement->FirstChildElement("Device"); deviceElement != nullptr; deviceElement = deviceElement->NextSiblingElement("Device")) {
            const char* deviceName = deviceElement->Attribute("name");
            const char* deviceType = deviceElement->Attribute("type");
            bool deviceStatus;
            deviceElement->QueryBoolAttribute("status", &deviceStatus);
            Device device(deviceName, deviceType, deviceStatus);
            room.AddDevice(device);
        }

        rooms_.insert({ room.GetName(), room });
    }
}


void SmartHome::AddToXml(const std::string &filename)
{
    tinyxml2::XMLDocument xmlDoc;
        tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("SmartHome");
        xmlDoc.InsertFirstChild(pRoot);

        for (auto& [roomName, room] : rooms_) {
            tinyxml2::XMLElement* pRoomElement = xmlDoc.NewElement("Room");
            pRoomElement->SetAttribute("name", roomName.c_str());

            for (auto& [name, sensor] : room.GetSensors()) {
                tinyxml2::XMLElement* sensorElement = xmlDoc.NewElement("Sensor");
                sensorElement->SetAttribute("name", name.c_str());
                sensorElement->SetAttribute("type", sensor.GetType().c_str());
                sensorElement->SetAttribute("value", sensor.GetValue());
                pRoomElement->InsertEndChild(sensorElement);
            }

            for (auto& [name, device] : room.GetDevices()) {
                tinyxml2::XMLElement* deviceElement = xmlDoc.NewElement("Device");
                deviceElement->SetAttribute("name", name.c_str());
                deviceElement->SetAttribute("type", device.GetType().c_str());
                deviceElement->SetAttribute("status", device.GetStatus());
                pRoomElement->InsertEndChild(deviceElement);
            }

            pRoot->InsertEndChild(pRoomElement);
        }

        tinyxml2::XMLError eResult = xmlDoc.SaveFile(filename.c_str());
        if (eResult != tinyxml2::XML_SUCCESS) {
            throw std::invalid_argument("Error saving to file!");
        }
}

std::unordered_map<std::string, Room>* SmartHome::GetRooms()
{
    return &rooms_;
}

Room* SmartHome::GetRoom(const std::string &roomName)
{
    return &rooms_.find(roomName)->second;
}
