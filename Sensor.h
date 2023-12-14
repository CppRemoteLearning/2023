#include <string>

class Sensor
{
public:
    Sensor(std::string type);

    std::string getType();
    std::string getData();
    void setType(std::string type);

private:
    std::string type;
};