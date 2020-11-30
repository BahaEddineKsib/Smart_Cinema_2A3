#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include "ui_mainwindow.h"
#include "ticketgroupbox.h"
class ticket
{
public:
    ticket(int, int, int, QString, QString, Ui::MainWindow *ui);
    int StoreInDatabase();
    void Display();
    Ui::MainWindow *ui;
    int             id;
    int             ShowId;
    QString         VIPseat;
    QString         BuyerEmail;
    int             price;
    TicketGroupBox* DisplayBox;

};

#endif // TICKET_H
