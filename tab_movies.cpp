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
               // qDebug() << qry.value(0).toString() << " " << qry.value(1).toInt() << " " << qry.value(2).toInt() << " " << qry.value(3).toInt() << endl;
                MOVIE = new movie(qry.value(0).toString(),
                                  qry.value(1).toString(),
                                  qry.value(2).toString(),
                                  qry.value(3).toString(),
                                  qry.value(4).toString(),
                                  qry.value(5).toInt()==1,
                                  qry.value(6).toInt()==1,
                                  qry.value(7).toInt()==1,
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
               // qDebug() << qry.value(0).toString() << " " << qry.value(1).toInt() << " " << qry.value(2).toInt() << " " << qry.value(3).toInt() << endl;
                MOVIE = new movie(qry.value(0).toString(),
                                  qry.value(1).toString(),
                                  qry.value(2).toString(),
                                  qry.value(3).toString(),
                                  qry.value(4).toString(),
                                  qry.value(5).toInt()==1,
                                  qry.value(6).toInt()==1,
                                  qry.value(7).toInt()==1,
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
                             ui->FilmArCheckAdd->isChecked(),
                             ui->FilmFrCheckAdd->isChecked(),
                             ui->FilmEnCheckAdd->isChecked(),
                             ui);

    Movie->StoreInDatabase();
    Movie->Display();
}


