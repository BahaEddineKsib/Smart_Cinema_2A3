#include "ticket.h"
#include "database.h"
#include <QMessageBox>
ticket::ticket(int ID, int SHOWID, int PRICE, bool VIPSEAT, QString BUYEREMAIL, Ui::MainWindow *ui)
{
    this->ui   = ui;
    id         = ID;
    ShowId     = SHOWID;
    if(VIPSEAT)
    {
        VIPseat    = "0";
    }
    else
    {
        VIPseat    = "1";
    }
    BuyerEmail = BUYEREMAIL;
    price      = PRICE;
}

int ticket::StoreInDatabase()
{
    if(database::get()->db.open())
    {
        bool ID_VERIFICATION=true;
        QSqlQuery qry;

        qry.prepare("SELECT id FROM  tickets");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
            return 0;
        }
        else
        {
            while(qry.next() && ID_VERIFICATION)
            {
                if(qry.value(qry.record().indexOf("id")).toInt() == id)
                {
                    ID_VERIFICATION=false;
                }
            }
        }

        if(ID_VERIFICATION == false)
        {
            QMessageBox::information(nullptr,"ERROR","ID ALREADY EXIST!.");
            return 0;
        }
        else if(id == 0 || ShowId == 0 || BuyerEmail == "")
        {
            QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
            return 0;
        }
        else
        {
            qry.prepare("INSERT INTO tickets (id, show_id, price, vip_seat, buyer_email) VALUES (:id, :show_id, :price, :vip_seat, :buyer_email)");
            qry.bindValue(":id",          id);
            qry.bindValue(":show_id",     ShowId);
            qry.bindValue(":price",       price);
            qry.bindValue(":vip_seat",    VIPseat);
            qry.bindValue(":buyer_email", BuyerEmail);

            if(qry.exec())
            {
                QMessageBox::information(nullptr,"Success","Ticket registered successfully.");

            }
            else
            {
                //QMessageBox::information(nullptr,"Error",qry.lastError().text());
                QMessageBox::information(nullptr,"error","SHOW ID DOESN'T EXIST ");
                //QMessageBox::information(nullptr,"error","database error");
                return 0;
            }
         }

    }
    return 1;

}

void ticket::Display()
{
    DisplayBox = new TicketGroupBox(ui->TicketsArea);
    DisplayBox->TicketId->setText(QString::number(id));
    DisplayBox->TicketShowId->setText(QString::number(ShowId));
    DisplayBox->TicketBuyerEmail->setText(BuyerEmail);
    DisplayBox->TicketPrice->setText(QString::number(price));
    if(VIPseat == "1")
    {
        DisplayBox->TicketVIP->setChecked(true);
    }
    else
    {
        DisplayBox->TicketVIP->setChecked(false);
    }

    ui->verticalLayout_tickets->addWidget(DisplayBox);
}
