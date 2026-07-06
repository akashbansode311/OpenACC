#include <iostream>
#include <string>
#include <openacc.h>   // OpenACC runtime API

int main()
{
    // Get the default device type OpenACC will target (e.g. NVIDIA GPU, or host)
    acc_device_t devtype = acc_get_device_type();

    // Ask the runtime how many devices of this type are available
    int numDevices = acc_get_num_devices(devtype);

    if (numDevices == 0)
    {
        std::cout << "There is no device supporting OpenACC" << std::endl;
        return 0;
    }

    // Loop over every available device
    for (int dev = 0; dev < numDevices; ++dev)
    {
        if (dev == 0)
        {
            if (numDevices == 1)
                std::cout << "There is 1 device supporting OpenACC" << std::endl;
            else
                std::cout << "There are " << numDevices << " devices supporting OpenACC" << std::endl;
        }

        // Device name
        std::string devName = acc_get_property_string(dev, devtype, acc_property_name);
        std::cout << "\nDevice " << dev << ": \"" << devName << "\"" << std::endl;

        // Vendor string (e.g. "NVIDIA")
        std::string vendor = acc_get_property_string(dev, devtype, acc_property_vendor);
        std::cout << "  Vendor:                                        " << vendor << std::endl;

        // Total global memory on the device
        size_t totalMem = acc_get_property(dev, devtype, acc_property_memory);
        std::cout << "  Total amount of global memory:                 " << totalMem << " bytes" << std::endl;

        // Free memory currently available on the device
        size_t freeMem = acc_get_property(dev, devtype, acc_property_free_memory);
        std::cout << "  Free memory available:                         " << freeMem << " bytes" << std::endl;
    }

    // Select device 0 as the active device for future OpenACC regions
    acc_set_device_num(0, devtype);
    std::cout << "\nDevice 0 selected as active OpenACC device." << std::endl;

    return 0;
}
