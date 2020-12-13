#include "mainwindow.h"
#include "moviesFiles\movie.h"
#include "database.h"
#include <QMessageBox>
#include <QHBoxLayout>
movie::movie(){}
movie::movie(QString ID, QString NAME, QString TYPE, QString PRICE, QString DESCRIPTION, QString IMAGELINK, QString SUBLANGUAGE, QString DUBLANGUAGE, Ui::MainWindow *ui)
{
    this->ui=ui;
    id =          ID;
    name =        NAME;
    type =        TYPE;
    price =       PRICE;
    description = DESCRIPTION;
    SubLaguage  = SUBLANGUAGE;
    DubLaguage  = DUBLANGUAGE;
    ImageLink=    IMAGELINK;
}
int movie::StoreInDatabase()
{
    if(database::get()->db.isOpen())
    {
        bool ID_VERIFICATION=true;
        QSqlQuery qry;
        qry.prepare("SELECT id FROM  movies");
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
            else if(id == "" || name == "" || type == "" || price == "" || description == "" || ImageLink == "" || SubLaguage == "" || DubLaguage == "" )
                    {QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
                     return 0;}
                        else
                        {
                            qry.prepare("INSERT INTO movies (id,name,type,price,description,imagelink,sub_language,dub_language) VALUES (:id,:name,:type,:price,:description,:imagelink,:sub_language,:dub_language)");
                            qry.bindValue(":id",          id);
                            qry.bindValue(":name",        name);
                            qry.bindValue(":type",        type);
                            qry.bindValue(":price",       price);
                            qry.bindValue(":description", description);
                            qry.bindValue(":imagelink",   ImageLink);
                            qry.bindValue(":sub_language",SubLaguage);
                            qry.bindValue(":dub_language",DubLaguage);
                            if(qry.exec())
                            {
                                QMessageBox::information(nullptr,"Success","Movie registered successfully.");

                            }
                            else
                            {
                                QMessageBox::information(nullptr,"Error",qry.lastError().text());
                                QMessageBox::information(nullptr,"error","database error");
                                return 0;
                            }
                         }

    }
     return 1;

}

void movie::Display()

{
    DisplayBox = new MovieGroupBox(ui->MoviesArea);
    DisplayBox->MovieIdEdit->setText(id);
    DisplayBox->MovieNameEdit->setText(name);
    DisplayBox->MovieTypeEdit->setText(type);
    DisplayBox->MoviePriceEdit->setText(price);
    DisplayBox->MovieDescriptionEdit->setPlainText(description);
    DisplayBox->MovieSubLanguageEdit->setText(SubLaguage);
    DisplayBox->MovieDubLanguageEdit->setText(DubLaguage);
    QIcon icon1;
    icon1.addFile(ImageLink, QSize(), QIcon::Normal, QIcon::Off);
    DisplayBox->MovieImageButton->setIcon(icon1);

    ui->horizontalLayout_4->addWidget(DisplayBox);
}





