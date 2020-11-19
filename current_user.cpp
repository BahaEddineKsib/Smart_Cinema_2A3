#include "current_user.h"
#include <QSqlDatabase>
#include <QtSql>


current_user::current_user()
{
    id=0;
    role=0;
    username="usrnm";
    password="pswrd";
    f_name="first";
    l_name="last";
    online=0;

}

current_user::~current_user()
{

}

current_user *current_user::Instance = nullptr;

void current_user::reset()
{
    id=0;
    role=0;
    username="usrnm";
    password="pswrd";
    f_name="first";
    l_name="last";
    online=0;
}

void current_user::setUser(int id)
{


    QSqlQuery qry;
    qry.prepare("SELECT * FROM  users WHERE id = :id");
    qry.bindValue(":id",id);

    if(!qry.exec())
    {

    }
    else
    {
        while(qry.next())
        {
            int db_id=qry.value(0).toInt();
            if(db_id==id)
            {
                role=qry.value(1).toInt();
                username=qry.value(2).toString();
                f_name=qry.value(4).toString();
                l_name=qry.value(5).toString();
            }

        }

        qDebug()  << "Welcome "  << f_name << " " << l_name  << ".\n";
    }

}


