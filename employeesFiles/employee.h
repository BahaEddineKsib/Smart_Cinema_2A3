#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include "ui_mainwindow.h"
#include "employeegroupbox.h"
class employee
{
public:
    employee(int, QString, QString, QString, QString, QString, QString, Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    int StoreInDatabase();
    void Display();
    int id;
    QString name;
    QString email;
    QString username;
    QString password;
    QString role;
    QString ImageLink;
    EmployeeGroupBox* DisplayBox;
private slots:
};
#endif // EMPLOYEE_H
