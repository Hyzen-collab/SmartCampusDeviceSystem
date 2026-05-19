// Derived class representing Smart Room Lighting

#ifndef ROOMLIGHTING_H
#define ROOMLIGHTING_H

#include "Device.h"

class RoomLighting : public Device
{
private:
    int brightness;         // Light brightness level (0 - 100)

protected:
    // Defines lighting-specific interaction behavior
    void PerformInteraction() override;

public:
    // Constructor initializes brightness level
    RoomLighting(int, string, string, int);

    // Displays lighting details
    void ViewInfo() const override;
};

#endif
