#ifndef NAGARROREMOTELEARNING_HUMIDITYSENSOR_H
#define NAGARROREMOTELEARNING_HUMIDITYSENSOR_H

#include "Sensor.h"

namespace SmartHome {
    class HumiditySensor : public Sensor {
    public:
        HumiditySensor(const std::string &name);

        void generateRandomValue() override;
        double getHumidityPercentage() const;
    };
}

#endif
