/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *adminPushButton;
    QPushButton *userPushButton;
    QPushButton *loginPushButton;
    QPushButton *registerPushButton;
    QLineEdit *adminPasswordForRegistrationLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *confirmPushButton;
    QPushButton *newRegistryPushButton;
    QLabel *wrongAdminPasswordLabel;
    QLabel *wrongUsernameOrPasswordLabel;
    QLabel *registrationSuccesfulLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        adminPushButton = new QPushButton(centralwidget);
        adminPushButton->setObjectName("adminPushButton");
        adminPushButton->setGeometry(QRect(170, 100, 181, 51));
        userPushButton = new QPushButton(centralwidget);
        userPushButton->setObjectName("userPushButton");
        userPushButton->setGeometry(QRect(400, 100, 181, 51));
        loginPushButton = new QPushButton(centralwidget);
        loginPushButton->setObjectName("loginPushButton");
        loginPushButton->setEnabled(true);
        loginPushButton->setGeometry(QRect(190, 170, 131, 51));
        registerPushButton = new QPushButton(centralwidget);
        registerPushButton->setObjectName("registerPushButton");
        registerPushButton->setEnabled(true);
        registerPushButton->setGeometry(QRect(420, 170, 141, 51));
        adminPasswordForRegistrationLineEdit = new QLineEdit(centralwidget);
        adminPasswordForRegistrationLineEdit->setObjectName("adminPasswordForRegistrationLineEdit");
        adminPasswordForRegistrationLineEdit->setEnabled(true);
        adminPasswordForRegistrationLineEdit->setGeometry(QRect(190, 230, 181, 21));
        adminPasswordForRegistrationLineEdit->setEchoMode(QLineEdit::Password);
        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setEnabled(true);
        usernameLineEdit->setGeometry(QRect(190, 260, 181, 21));
        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEnabled(true);
        passwordLineEdit->setGeometry(QRect(420, 260, 201, 21));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        confirmPushButton = new QPushButton(centralwidget);
        confirmPushButton->setObjectName("confirmPushButton");
        confirmPushButton->setEnabled(true);
        confirmPushButton->setGeometry(QRect(330, 330, 101, 41));
        newRegistryPushButton = new QPushButton(centralwidget);
        newRegistryPushButton->setObjectName("newRegistryPushButton");
        newRegistryPushButton->setGeometry(QRect(0, 530, 101, 31));
        wrongAdminPasswordLabel = new QLabel(centralwidget);
        wrongAdminPasswordLabel->setObjectName("wrongAdminPasswordLabel");
        wrongAdminPasswordLabel->setGeometry(QRect(410, 230, 151, 16));
        wrongAdminPasswordLabel->setStyleSheet(QString::fromUtf8("color: red"));
        wrongUsernameOrPasswordLabel = new QLabel(centralwidget);
        wrongUsernameOrPasswordLabel->setObjectName("wrongUsernameOrPasswordLabel");
        wrongUsernameOrPasswordLabel->setGeometry(QRect(190, 290, 251, 16));
        wrongUsernameOrPasswordLabel->setStyleSheet(QString::fromUtf8("color: red"));
        registrationSuccesfulLabel = new QLabel(centralwidget);
        registrationSuccesfulLabel->setObjectName("registrationSuccesfulLabel");
        registrationSuccesfulLabel->setGeometry(QRect(70, 220, 651, 61));
        QFont font;
        font.setPointSize(14);
        registrationSuccesfulLabel->setFont(font);
        registrationSuccesfulLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        adminPushButton->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        userPushButton->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        loginPushButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        registerPushButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        adminPasswordForRegistrationLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "type the admin password", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "username", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "password", nullptr));
        confirmPushButton->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        newRegistryPushButton->setText(QCoreApplication::translate("MainWindow", "New Registry", nullptr));
        wrongAdminPasswordLabel->setText(QCoreApplication::translate("MainWindow", "wrong password..!", nullptr));
        wrongUsernameOrPasswordLabel->setText(QCoreApplication::translate("MainWindow", "wrong username or password..!", nullptr));
        registrationSuccesfulLabel->setText(QCoreApplication::translate("MainWindow", "Registration successful. You can login after closing the session (restarting).\n"
" A new registry will open. ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
