#include "database.h"

database::database()
{

    db = QSqlDatabase::addDatabase("QODBC");
    //db.setHostName("sql7.freesqldatabase.com");
    db.setUserName("system");
    db.setPassword("0000");
    db.setDatabaseName("SC_DATA");


    if(db.open()){qDebug()<<"Database opened!";}
    else{qDebug() << db.lastError().text();}

}

database::~database()
{

}

database *database::Instance = nullptr;
