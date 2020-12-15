#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QVector>
#include "ui_mainwindow.h"
#include "clientgroupbox.h"
class client
{
public:
    client();
    client(QString, QString, QString,Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    int StoreInDatabase();
    void Display();
    QString id;
    QString name;
    QString Email;
    clientGroupBox* DisplayBox;
};
#endif // CLIENT_H
