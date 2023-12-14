#include <string>

class Device
{
public:
    Device(std::string type);

    std::string getType();
    void setType(std::string type);

private:
    std::string type;
};