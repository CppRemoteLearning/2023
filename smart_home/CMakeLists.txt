cmake_minimum_required(VERSION 3.10)

project(smart_home)

add_executable(smart_home src/main.cc src/services/temperature_service.cc src/services/presence_service.cc src/services/service.cc
src/services/light_service.cc src/services/status_service.cc src/devices/ac_unit.cc src/devices/device.cc src/devices/fan.cc
src/devices/light_bulb.cc)

target_include_directories(smart_home PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(smart_home PRIVATE "${CMAKE_SOURCE_DIR}/libs/tinyxml2_library.a")