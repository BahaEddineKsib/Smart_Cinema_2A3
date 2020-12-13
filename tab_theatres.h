#ifndef TAB_THEATRES_H
#define TAB_THEATRES_H

#include <QSqlDatabase>
#include <QtSql>

#include "ui_mainwindow.h"

class tab_theatres
{
public:
    tab_theatres(Ui::MainWindow *ui);
    Ui::MainWindow *ui;

    void show_theatres();

    void add_theatre();
    void show_add_theatre();
    void hide_add_theatre();
private slots:

};

#endif // TAB_THEATRES_H
