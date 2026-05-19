#include "DoorLock.h"

// Constructor initializes lock state and last user
DoorLock::DoorLock(int i, string n,
    string m, bool l, string user)
    : Device(i, n, m)           // Calls base constructor
{
    locked = l;
    lastUser = user;
}

// Allows user to lock or unlock the door
// Demonstrates encapsulated state modification
void DoorLock::PerformInteraction()
{
    cout << "\n==============================\n";
    cout << "Interacting with Door Lock: " << name << endl;
    cout << "Currently Locked: " << (locked ? "Yes" : "No") << endl;
    cout << "Last Opened By: " << lastUser << endl;

    int choice;
    cout << "1. Lock  2. Unlock: ";
    while (!(cin >> choice) || (choice != 1 && choice != 2))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter 1 or 2: ";
    }

    cout << "Enter username: ";
    cin >> lastUser;

    locked = (choice == 1);         // Update lock state

    cout << "Door Lock updated successfully!\n";
}

// Displays complete door lock details
void DoorLock::ViewInfo() const
{
    cout << "\n--- Door Lock ---"
        << "\nID: " << id
        << "\nName: " << name
        << "\nManufacturer: " << manufacturer
        << "\nLocked: " << (locked ? "Yes" : "No")
        << "\nLast Opened By: " << lastUser
        << "\nStatus: " << (status ? "Active" : "Inactive")
        << "\nConnection: " << (connection ? "Connected" : "Disconnected")
        << endl;
}
