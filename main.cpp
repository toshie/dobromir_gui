#include "MainWindow.h"
#include "UsbHandler.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    UsbHandler usbHandler;
    usbHandler.connect();


    return a.exec();
}
