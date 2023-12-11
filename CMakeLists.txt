cmake_minimum_required(VERSION 3.10)
project(nagarroRemoteLearning)

set(CMAKE_CXX_STANDARD 17)

add_executable(nagarroRemoteLearning main.cc
        enums.h
        Device.h
        Sensor.h
        Room.h
        House.h)
