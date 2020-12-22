#include "tab_clients.h"
#include <QDebug>
#include "client.h"
#include "database.h"
#include <QMessageBox>
tab_clients::tab_clients(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_clients::DisplayAllClients()
{
    qDebug() << "DISPLAY ALL CLIENTS";
    client *CLIENT;
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  clients");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {//client::client(int ID, QString NAME, QString EMAIL, int SUBSCRIPTION_ID, QDate SUBSCRIPTION_DATE, Ui::MainWindow *ui)
                CLIENT = new client(qry.value(qry.record().indexOf               ("id")).toInt(),
                                    qry.value(qry.record().indexOf             ("name")).toString(),
                                    qry.value(qry.record().indexOf            ("email")).toString(),
                                    qry.value(qry.record().indexOf  ("subscription_id")).toInt(),
                                    qry.value(qry.record().indexOf("subscription_date")).toDate(),
                                    ui);
                CLIENT->Display();
            }
        }
    }
}
void tab_clients::AddClient()
{
    client* Client = new client(ui->ClientIdAdd         ->text().toInt(),
                                      ui->ClientNameAdd       ->text(),
                                      ui->ClientEmailAdd->text(),
                                      ui->ClientSubscriptionIdAdd      ->text().toInt(),
                                      QDate::currentDate(),
                                      ui);
    if(Client->StoreInDatabase() == 1)
    {
        Client->Display();
    }

}
