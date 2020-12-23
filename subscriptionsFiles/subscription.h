#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H
#include <QString>
#include "ui_mainwindow.h"
#include "subscriptiongroupbox.h"

class subscription
{
public:
    subscription(int, QString, int, int, int, Ui::MainWindow *ui);
    void Display();
    int  StoreInDatabase();
    Ui::MainWindow *ui;

    int id;
    QString name;
    int price;
    int NumberOfDays;
    int FreeFood;
    SubscriptionGroupBox* DisplayBox;


};

#endif // SUBSCRIPTION_H
