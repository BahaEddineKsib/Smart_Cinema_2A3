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

void tab_clients::UndisplayAllClients()
{
    QLayoutItem *child;
    while ((child = ui->ClientVerticalLayout->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
    {
    ui->ClientVerticalLayout->children();
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



void tab_clients::SearchClients()
{
    UndisplayAllClients();
    client *CLIENT[100];
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
            int SearchConditionsNumber=0;
            int SearchConditionsTests[100];
            int NumberOfClients =0;
            while(qry.next())
            {
                CLIENT[NumberOfClients] = new client(qry.value(qry.record().indexOf               ("id")).toInt(),
                                                     qry.value(qry.record().indexOf             ("name")).toString(),
                                                     qry.value(qry.record().indexOf            ("email")).toString(),
                                                     qry.value(qry.record().indexOf  ("subscription_id")).toInt(),
                                                     qry.value(qry.record().indexOf("subscription_date")).toDate(),
                                                     ui);
                SearchConditionsTests[NumberOfClients]=0;
                NumberOfClients++;
                qDebug() << "NumberOfClients++";
            }


                if(ui->SearchClientById->text() != "" )
                {
                    qDebug() << "ui->SearchClientById->text() != '' ";
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfClients) {
                         if(ui->SearchClientById->text().toInt() == CLIENT[i]->id )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }

                if(ui->SearchClientByName->text() != "" )
                {
                    qDebug() << "ui->SearchClientById->text() !=  '' ";
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfClients) {
                         if(ui->SearchClientByName->text() == CLIENT[i]->name )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }
                if(ui->SearchClientByEmail->text() != "" )
                {
                    qDebug() << "ui->SearchClientByEmail->text() !=  '' ";
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfClients) {
                         if(ui->SearchClientByEmail->text() == CLIENT[i]->email )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }
                if(ui->SearchClientBySubscriptionId->text() != "" )
                {
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfClients) {
                         if(ui->SearchClientBySubscriptionId->text().toInt() == CLIENT[i]->SubscriptionId )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }
                if(ui->SearchClientBySubscriptionDate->text() != "" && ui->SearchClientBySubscriptionDateCheckBox->isChecked())
                {
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfClients) {
                         if(ui->SearchClientBySubscriptionDate->text() == CLIENT[i]->SubscriptionDate.toString() )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }
                int i=0;
                 while (i<NumberOfClients) {
                     qDebug() << "affiche ";
                     if(SearchConditionsTests[i]==SearchConditionsNumber)
                     {
                         CLIENT[i]->Display();
                     }
                     i++;
                }
        }

    }
}
