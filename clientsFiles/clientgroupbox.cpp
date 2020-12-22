#include "clientgroupbox.h"
#include "database.h"
#include <QMessageBox>

ClientGroupBox::ClientGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(100, 40));
    this->setMaximumSize(QSize(16777215, 40));

    ClientBox = new QGroupBox(this);
    ClientBox->setObjectName(QStringLiteral("ClientBox"));
    ClientBox->setMinimumSize(QSize(100, 40));
    ClientBox->setMaximumSize(QSize(16777215, 40));
    ClientBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"\n"
"     border: 0px solid rgb(249, 167, 43); \n"
"     border-radius: 0px; \n"
"	border-bottom-width:1px;	\n"
"\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"}"));
    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    ClientSubscriptionIdEdit = new QLineEdit(ClientBox);
    ClientSubscriptionIdEdit->setObjectName(QStringLiteral("ClientSubscriptionIdEdit"));
    ClientSubscriptionIdEdit->setGeometry(QRect(420, 10, 141, 26));
    ClientSubscriptionIdEdit->setFont(font1);
    ClientSubscriptionIdEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    ClientEmailEdit = new QLineEdit(ClientBox);
    ClientEmailEdit->setObjectName(QStringLiteral("ClientEmailEdit"));
    ClientEmailEdit->setGeometry(QRect(260, 10, 141, 26));
    ClientEmailEdit->setFont(font1);
    ClientEmailEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    ClientNameEdit = new QLineEdit(ClientBox);
    ClientNameEdit->setObjectName(QStringLiteral("ClientNameEdit"));
    ClientNameEdit->setGeometry(QRect(80, 10, 141, 26));
    ClientNameEdit->setFont(font1);
    ClientNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    ClientId = new QLabel(ClientBox);
    ClientId->setObjectName(QStringLiteral("ClientId"));
    ClientId->setGeometry(QRect(10, 5, 55, 31));
    ClientId->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    ClientSubscriptionDateEdit = new QDateEdit(ClientBox);
    ClientSubscriptionDateEdit->setObjectName(QStringLiteral("ClientSubscriptionDateEdit"));
    ClientSubscriptionDateEdit->setGeometry(QRect(610, 10, 110, 22));
    ClientSubscriptionDateEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    ClientUpdateButton = new QPushButton(ClientBox);
    ClientUpdateButton->setObjectName(QStringLiteral("ClientUpdateButton"));
    ClientUpdateButton->setGeometry(QRect(750, 10, 91, 20));
    ClientUpdateButton->setText("Update");
    ClientUpdateButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
""));
    ClientDeleteButton = new QPushButton(ClientBox);
    ClientDeleteButton->setObjectName(QStringLiteral("ClientDeleteButton"));
    ClientDeleteButton->setGeometry(QRect(850, 10, 91, 20));
    ClientDeleteButton->setText("Delete");
    ClientDeleteButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:rgb(50, 53, 57);\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:#ffffff;\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(255, 0, 4);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(255, 0, 4);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
""));

    connect(ClientUpdateButton,SIGNAL(clicked()),this,SLOT(UpdateClientSlot()));
    connect(ClientDeleteButton,SIGNAL(clicked()),this,SLOT(DeleteClientSlot()));
}

void ClientGroupBox::UpdateClientSlot()
{
    qDebug() << "UPDATE CLIENT";
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;

        qry.prepare("UPDATE employees SET name=:name, email=:email, subscription_id=:subscription_id, subscription_date=:subscription_date WHERE id=:id ");

        qry.bindValue(":name",    ClientNameEdit    ->text()        );
        qry.bindValue(":email",   ClientEmailEdit   ->text()        );
        qry.bindValue(":subscription_id",ClientSubscriptionIdEdit->text()        );
        qry.bindValue(":subscription_date",ClientSubscriptionDateEdit->date()        );

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"UPDATE CLIENT","DONE!");
        }
    }

}

void ClientGroupBox::DeleteClientSlot()
{
    qDebug() << "DELETE CLIENT FROM DATA BASE";
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;
        qry.prepare("DELETE FROM clients WHERE id=:id ");
        qry.bindValue(":id",ClientId->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE Client","DONE!");
        }
        delete this;
    }
}
