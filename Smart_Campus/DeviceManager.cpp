#include <iostream>
#include "DeviceManager.h"
#include "SecurityCamera.h"
#include "AirConditioning.h"
#include "Projector.h"
#include "RoomLighting.h"
#include "DoorLock.h"

using namespace std;

DeviceManager::DeviceManager()
{
    nextID = 1;
}

void DeviceManager::AddDevice()
{
    cout << "\n---Add New Device---\n";
    cout << "1. Camera\n2. AC\n3. Projector\n4. Light\n5. DoorLock\n";

    int type;
    cout << "Choice: ";

    while (!(cin >> type) || type < 1 || type > 5)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Choice please enter a valid number: ";
    }

    string name, manufacturer;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Manufacturer: ";
    cin >> manufacturer;

    if (type == 1)
    {
        string quality, power;

        cout << "Enter Quality (720p/1080p/4k): ";
        cin >> quality;

        cout << "Enter Power (mains/battery/solar): ";
        cin >> power;

        devices.push_back(
            make_unique<SecurityCamera>(nextID++, name, manufacturer, quality, power)
        );
    }

    else if (type == 2)
    {
        int temp;
        cout << "Enter Target Temperature: ";
        cin >> temp;

        devices.push_back(
            make_unique<AirConditioning>(nextID++, name, manufacturer, temp)
        );
    }

    else if (type == 3)
    {
        string input;
        int brightness;

        cout << "Enter Input (VGA/HDMI/Wireless): ";
        cin >> input;

        cout << "Enter Brightness (0-100): ";
        cin >> brightness;

        devices.push_back(
            make_unique<Projector>(nextID++, name, manufacturer, input, brightness)
        );
    }

    else if (type == 4)
    {
        int brightness;

        cout << "Enter Brightness (0-100): ";
        cin >> brightness;

        devices.push_back(
            make_unique<RoomLighting>(nextID++, name, manufacturer, brightness)
        );
    }

    else if (type == 5)
    {
        int lockedInput;
        string user;

        cout << "Is The Door Locked? (1=Locked 0=Open): ";
        cin >> lockedInput;

        cout << "Enter Last Opened By: ";
        cin >> user;

        devices.push_back(
            make_unique<DoorLock>(nextID++, name, manufacturer, lockedInput == 1, user)
        );
    }
}

void DeviceManager::ViewAll() const
{
    for (const auto& device : devices)
        device->ViewInfo();
}

void DeviceManager::ActivateAll() const
{
    for (const auto& device : devices)
        device->Activate();
}

void DeviceManager::DeactivateAll() const
{
    for (const auto& device : devices)
        device->Deactivate();
}

void DeviceManager::InteractAll() const
{
    for (const auto& device : devices)
        device->InteractionEvent();
}

void DeviceManager::DeleteDevice()
{
    int deleteID;
    cout << "Enter ID to delete: ";
    cin >> deleteID;

    for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        if ((*it)->GetID() == deleteID)
        {
            devices.erase(it);
            cout << "Device deleted.\n";
            return;
        }
    }

    cout << "Invalid ID.\n";
}

void DeviceManager::ActivateSingle() const
{
    int id;
    cout << "Enter Device ID to Activate: ";
    cin >> id;

    for (const auto& device : devices)
    {
        if (device->GetID() == id)
        {
            device->Activate();
            return;
        }
    }

    cout << "Invalid ID.\n";
}

void DeviceManager::DeactivateSingle() const
{
    int id;
    cout << "Enter Device ID to Deactivate: ";
    cin >> id;

    for (const auto& device : devices)
    {
        if (device->GetID() == id)
        {
            device->Deactivate();
            return;
        }
    }

    cout << "Invalid ID.\n";
}
