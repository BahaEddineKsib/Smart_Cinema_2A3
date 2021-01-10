#ifndef TAB_THEATRES_H
#define TAB_THEATRES_H
#include <ui_mainwindow.h>

class tab_theatres
{
public:
    tab_theatres(Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void DisplayAllTheatres();
    void UndisplayAllTheatres();
    void AddTheatre();
    //void SearchTheatres();
};

#endif // TAB_THEATRES_H
