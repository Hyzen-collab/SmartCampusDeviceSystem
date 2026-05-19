#include <vector>
#include <memory>
#include "Device.h"

class DeviceManager
{
private:
    std::vector<std::unique_ptr<Device>> devices;
    int nextID;

public:
    DeviceManager();

    void AddDevice();
    void ViewAll() const;
    void ActivateAll() const;
    void DeactivateAll() const;
    void InteractAll() const;
    void DeleteDevice();
    void ActivateSingle() const;
    void DeactivateSingle() const;
};
