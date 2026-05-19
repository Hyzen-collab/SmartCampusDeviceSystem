//G21328023_IDUSHA PIUMIKA
// Main driver file for Smart Campus Device Management System
// Demonstrates: Polymorphism, Dynamic Memory Allocation, Encapsulation, Inheritance

#define _CRTDBG_MAP_ALLOC
#include "SecurityCamera.h"
#include "AirConditioning.h"
#include "Projector.h"
#include "RoomLighting.h"
#include "DoorLock.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    const int MAX = 100;         // Maximum number of devices allowed in the system

    // Dynamic array of base class pointers
    Device** devices = new Device * [MAX];
    int count = 0;               // Keeps track of current number of devices
    int nextID = 1;              // Auto generated unique ID for each device

    int choice;                  // Stores user menu selection
    do 
    {
        cout << "==========================================" << endl;
        cout << "======= Campus Smart Device Console ======" << endl;
        cout << "==========================================" << endl;

        cout << "\n1. Add Device"
            << "\n2. View All Devices"
            << "\n3. Activate All Devices"
            << "\n4. Deactivate All Devices"
            << "\n5. Interact All Devices"
            << "\n6. Delete Device"
            << "\n7. Activate Single Device"
            << "\n8. Deactivate Single Device"
            << "\n9. View Single Device's Info"
            << "\n10.Interact Single Device"
            << "\n0. Exit"
            << "\n============================================\n";

        cout << "Choice: ";
        // Input validation for menu
        while (!(cin >> choice) || choice < 0 || choice > 10)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Choice please enter a valid number: ";
        }

        if (choice == 1)
        {
            cout << "\n---Add New Device---\n";
            cout << "1. Camera\n2. AC\n3. Projector\n4. Light\n5. DoorLock\n";

            int type;
            cout << "Choice: ";

            while (!(cin >> type) || type < 1 || type > 5)
            {
                cin.clear();                 //Clears the errors flags
                cin.ignore(1000, '\n');      //Remove Invalid inputs (Max character & stop when new line found)
                cout << "Invalid Choice please enter a valid number: ";
            }

            string name, manufacturer;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Manufacturer: ";
            cin >> manufacturer;

            // Create object dynamically based on user choice
            // Demonstrates Runtime Polymorphism
            if (type == 1)
            {
                string quality, power;

                cout << "Enter Quality (720p/1080p/4k): ";
                cin >> quality;

                while (quality != "720p" && quality != "1080p" && quality != "4k")
                {
                    cout << "Invalid input please enter a valid input: ";
                    cin >> quality;
                }

                cout << "Enter Power (mains/battery/solar): ";
                cin >> power;

                while (power != "mains" && power != "battery" && power != "solar")
                {
                    cout << "Invalid input please enter a valid input: ";
                    cin >> power;
                }

                devices[count++] =
                    new SecurityCamera(nextID++, name, manufacturer,
                        quality, power);
            }

            else if (type == 2)
            {
                int temp;
                cout << "Enter Target Temperature: ";

                while (!(cin >> temp) || temp < 0 || temp > 36)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input please enter a valid number: ";
                }

                devices[count++] =
                    new AirConditioning(nextID++, name, manufacturer,
                        temp);
            }

            else if (type == 3)
            {
                string input;
                int brightness;

                cout << "Enter Input (VGA/HDMI/Wireless): ";
                cin >> input;

                while (input != "VGA" && input != "HDMI" && input != "Wireless")
                {
                    cout << "Invalid input please enter a valid input: ";
                    cin >> input;
                }

                cout << "Enter Brightness (0-100): ";

                while (!(cin >> brightness) ||
                    brightness < 0 || brightness > 100)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input please enter 0-100: ";
                }

                devices[count++] =
                    new Projector(nextID++, name, manufacturer,
                        input, brightness);
            }

            else if (type == 4)
            {
                int brightness;

                cout << "Enter Brightness (0-100): ";

                while (!(cin >> brightness) ||
                    brightness < 0 || brightness > 100)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input please enter 0-100: ";
                }

                devices[count++] =
                    new RoomLighting(nextID++, name, manufacturer,
                        brightness);
            }

            else if (type == 5)
            {
                int lockedInput;
                string user;

                cout << "Is The Door Locked? (1=Locked 0=Open): ";

                while (!(cin >> lockedInput) ||
                    (lockedInput != 0 && lockedInput != 1))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input please enter 1 or 0: ";
                }

                cout << "Enter Last Opened By: ";
                cin >> user;

                devices[count++] =
                    new DoorLock(nextID++, name, manufacturer,
                        lockedInput == 1, user);
            }

            cout << "Device added successfully!\n";
        }
        //View All
        else if (choice == 2)
        {
            for (int i = 0; i < count; i++)
                devices[i]->ViewInfo();
        }
        //Activate All
        else if (choice == 3)
        {
            for (int i = 0; i < count; i++)
                devices[i]->Activate();
        }
        //Deacctivate All
        else if (choice == 4)
        {
            for (int i = 0; i < count; i++)
                devices[i]->Deactivate();
        }
        //Interact All
        else if (choice == 5)
        {
            for (int i = 0; i < count; i++)
                devices[i]->InteractionEvent();
        }
        //Delete Device
        else if (choice == 6)
        {
            int deleteID;
            cout << "Enter ID to delete: ";
            cin >> deleteID;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (devices[i]->GetID() == deleteID)
                {
                    delete devices[i];     // Free memory

                    // Shift remaining elements
                    for (int j = i; j < count - 1; j++)
                        devices[j] = devices[j + 1];

                    count--;          //Now the system ignores the last duplicated element
                    found = true;
                    cout << "Device deleted.\n";
                    break;
                }
            }

            if (!found)
                cout << "Invalid ID.\n";
        }

        else if (choice == 7)
        {
            int id;
            cout << "Enter Device ID to Activate: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (devices[i]->GetID() == id)
                {
                    devices[i]->Activate();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Invalid ID.\n";
        }

        else if (choice == 8)
        {
            int id;
            cout << "Enter Device ID to Deactivate: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (devices[i]->GetID() == id)
                {
                    devices[i]->Deactivate();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Invalid ID.\n";
        }

        else if (choice == 9)
        {
            int id;
            cout << "Enter Device ID to View: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (devices[i]->GetID() == id)
                {
                    devices[i]->ViewInfo();  // Polymorphic call
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Invalid ID.\n";
        }

        else if (choice == 10)
        {
            int id;
            cout << "Enter Device ID to Interact: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (devices[i]->GetID() == id)
                {
                    devices[i]->InteractionEvent();  ///Calls base class method which safely checks
                    found = true;                    //connection and status before calling the
                    break;                           //derived class’s PerformInteraction() 
                }
            }

            if (!found)
                cout << "Invalid ID.\n";
        }

    } while (choice != 0);

    // Clean up all dynamically allocated memory
    for (int i = 0; i < count; i++)
        delete devices[i];

    delete[] devices;

    _CrtDumpMemoryLeaks();
    return 0;
}
