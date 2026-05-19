#include "Device.h"

// Constructor initializes device data
Device::Device(int i, string n, string m)
{
    id = i;
    name = n;
    manufacturer = m;
    status = false;         // Devices start inactive
    connection = true;      // Devices start connected
}

// Virtual destructor ensures proper cleanup
Device::~Device() {}

// Getter for ID
int Device::GetID() const
{
    return id;
}

// Activate device
void Device::Activate()
{
    status = true;
}

// Deactivate device
void Device::Deactivate()
{
    status = false;
}

// Set connection state
void Device::SetConnection(bool c)
{
    connection = c;
}

// Ensures device is active and connected before interaction
void Device::InteractionEvent()
{
    if (!connection)
    {
        cout << "Device not connected.\n";
        return;
    }

    if (!status)
    {
        cout << "Activate device first.\n";
        return;
    }

    PerformInteraction();   // Polymorphic function call
}
