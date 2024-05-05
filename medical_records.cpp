#include "medical_records.h"
#include "ui_medical_records.h"

medical_records::medical_records(const QString& username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::medical_records)
    , m_username(username)
{
    ui->setupUi(this);

    // Initialize genderComboBox
    genderComboBox = ui->genderComboBox;

    // Connect signal to update gender variable
    connect(genderComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &medical_records::on_genderComboBox_currentIndexChanged);

    // Load medical records for the logged-in user
    loadMedicalRecords(username);

    // Connect save button to save slot
    connect(ui->saveButton, &QPushButton::clicked, this, &medical_records::onSaveButtonClicked);

    // Connect export function to aboutToQuit signal
    connect(qApp, &QCoreApplication::aboutToQuit, this, &medical_records::exportRecordsToFile);
    connect(this, &medical_records::aboutToClose, this, &medical_records::exportRecordsToFile);

    connect(ui->nameLineEdit, &QLineEdit::textChanged, this, &medical_records::removeSpaces);
    connect(ui->ageLineEdit, &QLineEdit::textChanged, this, &medical_records::removeSpaces);
    connect(ui->diseaseLineEdit, &QLineEdit::textChanged, this, &medical_records::removeSpaces);
    connect(ui->testLineEdit, &QLineEdit::textChanged, this, &medical_records::removeSpaces);
}

medical_records::~medical_records()
{
    delete ui;
}

void medical_records::onSaveButtonClicked()
{
    m_records.clear();
    // Retrieve information from line edits and combo box
    QString name = ui->nameLineEdit->text();
    QString gender = ui->genderComboBox->currentText();
    QString age = ui->ageLineEdit->text();
    QString disease = ui->diseaseLineEdit->text();
    QString test = ui->testLineEdit->text();

    // Combine all information into a single string with spaces separating them
    QString record = m_username + " " + name + " " + gender + " " + age + " " + disease + " " + test;

    // Check if the username already exists in the records vector
    bool usernameExists = false;
    for (int i = 0; i < m_records.size(); ++i) {
        QString existingRecord = m_records.at(i);
        QStringList recordParts = existingRecord.split(" ");
        if (recordParts.first() == m_username) {
            // Replace the existing record with the new one
            m_records.replace(i, record);
            usernameExists = true;
            break;
        }
    }

    // If the username doesn't exist, add the new record to the vector
    if (!usernameExists) {
        m_records.push_back(record);
    }
}


void medical_records::exportRecordsToFile()
{


    QFile file("medical_records.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream output(&file);
        for (const QString& record : m_records)
        {

            output << record << "\n";
        }
        file.close();
        qDebug() << "Records exported successfully!";
    }
    else
    {
        qDebug() << "Error occurred when opening file for writing";
    }
}



void medical_records::loadMedicalRecords(const QString& username)
{
    // Clear existing records for the user
    m_records.clear();

    QString filePath = QCoreApplication::applicationDirPath() + "/medical_records.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream input(&file);
        while (!input.atEnd())
        {
            QString record = input.readLine();
            QStringList recordParts = record.split(" "); // Split the record into parts
            QString recordUsername = recordParts.first(); // Get the username
            if (recordUsername == username) // Check if the record belongs to the logged-in user
            {
                // Extract medical record details
                QString name = recordParts.value(1);
                QString gender = recordParts.value(2);
                QString age = recordParts.value(3);
                QString disease = recordParts.value(4);
                QString test = recordParts.value(5);

                // Populate line edits and combo box with medical record details
                ui->nameLineEdit->setText(name);
                int genderIndex = ui->genderComboBox->findText(gender);
                if (genderIndex != -1) {
                    ui->genderComboBox->setCurrentIndex(genderIndex);
                }
                ui->ageLineEdit->setText(age);
                ui->diseaseLineEdit->setText(disease);
                ui->testLineEdit->setText(test);

                // Add the record to the records vector
                m_records.push_back(record);
            }
        }
        file.close();
    }
    else
    {
        qDebug() << "Error occurred when opening file for reading";
    }
}



void medical_records::on_genderComboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index); // Suppress unused variable warning
    // You can add additional functionality here if needed
}

void medical_records::closeEvent(QCloseEvent *event)
{
    // Emit the aboutToClose signal when the window is closed
    emit aboutToClose();
    // Call the parent class closeEvent to handle the event
    QDialog::closeEvent(event);
}

void medical_records::removeSpaces(const QString& text)
{
    QLineEdit *lineEdit = qobject_cast<QLineEdit*>(sender());
    if (lineEdit) {
        QString newText = text;
        newText.remove(' '); // Remove all spaces from the text
        lineEdit->setText(newText); // Set the line edit text to the modified text without spaces
    }
}


