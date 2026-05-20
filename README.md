# 🏫 Smart Campus Device Management System

![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue?style=flat-square&logo=cplusplus)
![OOP](https://img.shields.io/badge/Paradigm-Object--Oriented-green?style=flat-square)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey?style=flat-square&logo=windows)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-purple?style=flat-square&logo=visualstudio)
![Memory](https://img.shields.io/badge/Memory-CRT%20Leak%20Checked-orange?style=flat-square)

A console-based **C++ application** that simulates a centralised smart device management platform for a university campus. Devices such as security cameras, air conditioners, projectors, lights, and door locks can be added, monitored, activated, and controlled at runtime through an interactive menu.

The project was built with a strong emphasis on the four pillars of **Object-Oriented Programming** — encapsulation, inheritance, polymorphism, and abstraction — and uses dynamic memory allocation with CRT leak detection to ensure clean resource management.

---

## 📋 Table of Contents

- [Features](#-features)
- [OOP Design Principles](#-oop-design-principles)
- [Class Architecture](#-class-architecture)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Building with Visual Studio](#building-with-visual-studio)
  - [Building with g++](#building-with-g-linuxmacos)
- [Menu Reference](#-menu-reference)
- [Usage Walkthrough](#-usage-walkthrough)
- [Memory Management](#-memory-management)
- [Author](#-author)

---

## ✨ Features

- **5 Device Types** — Security Camera, Air Conditioning, Projector, Room Lighting, Door Lock
- **Runtime Polymorphism** — `ViewInfo()`, `Activate()`, `Deactivate()`, and `InteractionEvent()` behave differently for each device type via virtual dispatch
- **Bulk & Single Operations** — Apply actions to all devices at once, or target a specific device by ID
- **Auto-Incrementing IDs** — Each device gets a unique ID automatically on creation
- **Strict Input Validation** — Every input is validated in a loop; invalid entries are rejected gracefully
- **Dynamic Memory Management** — Devices are heap-allocated with full cleanup on exit
- **CRT Leak Detection** — Uses `_CrtSetDbgFlag` and `_CrtDumpMemoryLeaks` to catch any memory leaks in Debug builds

---

## 🧠 OOP Design Principles

| Principle | How It Is Applied |
|---|---|
| **Encapsulation** | Each device's attributes (ID, name, manufacturer, status, device-specific settings) are private, exposed only through public methods |
| **Inheritance** | `SecurityCamera`, `AirConditioning`, `Projector`, `RoomLighting`, and `DoorLock` all inherit from the abstract base class `Device` |
| **Polymorphism** | A `Device**` array holds pointers to any device subclass; virtual methods (`ViewInfo`, `Activate`, `Deactivate`, `InteractionEvent`, `PerformInteraction`) are dispatched at runtime |
| **Abstraction** | `Device` defines the interface and common behaviour; each subclass handles its own specifics without exposing implementation details to `main` |

---

## 🏗 Class Architecture

```
Device  (Abstract Base Class)
│   - int id
│   - string name, manufacturer
│   - bool isActive, isConnected
│   + GetID()
│   + Activate()
│   + Deactivate()
│   + InteractionEvent()        ← checks connectivity & status, then calls PerformInteraction()
│   + ViewInfo()                ← virtual
│   # PerformInteraction()      ← pure virtual (overridden by each subclass)
│
├── SecurityCamera
│     - string quality          (720p / 1080p / 4k)
│     - string powerSource      (mains / battery / solar)
│     + ViewInfo()
│     # PerformInteraction()
│
├── AirConditioning
│     - int targetTemperature   (0–36 °C)
│     + ViewInfo()
│     # PerformInteraction()
│
├── Projector
│     - string inputSource      (VGA / HDMI / Wireless)
│     - int brightness          (0–100)
│     + ViewInfo()
│     # PerformInteraction()
│
├── RoomLighting
│     - int brightness          (0–100)
│     + ViewInfo()
│     # PerformInteraction()
│
└── DoorLock
      - bool isLocked
      - string lastOpenedBy
      + ViewInfo()
      # PerformInteraction()
```

`InteractionEvent()` in the base class safely checks the device's connection and active status before delegating to the derived class's `PerformInteraction()`, keeping guard logic centralised and subclasses clean.

---

## 📁 Project Structure

```
SmartCampusDeviceSystem/
│
├── Smart_Campus/
│   ├── Smart_Campus.cpp        # Entry point — main menu loop & device management logic
│   ├── Device.h / .cpp         # Abstract base class
│   ├── SecurityCamera.h / .cpp # Camera subclass (quality, power source)
│   ├── AirConditioning.h / .cpp# AC subclass (target temperature)
│   ├── Projector.h / .cpp      # Projector subclass (input, brightness)
│   ├── RoomLighting.h / .cpp   # Lighting subclass (brightness)
│   └── DoorLock.h / .cpp       # Door lock subclass (lock state, last user)
│
├── .vs/Smart_Campus/           # Visual Studio IDE metadata (auto-generated)
├── x64/Debug/                  # Build output (auto-generated)
├── Smart_Campus.sln            # Visual Studio solution file
├── Report.docx                 # Project report
├── .gitignore
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- **C++17** or later
- **Visual Studio 2019 / 2022** (Windows — recommended), **or**
- **g++ 9+** (Linux / macOS / MinGW on Windows)

---

### Building with Visual Studio

```
1. Clone the repo:
   git clone https://github.com/Hyzen-collab/SmartCampusDeviceSystem.git

2. Open Smart_Campus.sln in Visual Studio.

3. Set the build configuration to Debug (x64).

4. Press Ctrl + Shift + B to build.

5. Press Ctrl + F5 to run.
```

CRT memory leak output will appear in the **Output** window when the program exits in Debug mode.

---

### Building with g++ (Linux/macOS)

```bash
git clone https://github.com/Hyzen-collab/SmartCampusDeviceSystem.git
cd SmartCampusDeviceSystem/Smart_Campus

g++ -std=c++17 -o SmartCampus \
    Smart_Campus.cpp \
    Device.cpp \
    SecurityCamera.cpp \
    AirConditioning.cpp \
    Projector.cpp \
    RoomLighting.cpp \
    DoorLock.cpp

./SmartCampus
```

> **Note:** The `_CrtSetDbgFlag` and `_CrtDumpMemoryLeaks` macros are Windows/MSVC-specific. On Linux/macOS they will be undefined and can be safely removed or guarded with `#ifdef _WIN32`.

---

## 📟 Menu Reference

```
==========================================
======= Campus Smart Device Console ======
==========================================

 1.  Add Device
 2.  View All Devices
 3.  Activate All Devices
 4.  Deactivate All Devices
 5.  Interact All Devices
 6.  Delete Device
 7.  Activate Single Device
 8.  Deactivate Single Device
 9.  View Single Device's Info
 10. Interact Single Device
 0.  Exit
```

| Option | Description |
|---|---|
| 1 | Prompts for device type, then collects type-specific attributes with full input validation |
| 2 | Calls `ViewInfo()` on every registered device (polymorphic) |
| 3 / 4 | Calls `Activate()` / `Deactivate()` on all devices |
| 5 | Calls `InteractionEvent()` on all devices |
| 6 | Deletes a device by ID; shifts the array and frees heap memory |
| 7 / 8 | Activates or deactivates a single device found by ID |
| 9 | Displays info for one device by ID |
| 10 | Triggers `InteractionEvent()` on one device by ID |

---

## 🖥 Usage Walkthrough

**Adding a Security Camera:**
```
--- Add New Device ---
1. Camera  2. AC  3. Projector  4. Light  5. DoorLock
Choice: 1
Enter Name: MainEntrance
Enter Manufacturer: Hikvision
Enter Quality (720p/1080p/4k): 1080p
Enter Power (mains/battery/solar): mains
Device added successfully!
```

**Viewing all devices:**
```
Choice: 2
[ID: 1] MainEntrance | Hikvision | Camera | 1080p | mains | Status: Inactive
```

**Deleting a device:**
```
Choice: 6
Enter ID to delete: 1
Device deleted.
```

---

## 🧹 Memory Management

- All devices are stored as `Device*` in a heap-allocated `Device**` array of maximum size 100.
- When a device is deleted (option 6), `delete devices[i]` is called before the array is compacted.
- On program exit, every remaining device is individually `delete`d, followed by `delete[] devices`.
- In Debug builds on MSVC, `_CrtDumpMemoryLeaks()` reports any remaining allocations to confirm a clean exit.

---

## 👤 Author

**Idusha Piumika**  
Student ID: G21328023  
[GitHub — @Hyzen-collab](https://github.com/Hyzen-collab)

---

> **Academic Notice:** This project was developed as part of a C++ Object-Oriented Programming module. It is intended for educational and demonstration purposes.
