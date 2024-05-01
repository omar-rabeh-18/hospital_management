#ifndef MEDICAL_RECORDS_H
#define MEDICAL_RECORDS_H

#include <QLineEdit>
#include <QDialog>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include "ui_medical_records.h"

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
    void nameLineEdit_textChanged(const QString &text);
    void ageLineEdit_textChanged(const QString &text);
    void diseaseLineEdit_textChanged(const QString &text);
    void testLineEdit_textChanged(const QString &text);
    void exportToFile();

private:

    QString name;
    QString gender;
    QString age;
    QString disease;
    QString test;



    Ui::medical_records *ui;
};

#endif // MEDICAL_RECORDS_H
