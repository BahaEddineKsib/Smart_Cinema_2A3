#include "mainwindow.h"
#include "movie.h"
#include "database.h"
#include <QMessageBox>
#include <QHBoxLayout>
movie::movie(){}
movie::movie(QString ID, QString NAME, QString TYPE, QString PRICE, QString DESCRIPTION, bool AR, bool FR, bool EN,Ui::MainWindow *ui)
{
    this->ui=ui;
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

void movie::Display()
{
    DisplayBox = new MovieGroupBox(ui->MoviesArea);
    DisplayBox->MovieIdEdit->setText(id);
    DisplayBox->MovieNameEdit->setText(name);
    DisplayBox->MovieTypeEdit->setText(type);
    DisplayBox->MoviePriceEdit->setText(price);
    DisplayBox->MovieDescriptionEdit->setPlainText(description);
    DisplayBox->MovieArCheck->setChecked(ar);
    DisplayBox->MovieFrCheck->setChecked(fr);
    DisplayBox->MovieEnCheck->setChecked(en);
    ui->horizontalLayout_4->addWidget(DisplayBox);
}





