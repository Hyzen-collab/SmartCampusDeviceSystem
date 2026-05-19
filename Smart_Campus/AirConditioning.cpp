#include "AirConditioning.h"

// Constructor initializes temperature
AirConditioning::AirConditioning(int i, string n,
    string m, int t)
    : Device(i, n, m)
{
    temperature = t;            //A private variable (Only class functions can modify it)
}

// Allows user to update temperature
void AirConditioning::PerformInteraction()
{
    cout << "==============================\n";
    cout << "Interacting with Air Conditioning: " << name << endl;
    cout << "Current Target Temperature: " << temperature << endl;

    int temp;
    cout << "Enter new target temperature: ";
    while (!(cin >> temp) || temp < 0 || temp > 36)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter a valid Temperature(0-36): ";
    }
    temperature = temp;

    cout << "Air Conditioning updated successfully!\n";
}


// Displays device information
void AirConditioning::ViewInfo() const
{
    cout << "\n--- Air Conditioning ---"
        << "\nID: " << id
        << "\nName: " << name
        << "\nManufacturer: " << manufacturer
        << "\nTarget Temperature: " << temperature
        << "\nStatus: " << (status ? "Active" : "Inactive")
        << "\nConnection: " << (connection ? "Connected" : "Disconnected")
        << endl;
}
