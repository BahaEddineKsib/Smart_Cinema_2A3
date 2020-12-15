#include "tab_subscription.h"
#include "subscription.h"
#include "database.h"
#include <QMessageBox>
#include <QLayoutItem>
#include <QString>
tab_subscription::tab_subscription(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_subscription::DisplayAllsubscription()
{
    qDebug() << "DISPLAY ALL subscription";
    subscription *SUBSCRIPTION;
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  subscription");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {

                qDebug() << qry.value(qry.record().indexOf("id")).toString() << " " << qry.value(qry.record().indexOf("name")).toString() << " " <<qry.value(qry.record().indexOf("price")).toString() << endl;
                SUBSCRIPTION = new subscription(qry.value(qry.record().indexOf          ("id")).toString(),
                                  qry.value(qry.record().indexOf        ("name")).toString(),
                                  qry.value(qry.record().indexOf       ("price")).toString(),
                                  ui);
                SUBSCRIPTION->Display();
            }
        }
    }
}

void tab_subscription::UndisplayAllsubscription()
{
    QLayoutItem *child;
    while ((child = ui->horizontalLayout_28->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
    {
    ui->horizontalLayout_28->children();
    }
}

void tab_subscription::Searchsubscription()
{
    UndisplayAllsubscription();
    subscription *SUBSCRIPTION;
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        if(ui->SearchsubscriptionIDchekbox   ->isChecked())
        {
            qry.prepare("SELECT * FROM  subscription WHERE id = :id");
            qry.bindValue(":id",ui->SearchsubscriptionID   ->text());
        }

        if(ui->SearchsubscriptionByNameCheck ->isChecked())
        {
            qry.prepare("SELECT * FROM  subscription WHERE name = :name");
            qry.bindValue(":name", ui->SearchsubscriptionByName ->text() );
        }

        if(ui->SearchsubscriptionBypriceCheck ->isChecked())
        {
            qry.prepare("SELECT * FROM  subscription WHERE price = :price");
            qry.bindValue(":price", ui->SearchsubscriptionByprice ->text() );
        }

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {

                qDebug() << qry.value(qry.record().indexOf("id")).toString() << " " << qry.value(qry.record().indexOf("name")).toString() << " " << qry.value(qry.record().indexOf("price")).toString() << endl;
                SUBSCRIPTION = new subscription(qry.value(qry.record().indexOf          ("id")).toString(),
                                  qry.value(qry.record().indexOf        ("name")).toString(),
                                  qry.value(qry.record().indexOf       ("price")).toString(),
                                  ui);
                SUBSCRIPTION->Display();
            }
        }
    }
}

void tab_subscription::Addsubscription()
{
    subscription* SUBSCRIPTION = new subscription(ui-> subscription_name ->text(),
                             ui-> subscription_ID   ->text(),
                             ui->subscription_price  ->text(),
                             ui);

    if(SUBSCRIPTION->StoreInDatabase() == 1)
    {
        SUBSCRIPTION->Display();
    }

}


