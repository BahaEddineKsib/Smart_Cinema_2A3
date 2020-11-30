#include "tab_tickets.h"
#include "ticket.h"
#include "database.h"
tab_tickets::tab_tickets(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_tickets::AddTicket()
{
    //ticket::ticket(int ID, int SHOWID, int PRICE, QString VIPSEAT, QString BUYEREMAIL, Ui::MainWindow *ui)
   // ticket* Ticket = new ticket(ui->TicketIdAdd->text().toInt(),
     //                           ui->TicketShowIdAdd->currentText().toInt(),
       //                         ui->TicketPriceAdd->text().toInt(),
         //                       ui->TicketVIPseatAdd->text(),
           //                     ui->TicketBuyerEmailAdd->text(),
             //                   ui);
    ticket* Ticket1 = new ticket(1,
                                741,
                                1,
                                "1",
                                "1",
                                ui);



    if(Ticket1->StoreInDatabase() == 1)
    {
        Ticket1->Display();
    }
}
