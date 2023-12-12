cmake_minimum_required(VERSION 3.10)
project(SmartHomeProject)

add_executable(SmartHome.app
  app.cpp
  components/component.cpp
  components/device/device.cpp
  components/room/room.cpp
  components/sensor/sensor.cpp
  components/smart_home/smart_home.cpp
  visitors/xml_read_visitor/xml_read_visitor.cpp
  visitors/xml_write_visitor/xml_write_visitor.cpp)