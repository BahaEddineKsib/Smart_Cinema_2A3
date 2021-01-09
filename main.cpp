#include "mainwindow.h"
#include <database.h>
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;



    if(c.CreateConnection())
    {

        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                         QObject::tr("connection successful.\n"
                                                     "Click cancel to exit."),
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                         QObject::tr("connection failed.\n"
                                                     "Click cancel to exit."),
                                 QMessageBox::Cancel);
    }
    MainWindow w;
   w.show();
    return a.exec();
}
