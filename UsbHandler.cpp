#include "UsbHandler.h"

#include <hidapi.h>

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
//    std::cerr << "Manufacturer: " << std::wstring(strbuf);
    hid_get_product_string(dobromirUsb, strbuf, sizeof(strbuf));
//    std::cerr << "Product: " << std::wstring(strbuf);

    return true;
}

bool UsbHandler::send()
{
    return true;
}
