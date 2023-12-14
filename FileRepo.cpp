#include "FileRepo.h"
#include <fstream>
#include <iostream>

void FileRepo::saveToFile(std::string filename, std::unordered_map<std::string, Room> rooms)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error opening file " << filename << std::endl;
        return;
    }

    for (auto room : rooms)
    {
        file << room.second.getName() << std::endl;
    }

    file.close();
}

void FileRepo::loadFromFile(std::string filename, std::unordered_map<std::string, Room> &rooms)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error opening file rooms.txt" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
}