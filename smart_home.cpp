#include "smart_home.h"

void SmartHome::GetDataFromXml(const std::string &filename) {
    tinyxml2::XMLDocument xmlDoc;
    if (xmlDoc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
        std::cout << "Error loading file!" << std::endl;
        return;
    }

    tinyxml2::XMLNode* pRoot = xmlDoc.RootElement();
    if (pRoot == nullptr) {
        std::cout << "Invalid XML format or missing 'SmartHome' node!" << std::endl;
        return;
    }


    std::cout << "Parent Element: " << pRoot->Value() << std::endl;

    tinyxml2::XMLElement* pRoomElement = pRoot->FirstChildElement("Room");

    std::cout << "Room Element: " << pRoomElement->Value() << std::endl;

    for (pRoomElement; pRoomElement != nullptr; pRoomElement = pRoomElement->NextSiblingElement("Room")) {
        const char* roomName = pRoomElement->Attribute("name");
        std::cout << "Reading Room: " << roomName << std::endl;

        Room room(roomName);

        for (tinyxml2::XMLElement* sensorElement = pRoomElement->FirstChildElement("Sensor"); sensorElement != nullptr; sensorElement = sensorElement->NextSiblingElement("Sensor")) {
            const char* sensorName = sensorElement->Attribute("name");
            const char* sensorType = sensorElement->Attribute("type");
            float sensorValue;
            sensorElement->QueryFloatAttribute("value", &sensorValue);
            Sensor sensor(sensorName, sensorType, sensorValue);
            room.AddSensor(sensor);
            std::cout << "Added Sensor: " << sensorName << std::endl;
        }

        for (tinyxml2::XMLElement* deviceElement = pRoomElement->FirstChildElement("Device"); deviceElement != nullptr; deviceElement = deviceElement->NextSiblingElement("Device")) {
            const char* deviceName = deviceElement->Attribute("name");
            const char* deviceType = deviceElement->Attribute("type");
            bool deviceStatus;
            deviceElement->QueryBoolAttribute("status", &deviceStatus);
            Device device(deviceName, deviceType, deviceStatus);
            room.AddDevice(device);
            std::cout << "Added Device: " << deviceName << std::endl;
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
            std::cout << "Error saving to file!" << std::endl;
        }
}

std::unordered_map<std::string, Room> SmartHome::GetRooms()
{
    return rooms_;
}

Room SmartHome::GetRoom(const std::string &roomName)
{
    return rooms_.find(roomName)->second;
}
