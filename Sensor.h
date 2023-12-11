#ifndef NAGARROREMOTELEARNING_SENSOR_H
#define NAGARROREMOTELEARNING_SENSOR_H

#include <string>
#include <cstdlib>
#include "enums.h"

class Sensor {
private:
    std::string name;
    int* value;
    MeasureUnit unit;
public:
    Sensor(const std::string& sensorName, MeasureUnit sensorUnit)
            : name(sensorName), value(new int(0)), unit(sensorUnit) {}

    Sensor(const Sensor& other)
            : name(other.name), value(new int(*(other.value))), unit(other.unit) {}

    Sensor& operator=(const Sensor& other) {
        if (this != &other) {
            delete value;
            name = other.name;
            value = new int(*(other.value));
            unit = other.unit;
        }
        return *this;
    }

    Sensor(Sensor&& other)
            : name(std::move(other.name)), value(other.value), unit(other.unit) {
        other.value = nullptr;
    }

    Sensor& operator=(Sensor&& other) {
        if (this != &other) {
            delete value;
            name = std::move(other.name);
            value = other.value;
            unit = other.unit;
            other.value = nullptr;
        }
        return *this;
    }

    ~Sensor() {
        delete value;
    }

    void generateRandomValue() {
        *value = rand() % 100;
    }

    const std::string& getName() const {
        return name;
    }

    int getValue() const {
        return *value;
    }

    MeasureUnit getUnit() const {
        return unit;
    }
};

#endif
