#ifndef NAGARROREMOTELEARNING_TEMPERATURESENSOR_H
#define NAGARROREMOTELEARNING_TEMPERATURESENSOR_H
#include "Sensor.h"

namespace SmartHome {
    class TemperatureSensor : public Sensor {
    public:
        TemperatureSensor(const std::string &name);

        void generateRandomValue() override;
        double readTemperature() const;

    private:
        double convertToFahrenheit() const;
    };
}
#endif
