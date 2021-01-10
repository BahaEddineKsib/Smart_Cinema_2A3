#include "client.h"
#include "database.h"
#include <QMessageBox>
client::client(int ID, QString NAME, QString EMAIL, int SUBSCRIPTION_ID, QDate SUBSCRIPTION_DATE, Ui::MainWindow *ui)
{
    this->ui         = ui;
    id               = ID;
    name             = NAME;
    email            = EMAIL;
    SubscriptionId   = SUBSCRIPTION_ID;
    SubscriptionDate = SUBSCRIPTION_DATE;

}


int client::StoreInDatabase()
{
        bool ID_VERIFICATION=true;
        QSqlQuery qry;

        qry.prepare("SELECT id FROM  clients");
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
        else if(id == 0 || name == "" || email == "" || SubscriptionId == 0)
        {
            QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
            return 0;
        }
        else
        {
            qry.prepare("INSERT INTO clients (id, name, email, subscription_id, subscription_date) VALUES (:id, :name, :email, :subscription_id, :subscription_date)");
            qry.bindValue(":id",       id);
            qry.bindValue(":name",     name);
            qry.bindValue(":email",    email);
            qry.bindValue(":subscription_id",SubscriptionId);
            qry.bindValue(":subscription_date",SubscriptionDate);

            if(qry.exec())
            {
                QMessageBox::information(nullptr,"Success","Client registered successfully.");

            }
            else
            {
                QMessageBox::information(nullptr,"Error",qry.lastError().text());
                QMessageBox::information(nullptr,"error","database error");
                return 0;
            }
         }
    return 1;

}

void client::Display()
{
    DisplayBox = new ClientGroupBox(ui->ClientsArea);
    DisplayBox->ClientId->setText(QString::number(id));
    DisplayBox->ClientNameEdit->setText(name);
    DisplayBox->ClientEmailEdit->setText(email);
    DisplayBox->ClientSubscriptionIdEdit->setText(QString::number(SubscriptionId));
    DisplayBox->ClientSubscriptionDateEdit->setDate(SubscriptionDate);

    ui->ClientVerticalLayout->addWidget(DisplayBox);

}
