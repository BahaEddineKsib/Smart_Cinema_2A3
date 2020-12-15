#include "mainwindow.h"
#include "client.h"
#include "database.h"
#include <QMessageBox>
#include <QHBoxLayout>
client::client(){}
client::client(QString ID, QString NAME, QString EMAIL, Ui::MainWindow *ui)
{
    this->ui=ui;
    id =          ID;
    name =        NAME;
    Email =       EMAIL;
}
int client::StoreInDatabase()
{
    if(database::get()->db.open())
    {
        bool ID_VERIFICATION=true;
        QSqlQuery qry;
        qry.prepare("SELECT id FROM  client");
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
            else if(id == "" || name == "" || Email == "")
                    {QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
                     return 0;}
                        else
                        {
                            qry.prepare("INSERT INTO client (id,name,Email) VALUES (:id,:name,:Email)");
                            qry.bindValue(":id",          id);
                            qry.bindValue(":name",        name);
                            qry.bindValue(":Email",       Email);
                            if(qry.exec())
                            {
                                QMessageBox::information(nullptr,"Success","client registered successfully.");
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

void client::Display()
{
    DisplayBox = new clientGroupBox(ui->clientArea);
    DisplayBox->clientIdEdit->setText(id);
    DisplayBox->clientNameEdit->setText(name);
    DisplayBox->clientEmailEdit->setText(Email);
    ui->horizontalLayout_22->addWidget(DisplayBox);
}





