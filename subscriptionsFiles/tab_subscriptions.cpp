#include "tab_subscriptions.h"
#include "subscription.h"
#include "database.h"
#include <QDebug>
#include <QMessageBox>
tab_subscriptions::tab_subscriptions(Ui::MainWindow *ui)
{
    this->ui = ui;
}
void tab_subscriptions::DisplayAllSubscriptions()
{
    qDebug() << "DISPLAY ALL TICKETS";
    subscription *SUBSCRIPTION;
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  subscriptions");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {
                //subscription::subscription(int ID, QString NAME, int PRICE, int NUMBER_OF_DAYS, int FREE_FOOD, Ui::MainWindow *ui)
                SUBSCRIPTION = new subscription(qry.value(qry.record().indexOf            ("id")).toInt(),
                                                qry.value(qry.record().indexOf          ("name")).toString(),
                                                qry.value(qry.record().indexOf         ("price")).toInt(),
                                                qry.value(qry.record().indexOf("number_of_days")).toInt(),
                                                qry.value(qry.record().indexOf     ("free_food")).toInt(),
                                                ui);
                SUBSCRIPTION->Display();
            }
        }
    }
}


void tab_subscriptions::AddSubscription()
{

    int FREEFOOD;
    if(ui->SubscriptionFreeFoodAdd->isChecked()){FREEFOOD = 1;}else{FREEFOOD = 0;}

    subscription* Subscription = new subscription(ui->SubscriptionIdAdd->text().toInt(),
                                                  ui->SubscriptionNameAdd->text(),
                                                  ui->SubscriptionPriceAdd->text().toInt(),
                                                  ui->SubscriptionNumberOfDaysAdd->text().toInt(),
                                                  FREEFOOD,
                                                  ui);

    if(Subscription->StoreInDatabase() == 1)
    {
        Subscription->Display();
    }
}
