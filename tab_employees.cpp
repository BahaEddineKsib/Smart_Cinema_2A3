#include "tab_employees.h"
#include "database.h"

#include <QSqlDatabase>
#include <QtSql>

tab_employees::tab_employees(Ui::MainWindow *ui)
{
    this->ui=ui;
}

void tab_employees::add_employee()
{
        QString name = ui->Employee_new_name->text();
        QString email = ui->Employee_new_email->text();
        QString username = ui->Employee_new_username->text();
        QString password = ui->Employee_new_password->text();

        if(username=="" || password=="")
        {
            qDebug("Please fill out both forms.");
        }

        else if(database::get()->db.open())
        {

            qDebug("CONNECTED TO DB.");
            QSqlQuery qry;
            qry.prepare("INSERT INTO users (name,email,username,password) VALUES (:email,:name,:username,:password");

            qry.bindValue(":email",email);
            qry.bindValue(":name",name);
            qry.bindValue(":username",username);
            qry.bindValue(":password",password);


            ui->Employee_new_name->setText("");
            ui->Employee_new_email->setText("");
            ui->Employee_new_username->setText("");
            ui->Employee_new_password->setText("");

            qry.exec();
        }
        else
        {
            qDebug("Failed to connect to DB");
        }
}
