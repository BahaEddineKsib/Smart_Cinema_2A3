#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql>


class database
{
    static database *Instance; //singleton instance
    database();
public:
    static database *get()
    {
        if(!Instance)
            Instance = new database();
        return Instance;
    }
    virtual ~database();
    QSqlDatabase db;
};

#endif // DATABASE_H
