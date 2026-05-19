#include "Projector.h"

// Constructor using initializer list to call base constructor
Projector::Projector(int i, string n, string m,
    string in, int b)
    : Device(i, n, m)           // Calls Device constructor
{
    input = in;
    brightness = b;
}

// Overridden interaction method
// Allows user to modify input source and brightness
void Projector::PerformInteraction()
{
    cout << "==============================\n";
    cout << "Interacting with Projector: " << name << endl;
    cout << "Current Input: " << input << endl;
    cout << "Current Brightness: " << brightness << endl;

    cout << "Enter new input (VGA/HDMI/Wireless): ";
    cin >> input;

    while (true)
    {
        cin >> input;

        if (input == "VGA" || input == "HDMI" || input == "Wireless")
            break;

        cout << "Invalid input please enter (VGA/HDMI/Wireless): ";
    }

    cout << "Enter new brightness (0-100): ";
    while (!(cin >> brightness) || brightness < 0 || brightness > 100)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid. Enter 0-100: ";
    }
    cout << "Projector updated successfully!\n";
}

// Displays all projector details
void Projector::ViewInfo() const
{
    cout << "\n--- Projector ---"
        << "\nID: " << id
        << "\nName: " << name
        << "\nManufacturer: " << manufacturer
        << "\nInput: " << input
        << "\nBrightness: " << brightness
        << "\nStatus: " << (status ? "Active" : "Inactive")
        << "\nConnection: " << (connection ? "Connected" : "Disconnected")
        << endl;
}
