#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QtSql>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool CreateConnection();
    void CloseConnection() ;
};

#endif // DATABASE_H
