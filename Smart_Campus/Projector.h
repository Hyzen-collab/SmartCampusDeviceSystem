// Derived class representing a Smart Projector device
// Inherits from Device (Demonstrates Inheritance)

#ifndef PROJECTOR_H
#define PROJECTOR_H

#include "Device.h"

class Projector : public Device
{
private:
    string input;                   // Input source (VGA / HDMI / Wireless)
    int brightness;                 // Brightness level (0 - 100)                             

protected:
    // Overridden function from base class
    // Defines specific interaction behavior for Projector
    void PerformInteraction() override;

public:
    // Constructor initializes projector attributes
    Projector(int, string, string, string, int);

    // Displays projector information
    void ViewInfo() const override;
};

#endif
