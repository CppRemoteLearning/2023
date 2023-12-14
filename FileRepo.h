#include <string>
#include <map>
#include "Room.h"
#include <unordered_map>

class FileRepo
{
public:
    void saveToFile(std::string filename, std::unordered_map<std::string, Room> rooms);
    void loadFromFile(std::string filename, std::unordered_map<std::string, Room> &rooms);
};
