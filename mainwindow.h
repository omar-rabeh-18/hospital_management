#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void setRegistrationAdminPassword(QString& text);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAdminPushButtonClicked();

    void onUserPushButtonClicked();

    void onLoginPushButtonClicked();

    void onRegisterPushButtonClicked();

    void onAdminPasswordForRegistrationLineEditTextChanged(const QString &arg1);

    void onPasswordLineEditTextChanged(const QString &arg1);

    void onNewRegistryPushButtonClicked();

    void onUsernameLineEditTextChanged(const QString &arg1);

    void onConfirmPushButtonClicked();

    void restoreToDefault();

private:
    Ui::MainWindow *ui;

    bool adminClicked = false;
    bool registeringClient = false;
    bool adminPasswordCorrect = false;

    QString registeringAdminPassword = "-";
    QString adminPassword;
    QString password;
    QString username;

    QFile* usernamesFile;
    QFile* adminUsernamesFile;
    QFile* userPasswordsFile;
    QFile* adminPasswordsFile;
    QFile* theAdminPasswordFile;

    std::vector<QString> registerUsernames;
    std::vector<QString> adminUsernames;

    bool checkIfAdminPassword();
    bool checkIfAdminLogin();
    bool checkIfUserLogin();
    bool checkIfClientLogin(QFile* usernameFile, QFile* passwordFile);
    bool checkIfUsernameAlreadyExists();
    bool checkIfUsernameAlreadyExists(std::vector<QString> array, QFile* file);

    void initializeTheFiles();
    void hideAllWidgets();
    void enableAllWidgets();
    void connectAllWidgetsToSlots();
    void exportChangesToFiles();
};
#endif // MAINWINDOW_H
