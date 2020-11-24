#include "mainwindow.h"
#include "movie.h"
#include "database.h"
#include <QMessageBox>
movie::movie(){}
movie::movie(QString ID, QString NAME, QString TYPE, QString PRICE, QString DESCRIPTION, bool AR, bool FR, bool EN)
{
    id =          ID;
    name =        NAME;
    type =        TYPE;
    price =       PRICE;
    description = DESCRIPTION;
    ar =          AR;
    fr =          FR;
    en =          EN;
}
void movie::StoreInDatabase()
{
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("INSERT INTO movies (id,name,type,price,fr,ar,en,description) VALUES (:id,:name,:type,:price,:fr,:ar,:en,:description)");

        qry.bindValue(":id",         id);
        qry.bindValue(":name",       name);
        qry.bindValue(":type",       type);
        qry.bindValue(":price",      price);
        qry.bindValue(":description",description);
        if(fr)
        {
            qry.bindValue(":fr","1");
        }
        else
        {
            qry.bindValue(":fr","0");
        }
        if(ar)
        {
            qry.bindValue(":ar","1");
        }
        else
        {
            qry.bindValue(":ar","0");
        }
        if(en)
        {
            qry.bindValue(":en","1");
        }
        else
        {
            qry.bindValue(":en","0");
        }
        if(qry.exec())
        {
            QMessageBox::information(nullptr,"Success","Employee registered successfully.");
        }
        else
        {
            QMessageBox::information(nullptr,"Error",qry.lastError().text());
        }

    }

}
void MainWindow::on_FilmAddButton_clicked()
{
    movie Movie(ui->FilmIdAdd->   text(),
                ui->FilmNameAdd-> text(),
                ui->FilmTypeAdd-> text(),
                ui->FilmPriceAdd->text(),
                ui->FilmDescriptionAdd->text(),
                ui->FilmArCheckAdd->isChecked(),
                ui->FilmFrCheckAdd->isChecked(),
                ui->FilmEnCheckAdd->isChecked());

    Movie.StoreInDatabase();
}
