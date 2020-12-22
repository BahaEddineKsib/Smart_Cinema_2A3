#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include "ui_mainwindow.h"
#include "clientgroupbox.h"

class client
{
public:
    //CLIENTS(ID, EMAIL, NAME, SUBS#, SUBS_DATE)
    client(int, QString, QString, int, QDate, Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    int StoreInDatabase();
    void Display();
    int            id;
    QString        name;
    QString        email;
    int            SubscriptionId;
    QDate        SubscriptionDate;
    ClientGroupBox* DisplayBox;
};

#endif // CLIENT_H
