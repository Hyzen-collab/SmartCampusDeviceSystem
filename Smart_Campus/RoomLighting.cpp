#include "RoomLighting.h"

// Constructor initializes brightness
RoomLighting::RoomLighting(int i, string n,
    string m, int b)
    : Device(i, n, m)
{
    brightness = b;
}

// Allows brightness adjustment
void RoomLighting::PerformInteraction()
{
    cout << "==============================\n";
    cout << "Interacting with Room Lighting: " << name << endl;
    cout << "Current Brightness: " << brightness << endl;

    cout << "Enter new brightness (0-100): ";
    while (!(cin >> brightness) || brightness < 0 || brightness > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter 0-100: ";
    }

    cout << "Room lighting updated successfully!\n";
}

// Displays room lighting information
void RoomLighting::ViewInfo() const
{
    cout << "\n--- Room Lighting ---"
        << "\nID: " << id
        << "\nName: " << name
        << "\nManufacturer: " << manufacturer
        << "\nBrightness: " << brightness
        << "\nStatus: " << (status ? "Active" : "Inactive")
        << "\nConnection: " << (connection ? "Connected" : "Disconnected")
        << endl;
}
