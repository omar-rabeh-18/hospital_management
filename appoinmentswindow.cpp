#include "appoinmentswindow.h"
#include "ui_appoinmentswindow.h"

AppoinmentsWindow::AppoinmentsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AppoinmentsWindow)
{
    ui->setupUi(this);
}

AppoinmentsWindow::~AppoinmentsWindow()
{
    delete ui;
}
