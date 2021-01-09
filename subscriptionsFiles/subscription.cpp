#include "subscription.h"
#include "database.h"
#include <QMessageBox>
subscription::subscription(int ID, QString NAME, int PRICE, int NUMBER_OF_DAYS, int FREE_FOOD, Ui::MainWindow *ui)
{
    this->ui     = ui;
    id           = ID;
    name         = NAME;
    price        = PRICE;
    NumberOfDays = NUMBER_OF_DAYS;
    FreeFood     = FREE_FOOD;
}
int subscription::StoreInDatabase()
{

        bool ID_VERIFICATION=true;
        QSqlQuery qry;

        qry.prepare("SELECT id FROM  subscriptions");
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
        else if(id == 0 || name == 0 || price == 0 || NumberOfDays == 0)
        {
            QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
            return 0;
        }
        else
        {
            qry.prepare("INSERT INTO subscriptions (id, name, price, number_of_days, free_food) VALUES (:id, :name, :price, :number_of_days, :free_food)");
            qry.bindValue(":id",          id);
            qry.bindValue(":name",     name);
            qry.bindValue(":price",       price);
            qry.bindValue(":number_of_days", NumberOfDays);
            qry.bindValue(":free_food", FreeFood);

            if(qry.exec())
            {
                QMessageBox::information(nullptr,"Success","Subscription registered successfully.");

            }
            else
            {
                QMessageBox::information(nullptr,"Error",qry.lastError().text());
                //QMessageBox::information(nullptr,"error","database error");
                return 0;
            }
         }
    return 1;

}

void subscription::Display()
{
    //subscription::subscription(int ID, QString NAME, int PRICE, int NUMBER_OF_DAYS, int FREE_FOOD, Ui::MainWindow *ui)
    DisplayBox = new SubscriptionGroupBox(ui->SubscriptionsArea);
    DisplayBox->SubscriptionId->setText(QString::number(id));
    DisplayBox->SubscriptionPriceEdit->setText(QString::number(price));
    DisplayBox->SubscriptionNameEdit->setText(name);
    DisplayBox->SubscriptionNumberOfDaysEdit->setText(QString::number(NumberOfDays));
    if(FreeFood == 1)
    {
        DisplayBox->SubscriptionFreeFoodEdit->setChecked(true);
    }
    else
    {
        DisplayBox->SubscriptionFreeFoodEdit->setChecked(false);
    }

    ui->horizontalLayout_SUB->addWidget(DisplayBox);
}
