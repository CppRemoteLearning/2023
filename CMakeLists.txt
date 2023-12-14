cmake_minimum_required(VERSION 3.10)

project(SmartHomeApp)

set(CMAKE_CXX_STANDARD 11)

# add_executable(smart_home_app main.cpp Device.cpp Room.cpp Sensor.cpp FileRepo.cpp SmartHomeManager.cpp)
file(GLOB SRC_FILES *.cpp)
add_executable(my_project ${SRC_FILES})