#ifndef MOVIE_H
#define MOVIE_H
#include <QString>
#include <QVector>
#include "ui_mainwindow.h"
#include "moviegroupbox.h"
class movie
{
public:
    movie();
    movie(QString, QString, QString, QString, QString, bool, bool, bool,Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void StoreInDatabase();
    void Display();
    QString id;
    QString name;
    QString type;
    QString price;
    QString description;
    bool ar;
    bool fr;
    bool en;
    MovieGroupBox* DisplayBox;
};
#endif // MOVIE_H
