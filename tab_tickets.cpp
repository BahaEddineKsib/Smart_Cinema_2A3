#include "tab_tickets.h"
#include "ticket.h"
#include "database.h"
#include <QMessageBox>
tab_tickets::tab_tickets(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_tickets::DisplayAllTickets()
{
    qDebug() << "DISPLAY ALL MOVIES";
    ticket *TICKET;
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  tickets");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {
                //ticket::ticket(int ID, int SHOWID, int PRICE, bool VIPSEAT, QString BUYEREMAIL, Ui::MainWindow *ui)
                bool VIP = false;
                if(qry.value(qry.record().indexOf("vip_seat")).toInt() == 1)
                {
                    VIP = true;
                }
                TICKET = new ticket(qry.value(qry.record().indexOf("id")).toInt(),
                                  qry.value(qry.record().indexOf  ("show_id")).toInt(),
                                  qry.value(qry.record().indexOf  ("price")).toInt(),
                                  VIP,
                                  qry.value(qry.record().indexOf  ("buyer_email")).toString(),
                                  ui);
                TICKET->Display();
            }
        }
    }
}


void tab_tickets::AddTicket()
{
    //ticket::ticket(int ID, int SHOWID, int PRICE, QString VIPSEAT, QString BUYEREMAIL, Ui::MainWindow *ui)
    ticket* Ticket = new ticket(ui->TicketIdAdd->text().toInt(),
                                ui->TicketShowIdAdd->text().toInt(),
                                ui->TicketPriceAdd->text().toInt(),
                                ui->TicketVIPseatAdd->isChecked(),
                                ui->TicketBuyerEmailAdd->text(),
                                ui);

    if(Ticket->StoreInDatabase() == 1)
    {
        Ticket->Display();
    }
}
