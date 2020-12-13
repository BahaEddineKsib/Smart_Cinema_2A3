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
    movie(QString, QString, QString, QString, QString, QString, QString, QString, Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    int StoreInDatabase();
    void Display();
    QString id;
    QString name;
    QString type;
    QString price;
    QString description;
    QString ImageLink;
    QString SubLaguage;
    QString DubLaguage;
    MovieGroupBox* DisplayBox;
};
#endif // MOVIE_H
