#include "moviesFiles\tab_movies.h"
#include "moviesFiles\movie.h"
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
    movie *MOVIE[100];
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  movies");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            int SearchConditionsNumber=0;
            int SearchConditionsTests[100];
            int NumberOfMovies =0;
            while(qry.next())
            {
                MOVIE[NumberOfMovies] = new movie(qry.value(qry.record().indexOf       ("id")).toString(),
                                  qry.value(qry.record().indexOf        ("name")).toString(),
                                  qry.value(qry.record().indexOf        ("type")).toString(),
                                  qry.value(qry.record().indexOf       ("price")).toString(),
                                  qry.value(qry.record().indexOf ("description")).toString(),
                                  qry.value(qry.record().indexOf   ("imagelink")).toString(),
                                  qry.value(qry.record().indexOf("sub_language")).toString(),
                                  qry.value(qry.record().indexOf("dub_language")).toString(),
                                  ui);
                SearchConditionsTests[NumberOfMovies]=0;
                NumberOfMovies++;
            }


                if(ui->SearchFilmById->text() != "" )
                {
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfMovies) {
                         if(ui->SearchFilmById->text() == MOVIE[i]->id )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }

                if(ui->SearchFilmByName->text() != "" )
                {
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfMovies) {
                         if(ui->SearchFilmByName->text() == MOVIE[i]->name )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }
                if(ui->SearchFilmByType->text() != "" )
                {
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfMovies) {
                         if(ui->SearchFilmByType->text() == MOVIE[i]->type )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }
                if(ui->SearchFilmByPrice->text() != "" )
                {
                    SearchConditionsNumber++;
                    int i=0;
                     while (i<NumberOfMovies) {
                         if(ui->SearchFilmByPrice->text() == MOVIE[i]->price )
                         {
                             SearchConditionsTests[i]++;
                         }
                         i++;
                     }
                }
                int i=0;
                 while (i<NumberOfMovies) {
                     if(SearchConditionsTests[i]==SearchConditionsNumber)
                     {
                         MOVIE[i]->Display();
                     }
                     i++;
                }
        }

    }

void tab_movies::AddMovie()
{
    QString link = "" ;
    if(ui->FilmAddImageButton->text().indexOf(".png")!=-1 || ui->FilmAddImageButton->text().indexOf(".PNG")!=-1)
    {
        link = QCoreApplication::applicationDirPath()+"/"+ui->FilmIdAdd->text()+".png";
    }
    else if (ui->FilmAddImageButton->text().indexOf(".jpg")!=-1 || ui->FilmAddImageButton->text().indexOf(".JPG")!=-1)
    {
        link = QCoreApplication::applicationDirPath()+"/"+ui->FilmIdAdd->text()+".jpg";
    }
    else if (ui->FilmAddImageButton->text().indexOf(".gif")!=-1 || ui->FilmAddImageButton->text().indexOf(".GIF")!=-1)
    {
        link = QCoreApplication::applicationDirPath()+"/"+ui->FilmIdAdd->text()+".gif";
    }
    else if (ui->FilmAddImageButton->text().indexOf(".jpeg")!=-1 || ui->FilmAddImageButton->text().indexOf(".JPEG")!=-1)
    {
        link = QCoreApplication::applicationDirPath()+"/"+ui->FilmIdAdd->text()+".jpeg";
    }
    QFile::copy(ui->FilmAddImageButton ->text(),link);
    movie* Movie = new movie(ui->FilmIdAdd          ->text(),
                             ui->FilmNameAdd        ->text(),
                             ui->FilmTypeAdd        ->text(),
                             ui->FilmPriceAdd       ->text(),
                             ui->FilmDescriptionAdd ->text(),
                             link,
                             ui->FilmSubLanguageAdd ->text(),
                             ui->FilmDubLanguageAdd ->text(),
                             ui);

    if(Movie->StoreInDatabase() == 1)
    {
        Movie->Display();
    }

}


