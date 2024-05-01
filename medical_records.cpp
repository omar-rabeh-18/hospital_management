#include "medical_records.h"
#include "ui_medical_records.h"

medical_records::medical_records(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::medical_records)
{
    ui->setupUi(this);

    // Updates gender variable
    connect(genderComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int index){
        gender = genderComboBox->itemText(index);
    });

    // Line edits signals become connected to corresponding slots
    connect(nameLineEdit, &QLineEdit::textChanged, this, &medical_records::nameLineEdit_textChanged);
    connect(ageLineEdit, &QLineEdit::textChanged, this, &medical_records::nameLineEdit_textChanged);
    connect(diseaseLineEdit, &QLineEdit::textChanged, this, &medical_records::nameLineEdit_textChanged);
    connect(testLineEdit, &QLineEdit::textChanged, this, &medical_records::nameLineEdit_textChanged);

    // Connects exportToFile slot to application exit signal
    connect(qApp, &QCoreApplication::aboutToQuit, this, &medical_records::exportToFile);


    // Extracts information from the file and puts it back into its designated space
    QFile file("data.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream input(&file);

        name = input.readLine();
        gender = input.readLine();
        age = input.readLine();
        disease = input.readLine();
        test = input.readLine();

        nameLineEdit->setText(name);
        int index = genderComboBox->findText(gender);
        if (index != -1) {
            genderComboBox->setCurrentIndex(index);
        }
        ageLineEdit->setText(age);
        diseaseLineEdit->setText(disease);
        testLineEdit->setText(test);

        file.close();
    } else {
        qDebug() << "Error occurred when opening file for reading";
    }



}

// Destuctor
medical_records::~medical_records()
{
    delete ui;
}

// Updates "name" variable when text changes
void medical_records::nameLineEdit_textChanged(const QString &text)
{
    name = text;
}

// Updates "age" variable when text changes
void medical_records::ageLineEdit_textChanged(const QString &text)
{
    age = text;
}

// Updates "disease" variable when text changes
void medical_records::diseaseLineEdit_textChanged(const QString &text)
{
    disease = text;
}

// Updates "test" variable when text changes
void medical_records::testLineEdit_textChanged(const QString &text)
{
    test = text;
}

// Exports data to file
void medical_records::exportToFile()
{
    QFile file("data.txt"); // Opens file for writing

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream output(&file);

        // Writes data
        output << nameLineEdit->text() << "\n";
        output << gender << "\n";
        output << ageLineEdit->text() << "\n";
        output << diseaseLineEdit->text() << "\n";
        output << testLineEdit->text() << "\n";

        file.close(); // closes file
    } else {
        qDebug() << "Error occurred when opening file for writing";
    }
}
