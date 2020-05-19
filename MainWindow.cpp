#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::disableUsbCommunicationButtons()
{
    ui->btnPing->setEnabled(false);
    ui->btnConnect->setEnabled(false);
    ui->btnDisconnect->setEnabled(false);
}

void MainWindow::enableUsbCommunicationButtons()
{
    ui->btnPing->setEnabled(true);
    ui->btnConnect->setEnabled(true);
    ui->btnDisconnect->setEnabled(true);
}

void MainWindow::setButtonsForStateConnected()
{
    enableUsbCommunicationButtons();
    ui->btnConnect->setEnabled(false);
}

void MainWindow::setButtonsForStateDisconnected()
{
    disableUsbCommunicationButtons();
    ui->btnConnect->setEnabled(true);
}
