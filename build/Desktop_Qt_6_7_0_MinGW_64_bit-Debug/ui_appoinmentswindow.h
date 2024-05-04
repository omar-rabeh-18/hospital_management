/********************************************************************************
** Form generated from reading UI file 'appoinmentswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINMENTSWINDOW_H
#define UI_APPOINMENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_AppoinmentsWindow
{
public:
    QTableView *tableView;
    QTableWidget *tableWidget;

    void setupUi(QDialog *AppoinmentsWindow)
    {
        if (AppoinmentsWindow->objectName().isEmpty())
            AppoinmentsWindow->setObjectName("AppoinmentsWindow");
        AppoinmentsWindow->resize(515, 485);
        tableView = new QTableView(AppoinmentsWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(110, 300, 256, 192));
        tableWidget = new QTableWidget(AppoinmentsWindow);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(130, 90, 256, 192));

        retranslateUi(AppoinmentsWindow);

        QMetaObject::connectSlotsByName(AppoinmentsWindow);
    } // setupUi

    void retranslateUi(QDialog *AppoinmentsWindow)
    {
        AppoinmentsWindow->setWindowTitle(QCoreApplication::translate("AppoinmentsWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppoinmentsWindow: public Ui_AppoinmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINMENTSWINDOW_H
