#ifndef TAB_TICKETS_H
#define TAB_TICKETS_H
#include "ui_mainwindow.h"

class tab_tickets
{
public:
    tab_tickets(Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void DisplayAllTickets();
    void UndisplayAllTickets();
    void AddTicket();
    //void SearchTickets();
};

#endif // TAB_TICKETS_H
