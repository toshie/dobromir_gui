#ifndef USBHANDLER_H
#define USBHANDLER_H

#include "lib/hidapi2/hidapi.h"

#include <iostream>
#include <string>

#include <cassert>
#include <cstdint>

class UsbHandler
{
public:
    UsbHandler();

    bool connect();
    bool disconnect();
    bool sendPing();

private:
    template <typename Report>
    bool send(const Report& report)
    {
        assert(_dobromirUsb);
        if (hid_write(_dobromirUsb, reinterpret_cast<const uint8_t*>(&report), sizeof(Report)) == -1)
        {
            std::wcerr << "Error sending the message: " << std::wstring(hid_error(_dobromirUsb)) << std::endl;
            return false;
        }

        return true;
    }

    hid_device* _dobromirUsb = nullptr;
};

#endif // USBHANDLER_H
