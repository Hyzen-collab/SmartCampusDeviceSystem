// Abstract Base Class

#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    int id;                 // Unique device ID
    string name;            // Device name
    string manufacturer;    // Device manufacturer
    bool status;            // Active / Inactive state
    bool connection;        // Connected / Disconnected state

    // Pure virtual function (must be implemented by derived classes)
    virtual void PerformInteraction() = 0;

public:
    Device(int, string, string);       // Constructor
    virtual ~Device();                 // Virtual destructor

    int GetID() const;                 // Returns device ID

    void Activate();                   // Sets device active
    void Deactivate();                 // Sets device inactive
    void SetConnection(bool);          // Sets connection state

    // Controls interaction flow
    void InteractionEvent();           

    virtual void ViewInfo() const = 0; // Pure virtual function
};

#endif
