#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QSqlDatabase>
#include <QtSql>

#include "ui_mainwindow.h"

class loginpage
{
public:
    loginpage(Ui::MainWindow *ui);
    Ui::MainWindow *ui;

    void login();


};

#endif // LOGINPAGE_H
