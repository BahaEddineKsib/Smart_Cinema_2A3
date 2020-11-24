#ifndef MOVIE_H
#define MOVIE_H
#include <QString>
#include <QVector>
#include "moviegroupbox.h"
class movie
{
public:
    movie();
    movie(QString, QString, QString, QString, QString, bool, bool, bool);
    void StoreInDatabase();
    QString id;
    QString name;
    QString type;
    QString price;
    QString description;
    bool ar;
    bool fr;
    bool en;
    MovieGroupBox DisplayBox;
};
QVector<movie> AllMovies;
#endif // MOVIE_H
