#include "tab_theatres.h"
#include "database.h"

#include <QMessageBox>

tab_theatres::tab_theatres(Ui::MainWindow *ui)
{
    this->ui=ui;
    ui->add_theatre_widget->hide(); //default : hidden
    ui->add_theatre_widget->setGeometry(211,149,449,355);
}

void tab_theatres::show_theatres()
{
    //int x= 84;
    int i=0;
    if(database::get()->db.open())
            {
                QSqlQuery qry;
                qry.prepare("SELECT * FROM  tab_theatres");
                if(!qry.exec())
                {
                    QMessageBox::information(nullptr,"Error","Failed to exec query");
                }
                else
                {
                    while(qry.next())
                    {
                        qDebug() << qry.value(0).toString() << " " << qry.value(1).toInt() << " " << qry.value(2).toInt() << " " << qry.value(3).toInt() << endl;

                        /*QFrame *th_frame = new QFrame();
                        th_frame->setParent(ui->theatresScrollArea);
                        th_frame->setStyleSheet("background-color: rgb(51, 56, 100);border-radius: 10px;");
                        th_frame->setGeometry(x,62,200,222);

                        QLabel *th_label = new QLabel();
                        th_label->setParent(th_frame);
                        th_label->setText(qry.value(0).toString());
                        th_label->setStyleSheet("color:#fff");
                        th_label->move(x+100,62);

                        x+=304;*/

                        i++;

                    }
                }
    }
    else
    {
        QMessageBox::information(nullptr,"Error","Failed to connect to DB");
    }
}

void tab_theatres::add_theatre()
{

    QString name = ui->add_theatre_name->text();
    QString max_seats = ui->add_theatre_seats->text();

    if(name=="" || max_seats=="")
    {
        QMessageBox::information(nullptr,"Notice","Please fill out all forms.");
    }

    else if(database::get()->db.open())
    {

        QSqlQuery qry;
        qry.prepare("INSERT INTO tab_theatres (name,seats_max) VALUES (:name,:seats_max)");

        qry.bindValue(":name",name);
        qry.bindValue(":seats_max",max_seats.toInt());

        ui->add_theatre_name->setText("");
        ui->add_theatre_seats->setText("");

        if(qry.exec())
        {
            QMessageBox::information(nullptr,"Success","Theatre added.");
        }
        else
        {
            QMessageBox::information(nullptr,"Error",qry.lastError().text());
        }


    }
    else
    {
        QMessageBox::information(nullptr,"Error","Failed to connect to DB");
    }

    ui->add_theatre_widget->hide();
}

void tab_theatres::show_add_theatre()
{
    ui->add_theatre_widget->show();
}

void tab_theatres::hide_add_theatre()
{
    ui->add_theatre_widget->hide();
}
