#ifndef MEDICAL_RECORDS_H
#define MEDICAL_RECORDS_H


#include <QLineEdit>
#include <QDialog>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include "ui_medical_records.h"
#include <QComboBox>



namespace Ui {
class medical_records;
}

class medical_records : public QDialog, private Ui::medical_records
{
    Q_OBJECT

public:
    explicit medical_records(QWidget *parent = nullptr);
    ~medical_records();

private slots:
    void on_nameLineEdit_textChanged(const QString &text);
    void on_genderComboBox_currentIndexChanged(int index); // Slot for gender combo box
    void on_ageLineEdit_textChanged(const QString &text);
    void on_diseaseLineEdit_textChanged(const QString &text);
    void on_testLineEdit_textChanged(const QString &text);
    void exportToFile();




private:

    QString name;
    QString gender;
    QString age;
    QString disease;
    QString test;

    QComboBox *genderComboBox;

    Ui::medical_records *ui;
};

#endif // MEDICAL_RECORDS_H
