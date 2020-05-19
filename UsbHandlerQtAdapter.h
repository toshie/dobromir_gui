#ifndef USBHANDLERQTADAPTER_H
#define USBHANDLERQTADAPTER_H

#include <QObject>

namespace Ui { class MainWindow; }
class MainWindow;
class UsbHandler;
class UsbHandlerQtAdapter : public QObject
{
    Q_OBJECT
public:
    UsbHandlerQtAdapter(UsbHandler& handler, MainWindow& mainWindow);

public slots:
    void slotConnect();
    void slotDisconnect();
    void slotPing();

private:
    UsbHandler& _handler;
    MainWindow& _mainWindow;
    Ui::MainWindow& _ui;
};

#endif // USBHANDLERQTADAPTER_H
