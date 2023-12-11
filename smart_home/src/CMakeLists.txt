add_executable(smart_home main.cc services/temperature_service.cc devices/device.cc sensors/sensor.cc)

target_include_directories(smart_home PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/../include)