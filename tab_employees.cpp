#include "tab_employees.h"
#include "database.h"

#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>

tab_employees::tab_employees(Ui::MainWindow *ui)
{
    this->ui=ui;
}

void tab_employees::add_employee()
{

        QString email = ui->Employee_new_email->text();
        QString username = ui->Employee_new_username->text();
        QString password = ui->Employee_new_password->text();
        QString name = ui->Employee_new_name->text();

        if(name=="" || email=="" || username=="" || password=="")
        {
            QMessageBox::information(nullptr,"Notice","Please fill out all forms.");
        }

        else if(database::get()->db.open())
        {

            qDebug("CONNECTED TO DB.");
            QSqlQuery qry;
            qry.prepare("INSERT INTO users (email,username,password,name,role) VALUES (:email,:username,:password,:name,:role)");


            qry.bindValue(":email",email);
            qry.bindValue(":username",username);
            qry.bindValue(":password",password);
            qry.bindValue(":name",name);
            qry.bindValue(":role",0);

            ui->Employee_new_email->setText("");
            ui->Employee_new_username->setText("");
            ui->Employee_new_password->setText("");
            ui->Employee_new_name->setText("");

            if(qry.exec())
            {
                QMessageBox::information(nullptr,"Success","Employee registered successfully.");
            }
            else
            {
                QMessageBox::information(nullptr,"Error",qry.lastError().text());
            }


        }
        else
        {
            qDebug("Failed to connect to DB");
        }
}
