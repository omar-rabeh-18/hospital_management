#ifndef MEDICAL_RECORDS_H
#define MEDICAL_RECORDS_H

#include <QDialog>
#include <QComboBox>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class medical_records; }
QT_END_NAMESPACE

class medical_records : public QDialog
{
    Q_OBJECT

public:
    medical_records(const QString& username, QWidget *parent = nullptr);
    ~medical_records();

signals:
    void aboutToClose(); // Signal emitted when the window is about to close


protected:
    void closeEvent(QCloseEvent *event) override;


private slots:
    void onSaveButtonClicked();
    void exportRecordsToFile();
    void loadMedicalRecords(const QString& username);
    void on_genderComboBox_currentIndexChanged(int index);
    void removeSpaces(const QString& text);

private:
    Ui::medical_records *ui;
    QString m_username;
    QComboBox *genderComboBox;
    QVector<QString> m_records;


};

#endif // MEDICAL_RECORDS_H
