#ifndef NAGARROREMOTELEARNING_HEATER_H
#define NAGARROREMOTELEARNING_HEATER_H

#include "Device.h"

namespace SmartHome {
    class Heater : public Device {
    public:
        Heater();
        void setTemperature(int temperature);
        int getTemperature() const;
        void displayStatuses() const override;

    private:
        int temperature;
    };
}

#endif