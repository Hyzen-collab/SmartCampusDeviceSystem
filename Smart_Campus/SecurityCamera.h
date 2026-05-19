// Derived class representing a Smart Security Camera

#ifndef SECURITYCAMERA_H
#define SECURITYCAMERA_H

#include "Device.h"

class SecurityCamera : public Device
{
private:
    string quality;        // Camera resolution (720p / 1080p / 4k) 
    string power;          // Power source (mains / battery / solar) 

protected:
    // Defines camera-specific interaction behavior
    void PerformInteraction() override;

public:
    // Constructor initializes camera properties
    SecurityCamera(int, string, string, string, string);

    // Displays camera information
    void ViewInfo() const override;
};

#endif
