#include "database.h"

database::database()
{

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql7.freesqldatabase.com");
    db.setUserName("sql7377608");
    db.setPassword("SeJMMSScDF");
    db.setDatabaseName("sql7377608");


    if(db.open()){qDebug()<<"Database opened!";}
    else{qDebug() << db.lastError().text();}

}

database::~database()
{

}

database *database::Instance = nullptr;
