#include "tab_theatres.h"
#include "database.h"

tab_theatres::tab_theatres(Ui::MainWindow *ui)
{
    this->ui=ui;
    ui->add_theatre_widget->hide(); //default : hidden
}

void tab_theatres::show_theatres()
{

}

void tab_theatres::add_theatre()
{

    QString name = ui->add_theatre_name->text();
    QString max_seats = ui->add_theatre_seats->text();

    if(name=="" || max_seats=="")
    {
        qDebug("Please fill out all forms.");
    }

    else if(database::get()->db.open())
    {

        QSqlQuery qry;
        qry.prepare("INSERT INTO tab_theatres (name,seats_max) VALUES (:name,:seats_max)");

        qry.bindValue(":name",name);
        qry.bindValue(":seats_max",max_seats.toInt());

        ui->add_theatre_name->setText("");
        ui->add_theatre_seats->setText("");

        qry.exec();
        //qDebug() << qry.lastError().text();
        qDebug("Theatre added.");
    }
    else
    {
        qDebug("Failed to connect to DB");
    }

    ui->add_theatre_widget->hide();
}

void tab_theatres::show_add_theatre()
{
    ui->add_theatre_widget->show();
}
