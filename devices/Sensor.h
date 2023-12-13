#ifndef NAGARROREMOTELEARNING_SENSOR_H
#define NAGARROREMOTELEARNING_SENSOR_H

#include <string>
#include "../utils/enums.h"

namespace SmartHome {
    class Sensor {
    private:
        std::string name;
        int *value;
        MeasureUnit unit;

    public:
        const std::string &getName() const;

        int getValue() const;

        MeasureUnit getUnit() const;

        Sensor(const std::string &sensorName, MeasureUnit sensorUnit);

        Sensor(const Sensor &other);

        Sensor &operator=(const Sensor &other);

        Sensor(Sensor &&other);

        Sensor &operator=(Sensor &&other);

        ~Sensor();

        void generateRandomValue();
    };
}
#endif