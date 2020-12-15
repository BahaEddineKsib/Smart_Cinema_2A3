#include "mainwindow.h"
#include "subscription.h"
#include "database.h"
#include <QMessageBox>
#include <QHBoxLayout>
subscription::subscription(){}
subscription::subscription(QString ID, QString NAME, QString PRICE, Ui::MainWindow *ui)
{
    this->ui=ui;
    id =          ID;
    name =        NAME;
    price =       PRICE;
}
int subscription::StoreInDatabase()
{
    if(database::get()->db.open())
    {
        bool ID_VERIFICATION=true;
        QSqlQuery qry;
        qry.prepare("SELECT id FROM  subscription");
        if(!qry.exec())
        {QMessageBox::information(nullptr,"Error","Failed to exec query");
         return 0;}
        else{

            while(qry.next() && ID_VERIFICATION){
                if(qry.value(qry.record().indexOf("id")).toString() == id){
                    ID_VERIFICATION=false;}}}

        if(ID_VERIFICATION == false)
        {QMessageBox::information(nullptr,"ERROR","ID ALREADY EXIST!.");
         return 0;}
            else if(id == "" || name == "" || price == "")
                    {QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
                     return 0;}
                        else
                        {
                            qry.prepare("INSERT INTO subscription (id,name,price) VALUES (:id,:name,:price)");
                            qry.bindValue(":id",          id);
                            qry.bindValue(":name",        name);
                            qry.bindValue(":price",       price);
                            if(qry.exec())
                            {
                                QMessageBox::information(nullptr,"Success","subscription registered successfully.");
                                return 1;
                            }
                            else
                            {
                                QMessageBox::information(nullptr,"Error",qry.lastError().text());
                                QMessageBox::information(nullptr,"error","database error");
                                return 0;
                            }
                         }

    }}

void subscription::Display()
{
    DisplayBox = new subscriptionGroupBox(ui->subscriptionArea);
    DisplayBox->subscriptionIdEdit->setText(id);
    DisplayBox->subscriptionNameEdit->setText(name);
    DisplayBox->subscriptionpriceEdit->setText(price);
    ui->horizontalLayout_28->addWidget(DisplayBox);
}











