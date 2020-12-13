#ifndef TAB_MOVIES_H
#define TAB_MOVIES_H

#include "ui_mainwindow.h"
class tab_movies
{
public:
    tab_movies(Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void DisplayAllMovies();
    void UndisplayAllMovies();
    void AddMovie();
    void SearchMovies();

};

#endif // TAB_MOVIES_H
