#include "MainWindow.h"
#include "UsbHandler.h"
#include "UsbHandlerQtAdapter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    UsbHandler usbHandler;
    UsbHandlerQtAdapter usbHandlerAdapter(usbHandler, w);

    return a.exec();
}
