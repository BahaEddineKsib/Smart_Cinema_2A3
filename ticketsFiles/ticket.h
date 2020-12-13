#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include "ui_mainwindow.h"
#include "ticketgroupbox.h"
class ticket
{
public:
    ticket(int, int, int, bool, QString, Ui::MainWindow *ui);
    void Display();
    int  StoreInDatabase();
    Ui::MainWindow *ui;
    int             id;
    int             ShowId;
    QString         VIPseat;
    QString         BuyerEmail;
    int             price;
    TicketGroupBox* DisplayBox =nullptr;

private slots:
    void on_FilmIdAdd_textChanged(const QString &arg1);
};

#endif // TICKET_H
