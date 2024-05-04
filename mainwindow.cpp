#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include "medical_records.h"
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect all widgets in the scene to their corresponding signals
    connectAllWidgetsToSlots();

    //Set up the main window and the main view
    restoreToDefault();

    //Create the databases
    initializeTheFiles();

    // Connects export changes to application quit
    connect(qApp, &QCoreApplication::aboutToQuit, this, &MainWindow::exportChangesToFiles);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_pushButton_clicked()
// {
//     medical_records a;
//     a.setModal(true);
//     a.exec();
// }


void MainWindow::onAdminPushButtonClicked()
{
    //hide the user button
    ui->userPushButton->hide();

    //show the login and register buttons
    ui->loginPushButton->show();
    ui->registerPushButton->show();

    //Disable the admin button from being clicked
    ui->adminPushButton->setEnabled(false);

    //admin clicked is true
    adminClicked = true;
}


void MainWindow::onUserPushButtonClicked()
{
    //hide the admin button
    ui->adminPushButton->hide();

    //show the login and register buttons
    ui->loginPushButton->show();
    ui->registerPushButton->show();

    //disable the user button from being clicked
    ui->userPushButton->setEnabled(false);
}


void MainWindow::onLoginPushButtonClicked()
{
    //hide the register button
    ui->registerPushButton->hide();

    //show the username and password line edits and the confirm button
    ui->usernameLineEdit->show();
    ui->passwordLineEdit->show();
    ui->confirmPushButton->show();

    //Note for new users
    ui->passwordLineEdit->setPlaceholderText("Skip if you have no password...");

    //disable the login button
    ui->loginPushButton->setEnabled(false);
}


void MainWindow::onRegisterPushButtonClicked()
{
    //hide the login button and show the confirm button
    ui->loginPushButton->hide();
    ui->confirmPushButton->show();

    //If an admin tries to register, ask for the admin passowrd
    if(adminClicked){
        ui->adminPasswordForRegistrationLineEdit->show();
    }
    else{
        ui->usernameLineEdit->show();
    }

    //mark this client as a registering (as opposed to logging in) client
    registeringClient = true;

    //disable this button
    ui->registerPushButton->setEnabled(false);
}


void MainWindow::onAdminPasswordForRegistrationLineEditTextChanged(const QString &text)
{
    adminPassword = text; //set the admin password
}

void MainWindow::onUsernameLineEditTextChanged(const QString &text)
{
    username = text; //set the register username
}

void MainWindow::onPasswordLineEditTextChanged(const QString &text)
{
    password = text; //set the password
}


void MainWindow::onConfirmPushButtonClicked()
{
    if(adminClicked){
        if(registeringClient){
            //If the admin password is correct and the client has entered a username, then registration successful
            if(adminPasswordCorrect && username!=""){
                if(!checkIfUsernameAlreadyExists()){
                    adminUsernames.push_back(username);
                    ui->confirmPushButton->setEnabled(false);
                    hideAllWidgets();
                    ui->registrationSuccesfulLabel->show();
                    ui->newRegistryPushButton->hide();
                    QTimer::singleShot(2500, this, &MainWindow::restoreToDefault);
                }
                //Username exists, so ask for another username
                else{
                    ui->wrongUsernameOrPasswordLabel->show();
                    ui->wrongUsernameOrPasswordLabel->setText("username already exists..");
                    ui->usernameLineEdit->setText("");
                }
            }
            else{
                //Check the admin password, if correct continue the registration process
                if(checkIfAdminPassword()){
                    ui->wrongAdminPasswordLabel->hide();
                    ui->adminPasswordForRegistrationLineEdit->setEnabled(false);
                    ui->adminPasswordForRegistrationLineEdit->hide();
                    ui->usernameLineEdit->show();
                }
                else{
                    //the admin password entered is wrong
                    ui->wrongAdminPasswordLabel->show();
                    ui->adminPasswordForRegistrationLineEdit->setText("");
                }
            }
        }
        //loggin in
        else{
            if(checkIfAdminLogin()){
                //the admin credentials are correct, so continue..
                std::cout<<"Admin credentials correct, should show the new window .... ..." << std::endl;
            }
            else{
                ui->wrongUsernameOrPasswordLabel->show();
                ui->usernameLineEdit->setText("");
                ui->passwordLineEdit->setText("");
            }
        }
    }

    else{
        //If the client is registring, just register and show the successful registration
        if(registeringClient){
            if(!checkIfUsernameAlreadyExists()){
                ui->confirmPushButton->setEnabled(false);
                registerUsernames.push_back(username);
                hideAllWidgets();
                ui->registrationSuccesfulLabel->show();
                ui->newRegistryPushButton->hide();
                QTimer::singleShot(2500, this, &MainWindow::restoreToDefault);
            }
            else {
                ui->wrongUsernameOrPasswordLabel->show();
                ui->wrongUsernameOrPasswordLabel->setText("username already exists..");
                ui->usernameLineEdit->setText("");

            }
        }
        else{
            //check if the user is in the database
            if(checkIfUserLogin()){
                //then continue as the user is actually a user
                std::cout<<"User credentials correct, should show the new window .... ..." << std::endl;
            }
            else{
                ui->wrongUsernameOrPasswordLabel->show();
                ui->usernameLineEdit->setText("");
                ui->passwordLineEdit->setText("");
            }
        }
    }


}

void MainWindow::onNewRegistryPushButtonClicked()
{
    restoreToDefault(); //Restore the main window
}


bool MainWindow::checkIfAdminPassword(){
    //Open the file...
    if(theAdminPasswordFile->open(QIODevice::ReadOnly)){
        QString currentAdminPassword;

        //Input the first line in the file (the password basically)
        QTextStream input(theAdminPasswordFile);
        currentAdminPassword = input.readLine().trimmed();//read the first line for the password and remove any whitespace
        theAdminPasswordFile->close(); //close the file

        if(adminPassword == currentAdminPassword){ //if the inputted admin password is correct then return true
            adminPasswordCorrect = true;
            return true;
        }

    }
    return false;
}

bool MainWindow::checkIfAdminLogin(){
    if(!adminClicked || registeringClient){
        return false;
    }
    return checkIfClientLogin(adminUsernamesFile, adminPasswordsFile);
}

bool MainWindow::checkIfUserLogin(){
    if(adminClicked || registeringClient){
        return false;
    }
    return checkIfClientLogin(usernamesFile, userPasswordsFile);
}

bool MainWindow::checkIfClientLogin(QFile* usernameFile, QFile* passwordFile){

    bool usernameFound = false;
    int countULines = 0;
    if(usernameFile->open(QIODevice::ReadOnly)){
        QTextStream input(usernameFile);
        QString currentUsername;
        while(!input.atEnd()){
            currentUsername = input.readLine();
            if(username == currentUsername){
                usernameFound = true;
                break;
            }
            countULines++;
        }
        usernameFile->close();
    }

    if(!usernameFound)
        return false;

    int countPLines = 0;
    if(passwordFile->open(QIODevice::ReadOnly)){
        QTextStream input(passwordFile);
        QString currentPassword;
        while(countPLines < countULines){
            input.readLine();
            countPLines++;
        }
        currentPassword = input.readLine();
        if(password==currentPassword || (currentPassword=="-" && password=="")){
            passwordFile->close();
            return true;
        }
        passwordFile->close();
    }
    return false;
}

bool MainWindow::checkIfUsernameAlreadyExists(){
    if(adminClicked){
        return checkIfUsernameAlreadyExists(adminUsernames, adminUsernamesFile);
    }
    else{
        return checkIfUsernameAlreadyExists(registerUsernames, usernamesFile);
    }
}

bool MainWindow::checkIfUsernameAlreadyExists(std::vector<QString> array, QFile* file){
    for(size_t i = 0; i < array.size(); i++){
        if(array[i] == username){
            return true;
        }
    }
    QString currentUsername;
    if(file->open(QIODevice::ReadOnly)){
        QTextStream input(file);
        while(!input.atEnd()){
            currentUsername = input.readLine();
            if(username==currentUsername){
                file->close();
                return true;
            }
        }
        file->close();
    }
    return false;
}

//Sets the admin registration password to the specified text
void MainWindow::setRegistrationAdminPassword(QString& text){
    registeringAdminPassword = text;
}

//Hides all widgets from view
void MainWindow::hideAllWidgets(){
    ui->userPushButton->hide();
    ui->adminPushButton->hide();
    ui->confirmPushButton->hide();
    ui->loginPushButton->hide();
    ui->registerPushButton->hide();
    ui->adminPasswordForRegistrationLineEdit->hide();
    ui->usernameLineEdit->hide();
    ui->passwordLineEdit->hide();
    ui->wrongUsernameOrPasswordLabel->hide();
    ui->wrongAdminPasswordLabel->hide();
    ui->registrationSuccesfulLabel->hide();
}

//Enables all widgets
void MainWindow::enableAllWidgets(){
    ui->userPushButton->setEnabled(true);
    ui->adminPushButton->setEnabled(true);
    ui->confirmPushButton->setEnabled(true);
    ui->loginPushButton->setEnabled(true);
    ui->registerPushButton->setEnabled(true);
    ui->adminPasswordForRegistrationLineEdit->setEnabled(true);
    ui->usernameLineEdit->setEnabled(true);
    ui->passwordLineEdit->setEnabled(true);
    ui->wrongUsernameOrPasswordLabel->setEnabled(true);
    ui->wrongAdminPasswordLabel->setEnabled(true);
    ui->registrationSuccesfulLabel->setEnabled(true);
}

//Connects all widgets to their appropriate slots
void MainWindow::connectAllWidgetsToSlots(){
    ui->adminPushButton->connect(ui->adminPushButton, &QPushButton::clicked, this, &MainWindow::onAdminPushButtonClicked);
    ui->userPushButton->connect(ui->userPushButton, &QPushButton::clicked, this, &MainWindow::onUserPushButtonClicked);
    ui->loginPushButton->connect(ui->loginPushButton, &QPushButton::clicked, this, &MainWindow::onLoginPushButtonClicked);
    ui->registerPushButton->connect(ui->registerPushButton, &QPushButton::clicked, this, &MainWindow::onRegisterPushButtonClicked);
    ui->adminPasswordForRegistrationLineEdit->connect(ui->adminPasswordForRegistrationLineEdit, &QLineEdit::textChanged,
                                                      this, &MainWindow::onAdminPasswordForRegistrationLineEditTextChanged);
    ui->usernameLineEdit->connect(ui->usernameLineEdit, &QLineEdit::textChanged, this, &MainWindow::onUsernameLineEditTextChanged);
    ui->passwordLineEdit->connect(ui->passwordLineEdit, &QLineEdit::textChanged, this, &MainWindow::onPasswordLineEditTextChanged);
    ui->confirmPushButton->connect(ui->confirmPushButton, &QPushButton::clicked, this, &MainWindow::onConfirmPushButtonClicked);
    ui->newRegistryPushButton->connect(ui->newRegistryPushButton, &QPushButton::clicked, this, &MainWindow::onNewRegistryPushButtonClicked);
}

//Restores the main window to default
void MainWindow::restoreToDefault(){
    hideAllWidgets();
    adminClicked= false;
    registeringClient = false;
    adminPasswordCorrect = false;

    ui->passwordLineEdit->setText("");
    ui->usernameLineEdit->setText("");
    ui->adminPasswordForRegistrationLineEdit->setText("");
    ui->passwordLineEdit->setPlaceholderText("password");
    ui->wrongUsernameOrPasswordLabel->setText("wrong username or password..!");

    ui->adminPushButton->show();
    ui->userPushButton->show();
    ui->newRegistryPushButton->show();

    enableAllWidgets();
}

//Initializes all the files
void MainWindow::initializeTheFiles(){
    //Instantiate all the individual files
    usernamesFile = new QFile("usernamesFile.txt");
    adminUsernamesFile = new QFile("adminUsernamesFile.txt");
    userPasswordsFile = new QFile("userPasswordsFile.txt");
    adminPasswordsFile = new QFile("adminPasswordsFile.txt");
    theAdminPasswordFile = new QFile("theAdminPasswordFile.txt");

    //If the file is not already created
    if(theAdminPasswordFile->open(QIODevice::NewOnly)){
        QTextStream output(theAdminPasswordFile);
        output<< "thegreatestteamonearth"; //set this as the default password
        theAdminPasswordFile->close();
    }

}

//Exports all changes to files, which are now reflected in new sessions
void MainWindow::exportChangesToFiles(){

    //Update all the registered usernames
    //Set default passwords to -
    if(usernamesFile->open(QIODevice::Append) && userPasswordsFile->open(QIODevice::Append)){
        QTextStream outputUsernames(usernamesFile);
        QTextStream outputPasswords(userPasswordsFile);
        for(size_t i = 0; i < registerUsernames.size(); i++){
            outputUsernames << registerUsernames[i] << "\n";
            outputPasswords << "-\n";
        }
        usernamesFile->close();
        userPasswordsFile->close();
    }

    //Update all the registered admins
    //Set default passwords to -
    if(adminUsernamesFile->open(QIODevice::Append) && adminPasswordsFile->open(QIODevice::Append)){
        QTextStream outputUsernames(adminUsernamesFile);
        QTextStream outputPasswords(adminPasswordsFile);
        for(size_t i = 0; i < adminUsernames.size(); i++){
            outputUsernames << adminUsernames[i] << "\n";
            outputPasswords << "-\n";
        }
        adminUsernamesFile->close();
        adminPasswordsFile->close();
    }

    //Truncates over the existing admin registration password file if a new registration admin password is submitted
    if(registeringAdminPassword!="-"){
        if(theAdminPasswordFile->open(QIODevice::Truncate)){
            QTextStream output(theAdminPasswordFile);
            output<< registeringAdminPassword;
            theAdminPasswordFile->close();
    }
    }
}




