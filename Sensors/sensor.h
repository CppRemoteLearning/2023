#ifndef SENSOR_H
#define SENSOR_H

#include <string>

namespace smart_home
{

class Sensor
{
public:
    Sensor(const std::string &name = "");
    std::string& GetName();
    void SetName(const std::string &name);

    virtual bool ActionNeeded() = 0;

    virtual ~Sensor() = default;

private:
    std::string name_;
};

} // namespace smart_home

#endif