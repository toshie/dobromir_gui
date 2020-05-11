#ifndef USBHANDLER_H
#define USBHANDLER_H


class UsbHandler
{
public:
    UsbHandler();

    bool connect();
    bool send();
};

#endif // USBHANDLER_H
