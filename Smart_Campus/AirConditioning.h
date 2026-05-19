// Derived class representing a Air Conditioner

#ifndef AIRCONDITIONING_H
#define AIRCONDITIONING_H

#include "Device.h"

class AirConditioning : public Device
{
private:
    int temperature;                        // Target room temperature

protected:
    void PerformInteraction() override;     // Overridden function

public:
    AirConditioning(int, string, string, int);
    void ViewInfo() const override;         //display device information
};

#endif                                      //ends the header guard
