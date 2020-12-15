#include "tab_client.h"
#include "client.h"
#include "database.h"
#include <QMessageBox>
#include <QLayoutItem>
#include <QString>
tab_client::tab_client(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_client::DisplayAllclient()
{
    qDebug() << "DISPLAY ALL CLIENT";
    client *CLIENT;
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  client");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {

                qDebug() << qry.value(qry.record().indexOf("id")).toString() << " " << qry.value(qry.record().indexOf("name")).toString() << " " <<qry.value(qry.record().indexOf("Email")).toString() << endl;
                CLIENT = new client(qry.value(qry.record().indexOf          ("id")).toString(),
                                  qry.value(qry.record().indexOf        ("name")).toString(),
                                  qry.value(qry.record().indexOf       ("Email")).toString(),
                                  ui);
                CLIENT->Display();
            }
        }
    }
}

void tab_client::UndisplayAllclient()
{
    QLayoutItem *child;
    while ((child = ui->horizontalLayout_22->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
    {
    ui->horizontalLayout_22->children();
    }
}

void tab_client::Searchclient()
{
    UndisplayAllclient();
    client *CLIENT;
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        if(ui->SearchclientIDchekbox   ->isChecked())
        {
            qry.prepare("SELECT * FROM  client WHERE id = :id");
            qry.bindValue(":id",ui->SearchclientID   ->text());
        }

        if(ui->SearchclientByNameCheck ->isChecked())
        {
            qry.prepare("SELECT * FROM  client WHERE name = :name");
            qry.bindValue(":name", ui->SearchclientByName ->text() );
        }

        if(ui->SearchsubscriptionBypriceCheck ->isChecked())
        {
            qry.prepare("SELECT * FROM  client WHERE Email = :email");
            qry.bindValue(":Email", ui->SearchsubscriptionByprice ->text() );
        }

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {

                qDebug() << qry.value(qry.record().indexOf("id")).toString() << " " << qry.value(qry.record().indexOf("name")).toString() << " " << qry.value(qry.record().indexOf("Email")).toString() << endl;
                CLIENT = new client(qry.value(qry.record().indexOf          ("id")).toString(),
                                  qry.value(qry.record().indexOf        ("name")).toString(),
                                  qry.value(qry.record().indexOf       ("Email")).toString(),
                                  ui);
                CLIENT->Display();
            }
        }
    }
}

void tab_client::Addclient()
{
    client* Client = new client(ui-> client_name ->text(),
                             ui-> client_ID   ->text(),
                             ui->client_Email  ->text(),
                             ui);

    if(Client->StoreInDatabase() == 1)
    {
        Client->Display();
    }

}


