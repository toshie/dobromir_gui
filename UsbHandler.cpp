#include "UsbHandler.h"

#include "lib/hidapi2/hidapi.h"

#include <iostream>
#include <string>

#include <cstdint>

UsbHandler::UsbHandler()
{
}

bool UsbHandler::connect()
{
    if (hid_init() != 0)
    {
        std::cerr << "Cannot init hid";
        return -1;
    }

    constexpr std::uint16_t dobromirVendorId = 0xebff;
    constexpr std::uint16_t dobromirProductId = 0x0;
    hid_device* dobromirUsb = hid_open(dobromirVendorId, dobromirProductId, NULL);
    if (!dobromirUsb)
    {
        std::cerr << "Cannot find Dobromir plugged in";
        return false;
    }

    std::cout << "Connected to something!\n";
    wchar_t strbuf[256];
    hid_get_manufacturer_string(dobromirUsb, strbuf, sizeof(strbuf));
    std::wcerr << "Manufacturer: " << std::wstring(strbuf) << std::endl;
    hid_get_product_string(dobromirUsb, strbuf, sizeof(strbuf));
    std::wcerr << "Product: " << std::wstring(strbuf) << std::endl;

    std::uint8_t data[65] = {0};
    data[0] = 0;
    data[1] = 0x9;
    if (hid_write(dobromirUsb, data, 21) == -1)
    {
        std::wcout << "Error sending the message: " << std::wstring(hid_error(dobromirUsb)) << std::endl;
    }
    else
    {
        std::cout << "Send OK!\n";
    }

    hid_close(dobromirUsb);
    hid_exit();

    return true;
}

bool UsbHandler::send()
{
    return true;
}
