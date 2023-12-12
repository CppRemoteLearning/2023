#include <iostream>
#include <cstring>

#include "components/smart_home/smart_home.hpp"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

SmartHome readFromXML(std::string_view inputFile) {
  using namespace rapidxml;

  file<> xmlFile(inputFile.data());
  
  xml_document<> doc;
  doc.parse<0>(xmlFile.data());
  
  xml_node<>* rootNode = doc.first_node("SmartHome");
  SmartHome smartHome(rootNode->first_attribute("name")->value());
  std::cout << "SmartHome: " << smartHome.GetName() << std::endl;

  for (xml_node<>* roomNode = rootNode->first_node("Room"); roomNode; roomNode = roomNode->next_sibling()) {
    Room room(roomNode->first_attribute("name")->value());
    std::cout << " Room: " << room.GetName() << std::endl;
    
    for (xml_node<>* deviceNode = roomNode->first_node("Device"); deviceNode; deviceNode = deviceNode->next_sibling("Device")) {
      Device device(deviceNode->first_attribute("name")->value());
      std::cout << "   Device: " << device.GetName() << std::endl;
      room.AddDevice(device);
    }
    for (xml_node<>* sensorNode = roomNode->first_node("Sensor"); sensorNode; sensorNode = sensorNode->next_sibling("Sensor")) {
      Sensor sensor(sensorNode->first_attribute("name")->value());
      std::cout << "   Sensor: " << sensor.GetName() << std::endl;
      room.AddSensor(sensor);
    }
    smartHome.AddRoom(room);
  }

  return smartHome;
}

void writeToXML(const SmartHome& smartHome, std::string_view outputFile) {
  using namespace rapidxml;

  xml_document<> doc;
  xml_node<>* rootNode = doc.allocate_node(node_element, "SmartHome");
  rootNode->append_attribute(doc.allocate_attribute("name", strdup(smartHome.GetName().c_str())));
  doc.append_node(rootNode);

  for (const Room& room : smartHome.GetRooms()) {
    xml_node<>* roomNode = doc.allocate_node(node_element, "Room");
    roomNode->append_attribute(doc.allocate_attribute("name", strdup(room.GetName().c_str())));
    rootNode->append_node(roomNode);

    for (const Device& device : room.GetDevices()) {
      xml_node<>* deviceNode = doc.allocate_node(node_element, "Device");
      deviceNode->append_attribute(doc.allocate_attribute("name", strdup(device.GetName().c_str())));
      roomNode->append_node(deviceNode);
    }
    for (const Sensor& sensor : room.GetSensors()) {
      xml_node<>* sensorNode = doc.allocate_node(node_element, "Sensor");
      sensorNode->append_attribute(doc.allocate_attribute("name", strdup(sensor.GetName().c_str())));
      roomNode->append_node(sensorNode);
    }
  }

  std::ofstream fileStream(outputFile.data());
  print(std::ostream_iterator<char>(fileStream), doc, 0);
  fileStream.close();
}

int main() {
  // TODO parse XML file and build smart home using XMLReadVisitor and print smart home using XMLWriteVisitor

  // POC
  SmartHome smartHome{readFromXML("input.xml")};
  writeToXML(smartHome, "out/output.xml");

  return 0;
}