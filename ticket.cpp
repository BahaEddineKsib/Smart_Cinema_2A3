#include "ticket.h"
#include "database.h"
#include <QMessageBox>
ticket::ticket(int ID, int SHOWID, int PRICE, QString VIPSEAT, QString BUYEREMAIL, Ui::MainWindow *ui)
{
    this->ui   = ui;
    id         = ID;
    ShowId     = SHOWID;
    VIPseat    = VIPSEAT;
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
        else if(id == 0 || ShowId == 0 || price == 0 || VIPseat == "" || BuyerEmail == "")
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
                QMessageBox::information(nullptr,"Error",qry.lastError().text());
                QMessageBox::information(nullptr,"error","database error");
                return 0;
            }
         }

    }
    return 1;

}

void ticket::Display()
{
    //TicketGroupBox* displayBox = new TicketGroupBox(ui->TicketsArea);
    //DisplayBox->PrepareToDisplay(id, ShowId, price, VIPseat, BuyerEmail);
    //ui->verticalLayout_8->addWidget(displayBox);
}
