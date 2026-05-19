#include "SecurityCamera.h"

// Constructor initializes camera attributes
SecurityCamera::SecurityCamera(int i, string n, string m,
    string q, string p)
    : Device(i, n, m)
{
    quality = q;
    power = p;
}

// Simulates viewing the camera feed
void SecurityCamera::PerformInteraction()
{
    cout << "==============================\n";
    cout << "Viewing Security Camera: " << name << endl;
    cout << "Current Quality: " << quality << endl;
    cout << "Power Source: " << power << endl;

    cout << "Now viewing camera: " << name << endl;
}

// Displays full camera details
void SecurityCamera::ViewInfo() const
{
    cout << "\n--- Security Camera ---"
        << "\nID: " << id
        << "\nName: " << name
        << "\nManufacturer: " << manufacturer
        << "\nQuality: " << quality
        << "\nPower: " << power
        << "\nStatus: " << (status ? "Active" : "Inactive")
        << "\nConnection: " << (connection ? "Connected" : "Disconnected")
        << endl;
}
