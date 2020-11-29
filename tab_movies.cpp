#include "tab_movies.h"
#include "movie.h"
#include "database.h"
#include <QMessageBox>
#include <QLayoutItem>
#include <QString>
tab_movies::tab_movies(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_movies::DisplayAllMovies()
{
    qDebug() << "DISPLAY ALL MOVIES";
    movie *MOVIE;
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  movies");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {

                qDebug() << qry.value(qry.record().indexOf("id")).toString() << " " << qry.value(qry.record().indexOf("name")).toInt() << " " << qry.value(qry.record().indexOf("type")).toInt() << " " << qry.value(qry.record().indexOf("price")).toInt() << qry.value(qry.record().indexOf("description")).toInt() << qry.value(qry.record().indexOf("imagelink")).toInt() << qry.value(qry.record().indexOf("sub_language")).toString() << qry.value(qry.record().indexOf("sub_language")).toString() << endl;
                MOVIE = new movie(qry.value(qry.record().indexOf          ("id")).toString(),
                                  qry.value(qry.record().indexOf        ("name")).toString(),
                                  qry.value(qry.record().indexOf        ("type")).toString(),
                                  qry.value(qry.record().indexOf       ("price")).toString(),
                                  qry.value(qry.record().indexOf ("description")).toString(),
                                  qry.value(qry.record().indexOf   ("imagelink")).toString(),
                                  qry.value(qry.record().indexOf("sub_language")).toString(),
                                  qry.value(qry.record().indexOf("dub_language")).toString(),
                                  ui);
                MOVIE->Display();
            }
        }
    }
}

void tab_movies::UndisplayAllMovies()
{
    QLayoutItem *child;
    while ((child = ui->horizontalLayout_4->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }
    {
    ui->horizontalLayout_4->children();
    }
}

void tab_movies::SearchMovies()
{
    UndisplayAllMovies();
    movie *MOVIE;
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        if(ui->SearchFilmByIdCheck   ->isChecked())
        {
            qry.prepare("SELECT * FROM  movies WHERE id = :id");
            qry.bindValue(":id",ui->SearchFilmById   ->text());
        }

        if(ui->SearchFilmByNameCheck ->isChecked())
        {
            qry.prepare("SELECT * FROM  movies WHERE name = :name");
            qry.bindValue(":name", ui->SearchFilmByName ->text() );
        }

        if(ui->SearchFilmByTypeCheck ->isChecked())
        {
            qry.prepare("SELECT * FROM  movies WHERE type = :type");
            qry.bindValue(":type", ui->SearchFilmByType ->text() );
        }

        if(ui->SearchFilmByPriceCheck->isChecked())
        {
            qry.prepare("SELECT * FROM  movies WHERE price = :price");
            qry.bindValue(":price",ui->SearchFilmByPrice->text());
        }

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {

                qDebug() << qry.value(qry.record().indexOf("id")).toString() << " " << qry.value(qry.record().indexOf("name")).toInt() << " " << qry.value(qry.record().indexOf("type")).toInt() << " " << qry.value(qry.record().indexOf("price")).toInt() << qry.value(qry.record().indexOf("description")).toInt() << qry.value(qry.record().indexOf("imagelink")).toInt() << qry.value(qry.record().indexOf("sub_language")).toString() << qry.value(qry.record().indexOf("sub_language")).toString() << endl;
                MOVIE = new movie(qry.value(qry.record().indexOf          ("id")).toString(),
                                  qry.value(qry.record().indexOf        ("name")).toString(),
                                  qry.value(qry.record().indexOf        ("type")).toString(),
                                  qry.value(qry.record().indexOf       ("price")).toString(),
                                  qry.value(qry.record().indexOf ("description")).toString(),
                                  qry.value(qry.record().indexOf   ("imagelink")).toString(),
                                  qry.value(qry.record().indexOf("sub_language")).toString(),
                                  qry.value(qry.record().indexOf("dub_language")).toString(),
                                  ui);
                MOVIE->Display();
            }
        }
    }
}

void tab_movies::AddMovie()
{
    movie* Movie = new movie(ui->FilmIdAdd          ->text(),
                             ui->FilmNameAdd        ->text(),
                             ui->FilmTypeAdd        ->text(),
                             ui->FilmPriceAdd       ->text(),
                             ui->FilmDescriptionAdd ->text(),
                             ui->FilmAddImageButton ->text(),
                             ui->FilmSubLanguageAdd ->text(),
                             ui->FilmDubLanguageAdd ->text(),
                             ui);

    if(Movie->StoreInDatabase() == 1)
    {
        Movie->Display();
    }

}


