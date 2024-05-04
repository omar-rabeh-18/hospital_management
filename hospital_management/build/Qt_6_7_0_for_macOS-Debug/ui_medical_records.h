/********************************************************************************
** Form generated from reading UI file 'medical_records.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICAL_RECORDS_H
#define UI_MEDICAL_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_medical_records
{
public:
    QLabel *nameLabel;
    QLabel *genderLabel;
    QLabel *ageLabel;
    QLabel *diseaseLabel;
    QLabel *testLabel;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QLineEdit *nameLineEdit;
    QLineEdit *ageLineEdit;
    QLineEdit *diseaseLineEdit;
    QLineEdit *testLineEdit;
    QComboBox *genderComboBox;

    void setupUi(QDialog *medical_records)
    {
        if (medical_records->objectName().isEmpty())
            medical_records->setObjectName("medical_records");
        medical_records->resize(528, 384);
        nameLabel = new QLabel(medical_records);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(60, 80, 71, 21));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        nameLabel->setFont(font);
        genderLabel = new QLabel(medical_records);
        genderLabel->setObjectName("genderLabel");
        genderLabel->setGeometry(QRect(60, 120, 71, 21));
        genderLabel->setFont(font);
        ageLabel = new QLabel(medical_records);
        ageLabel->setObjectName("ageLabel");
        ageLabel->setGeometry(QRect(60, 160, 71, 31));
        ageLabel->setFont(font);
        diseaseLabel = new QLabel(medical_records);
        diseaseLabel->setObjectName("diseaseLabel");
        diseaseLabel->setGeometry(QRect(60, 210, 81, 21));
        diseaseLabel->setFont(font);
        testLabel = new QLabel(medical_records);
        testLabel->setObjectName("testLabel");
        testLabel->setGeometry(QRect(60, 260, 71, 21));
        testLabel->setFont(font);
        line = new QFrame(medical_records);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 100, 351, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(medical_records);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 140, 351, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(medical_records);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(0, 190, 351, 16));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(medical_records);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 240, 351, 16));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(medical_records);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(0, 290, 351, 16));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        nameLineEdit = new QLineEdit(medical_records);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(130, 80, 221, 21));
        ageLineEdit = new QLineEdit(medical_records);
        ageLineEdit->setObjectName("ageLineEdit");
        ageLineEdit->setGeometry(QRect(110, 165, 241, 21));
        diseaseLineEdit = new QLineEdit(medical_records);
        diseaseLineEdit->setObjectName("diseaseLineEdit");
        diseaseLineEdit->setGeometry(QRect(140, 210, 211, 21));
        testLineEdit = new QLineEdit(medical_records);
        testLineEdit->setObjectName("testLineEdit");
        testLineEdit->setGeometry(QRect(110, 260, 241, 21));
        genderComboBox = new QComboBox(medical_records);
        genderComboBox->addItem(QString());
        genderComboBox->addItem(QString());
        genderComboBox->setObjectName("genderComboBox");
        genderComboBox->setGeometry(QRect(140, 120, 211, 20));

        retranslateUi(medical_records);

        QMetaObject::connectSlotsByName(medical_records);
    } // setupUi

    void retranslateUi(QDialog *medical_records)
    {
        medical_records->setWindowTitle(QCoreApplication::translate("medical_records", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("medical_records", "Name:", nullptr));
        genderLabel->setText(QCoreApplication::translate("medical_records", "Gender:", nullptr));
        ageLabel->setText(QCoreApplication::translate("medical_records", "Age:", nullptr));
        diseaseLabel->setText(QCoreApplication::translate("medical_records", "Disease:", nullptr));
        testLabel->setText(QCoreApplication::translate("medical_records", "Test:", nullptr));
        genderComboBox->setItemText(0, QCoreApplication::translate("medical_records", "Male", nullptr));
        genderComboBox->setItemText(1, QCoreApplication::translate("medical_records", "Female", nullptr));

    } // retranslateUi

};

namespace Ui {
    class medical_records: public Ui_medical_records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICAL_RECORDS_H
