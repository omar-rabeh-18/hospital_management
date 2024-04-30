#ifndef APPOINMENTSWINDOW_H
#define APPOINMENTSWINDOW_H

#include <QDialog>

namespace Ui {
class AppoinmentsWindow;
}

class AppoinmentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppoinmentsWindow(QWidget *parent = nullptr);
    ~AppoinmentsWindow();

private:
    Ui::AppoinmentsWindow *ui;
};

#endif // APPOINMENTSWINDOW_H
