#include "loginpage.h"
#include "database.h"
#include "current_user.h"

#include <QMessageBox>


loginpage::loginpage(Ui::MainWindow *ui)
{
    this->ui=ui;

}



void loginpage::login()
{
        QString username = ui->LoginUsernameInput->text();
        QString password = ui->LoginPasswordInput->text();

        if(username=="" || password=="")
        {
            QMessageBox::information(nullptr,"Notice","Please fill out both forms.");
        }
        else if(database::get()->db.open())
        {

            bool succ=false;


            QSqlQuery qry;
            qry.prepare("SELECT * FROM  users WHERE username = :username AND password = :password");
            qry.bindValue(":username",username);
            qry.bindValue(":password",password);
            if(!qry.exec())
            {
                QMessageBox::information(nullptr,"Error","Failed to exec query");
            }
            else
            {
                while(qry.next())
                {
                    QString db_username = qry.value(2).toString();
                    QString db_password = qry.value(3).toString();
                    if(db_username == username && db_password == password)
                    {
                        current_user::get()->setUser(qry.value(0).toInt());

                        //QString fullname=QString("%1 %2").arg(user::get()->f_name,user::get()->l_name);
                        //ui->name_label->setText(fullname);
                        //avatar->setLetter(QChar(u->f_name[0]));
                        //ui->stackedWidget->setCurrentIndex(2);
                        //snack->addMessage("Logged In.");
                        ui->BigStack->setCurrentIndex(1);
                        ui->LoginUsernameInput->setText("");
                        ui->LoginPasswordInput->setText("");

                        succ=true;
                    }
                    qDebug("Logged In.");
                    ui->DashboardPages->setCurrentIndex(0); //default page set to profile

                }
                if(succ==false)
                {
                    QMessageBox::information(nullptr,"Error","Couldnt Log In.");
                }
            }

        }
        else
        {
            QMessageBox::information(nullptr,"Error","Failed to connect to DB");
        }
}

