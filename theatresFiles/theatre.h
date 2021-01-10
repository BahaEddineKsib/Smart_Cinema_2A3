#ifndef THEATRE_H
#define THEATRE_H

#include <ui_mainwindow.h>
#include "theatregroupbox.h"

class theatre
{
public:
    theatre(int, QString, int, int, Ui::MainWindow *ui);
    void Display();
    int  StoreInDatabase();
    Ui::MainWindow *ui;
    int             id;
    QString       name;
    int          seats;
    int      VIP_Seats;
    TheatreGroupBox* DisplayBox =nullptr;
};

#endif // THEATRE_H
