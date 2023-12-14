#include <iostream>
#include "Device.h"
#include "Room.h"
#include "Sensor.h"
#include <set>
#include <vector>

using namespace System::Xml;

void readFromXml()
{
    XmlTextReader* reader = new XmlTextReader ("file.xml");

    while (reader->Read())
    {
        switch (reader->NodeType)
        {
            case XmlNodeType::Sensor: 
                
                while (reader->MoveToNextAttribute()) 
                    Console::Write(" {0}='{1}'", reader->Name, reader->Value);
                Console::WriteLine(">");
                break;
            case XmlNodeType::Device
                Console::WriteLine (reader->Value);
                break;
            case XmlNodeType::Room
                Console::Write("</{0}", reader->Name);
                Console::WriteLine(">");
                break;
        }
    }
}
std::vector<Sensor> sen;
std::vector<Device> dev;
std::vector<Room> room;
int main()
{
    //readFromXml();

    Sensor sen;
    Device dev;
    Room rom;

    dev.addSensor(&sen);
    rom.addDevice(&dev);

    return 0;
}