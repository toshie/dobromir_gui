#include "UsbHandlerQtAdapter.h"

#include "MainWindow.h"
#include "UsbHandler.h"
#include "ui_MainWindow.h"

#include <QDebug>

UsbHandlerQtAdapter::UsbHandlerQtAdapter(UsbHandler &handler,
                                         MainWindow& mainWindow) :
    QObject(nullptr),
    _handler(handler),
    _mainWindow(mainWindow),
    _ui(mainWindow.getUi())
{
    connect(_ui.btnConnect, SIGNAL(released()), this, SLOT(slotConnect()));
    connect(_ui.btnDisconnect, SIGNAL(released()), this, SLOT(slotDisconnect()));
    connect(_ui.btnPing, SIGNAL(released()), this, SLOT(slotPing()));
}

void UsbHandlerQtAdapter::slotConnect()
{
    _mainWindow.disableUsbCommunicationButtons();
    if (_handler.connect())
    {
        _mainWindow.setButtonsForStateConnected();
    }
    else
    {
        _mainWindow.setButtonsForStateDisconnected();
    }
}

void UsbHandlerQtAdapter::slotDisconnect()
{
    _mainWindow.disableUsbCommunicationButtons();
    if (_handler.disconnect())
    {
        _mainWindow.setButtonsForStateDisconnected();
    }
    else
    {
        _mainWindow.setButtonsForStateConnected();
    }
}

void UsbHandlerQtAdapter::slotPing()
{
    _mainWindow.disableUsbCommunicationButtons();
    _handler.sendPing();
    _mainWindow.setButtonsForStateConnected();
}
