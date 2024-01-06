#include <iostream>
#include <set>
#include <vector>
#include "pugixml.hpp"
#include <sstream>

#include "Bathroom.h"
#include "Bedroom.h"
#include "Kitchen.h"

#include "Heat.h"
#include "Ultrasonic.h"
#include "Pressure.h"

#include "Refrigerator.h"
#include "Vacuum.h"
#include "TV.h"
/*
void readFromXml()
{
    pugi::xml_document doc;
    std::string namePanel;
    const wchar_t* a = L"SmartHome";
    pugi::xml_node panels = doc.child(a);

    std::cout << panels.name() << std::endl;

    for (pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling())
    {
        //We found a "Panel" -- print it's attributes
        for (pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute())
        {
            std::cout << " " << attr.name() << "=" << attr.value() << std::endl;

            //const wchar_t* name = attr.name();
            
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
*/
//std::vector<Sensor> sen;
//std::vector<Device> dev;
//std::vector<Room> room;
int main()
{
    //readFromXml();
  //  Sensor s;
 
   // std::vector<Device*> vectDiv;
   // std::set<Sensor*> sss;
  //  sss.insert(&s);
    
   // Device d(sss);
   // vectDiv.push_back(&d);
    //Room r(vectDiv);
    //Sensor sen;
    Heat h;
    //std::set<Sensor*> sss;
    //sss.insert(&h);
    Refrigerator ref;
    std::cout<<ref.typeName();
    std::cout<<h.getName();
    //Room rom;

    //dev.addSensor(&sen);
    //rom.addDevice(&dev);

    return 0;
}