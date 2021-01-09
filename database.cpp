#include "database.h"



Connection::Connection(){}

bool Connection::CreateConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    //db.setHostName("sql7.freesqldatabase.com");
    db.setUserName("system");
    db.setPassword("0000");
    db.setDatabaseName("SC_DATA");


    if(db.open())
    {
        qDebug()<<"Database opened!";
        test = true;
    }
    else
    {
        qDebug() << db.lastError().text();
    }

    return test;
}


void Connection::CloseConnection()
{
    db.close();
}
