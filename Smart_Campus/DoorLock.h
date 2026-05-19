// Derived class representing a Smart Door Lock
// Demonstrates Encapsulation of lock state and last accessed user

#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "Device.h"

class DoorLock : public Device
{
private:
    bool locked;            // Indicates if the door is locked
    string lastUser;        // Stores the last user who accessed the door

protected:
    // Overridden function defining door interaction behavior
    void PerformInteraction() override;

public:
    // Constructor initializes door lock properties
    DoorLock(int, string, string, bool, string);

    // Displays door lock information
    void ViewInfo() const override;
};

#endif
