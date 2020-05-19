#include "UsbHandler.h"

#include "lib/dobromir_proto/dobromir_proto.h"

UsbHandler::UsbHandler()
{
}

bool UsbHandler::connect()
{
    if (hid_init() != 0)
    {
        std::cerr << "Cannot init hid";
        return false;
    }

    constexpr std::uint16_t dobromirVendorId = 0xebff;
    constexpr std::uint16_t dobromirProductId = 0x0;
    _dobromirUsb = hid_open(dobromirVendorId, dobromirProductId, NULL);
    if (!_dobromirUsb)
    {
        std::cerr << "Cannot find Dobromir plugged in";
        return false;
    }

    std::cout << "Connected to something!\n";
    wchar_t strbuf[256];
    hid_get_manufacturer_string(_dobromirUsb, strbuf, sizeof(strbuf));
    std::wcerr << "Manufacturer: " << std::wstring(strbuf) << std::endl;
    hid_get_product_string(_dobromirUsb, strbuf, sizeof(strbuf));
    std::wcerr << "Product: " << std::wstring(strbuf) << std::endl;

    return true;
}

bool UsbHandler::disconnect()
{
    if (_dobromirUsb)
    {
        hid_close(_dobromirUsb);
        hid_exit();
    }

    return true;
}

bool UsbHandler::sendPing()
{
    struct report_ping report;
    init_report_ping(&report);
    return send(report);
}
