#ifndef subscription_H
#define subscription_H
#include <QString>
#include <QVector>
#include "ui_mainwindow.h"
#include "subscriptiongroupbox.h"
class subscription
{
public:
    subscription();
    subscription(QString, QString, QString,Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    int StoreInDatabase();
    void Display();
    QString id;
    QString name;
    QString price;
    subscriptionGroupBox* DisplayBox;
private slots:
    void on_subscriptionAddButton_2_clicked();
    void on_subscriptionclient_clicked();
    void on_Searchclient_clicked();
};
#endif // subscription_H
