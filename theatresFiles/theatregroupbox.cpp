#include "theatregroupbox.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>

TheatreGroupBox::TheatreGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(391, 341));
    this->setMaximumSize(QSize(391, 295));

    TheatreBox = new QGroupBox(this);
    TheatreBox->setObjectName(QStringLiteral("TheatreBox"));
    TheatreBox->setMinimumSize(QSize(391, 341));
    TheatreBox->setMaximumSize(QSize(391, 295));
    TheatreBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"	background-color: rgba(255, 255, 255, 220);\n"
"border: 1px solid rgb(249, 167, 43);\n"
"/*border-left-width: 1px;*/\n"
"border-bottom-width: 1px;\n"
"border-radius: 20px;\n"
"}"));
    QFont font13;
    font13.setFamily(QStringLiteral("Yu Gothic UI Semilight"));
    font13.setPointSize(14);
    TheatreIdEdit = new QLabel(TheatreBox);
    TheatreIdEdit->setObjectName(QStringLiteral("TheatreIdEdit"));
    TheatreIdEdit->setGeometry(QRect(180, 0, 104, 31));
    TheatreIdEdit->setFont(font13);
    TheatreIdEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    TheatreNameEditTitle = new QLabel(TheatreBox);
    TheatreNameEditTitle->setText("NAME");
    TheatreNameEditTitle->setObjectName(QStringLiteral("TheatreNameEditTitle"));
    TheatreNameEditTitle->setGeometry(QRect(40, 60, 71, 31));
    TheatreNameEditTitle->setFont(font13);
    TheatreNameEditTitle->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    TheatreSeatsEditTitle = new QLabel(TheatreBox);
    TheatreSeatsEditTitle->setText("SEATS");
    TheatreSeatsEditTitle->setObjectName(QStringLiteral("TheatreSeatsEditTitle"));
    TheatreSeatsEditTitle->setGeometry(QRect(40, 110, 71, 31));
    TheatreSeatsEditTitle->setFont(font13);
    TheatreSeatsEditTitle->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    TheatreSeatsEdit = new QLineEdit(TheatreBox);
    TheatreSeatsEdit->setObjectName(QStringLiteral("TheatreSeatsEdit"));
    TheatreSeatsEdit->setGeometry(QRect(170, 110, 174, 31));
    TheatreSeatsEdit->setMaximumSize(QSize(16777215, 100));
    QFont font2;
    font2.setFamily(QStringLiteral("Arial Black"));
    font2.setPointSize(9);
    font2.setBold(true);
    font2.setWeight(75);
    TheatreSeatsEdit->setFont(font2);
    TheatreSeatsEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 0, 0);"));
    TheatreVIP_SeatsEdit = new QLineEdit(TheatreBox);
    TheatreVIP_SeatsEdit->setObjectName(QStringLiteral("TheatreVIP_SeatsEdit"));
    TheatreVIP_SeatsEdit->setGeometry(QRect(170, 160, 174, 31));
    TheatreVIP_SeatsEdit->setMaximumSize(QSize(16777215, 100));
    TheatreVIP_SeatsEdit->setFont(font2);
    TheatreVIP_SeatsEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 0, 0);"));
    TheatreVIP_SeatsEditTitle = new QLabel(TheatreBox);
    TheatreVIP_SeatsEditTitle->setText("VIP SEATS");
    TheatreVIP_SeatsEditTitle->setObjectName(QStringLiteral("TheatreVIP_SeatsEditTitle"));
    TheatreVIP_SeatsEditTitle->setGeometry(QRect(40, 160, 111, 31));
    TheatreVIP_SeatsEditTitle->setFont(font13);
    TheatreVIP_SeatsEditTitle->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
    TheatreUpdateButton = new QPushButton(TheatreBox);
    TheatreUpdateButton->setText("Update");
    TheatreUpdateButton->setObjectName(QStringLiteral("TheatreUpdateButton"));
    TheatreUpdateButton->setGeometry(QRect(13, 214, 361, 21));
    TheatreUpdateButton->setStyleSheet(QLatin1String("QPushButton\n"
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
"\n"
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
    TheatreDeleteButton = new QPushButton(TheatreBox);
    TheatreDeleteButton->setText("Delete");
    TheatreDeleteButton->setObjectName(QStringLiteral("TheatreDeleteButton"));
    TheatreDeleteButton->setGeometry(QRect(13, 250, 361, 21));
    TheatreDeleteButton->setStyleSheet(QLatin1String("QPushButton\n"
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
"	border-color:red;\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  red;\n"
"	border-color: red;\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
""));
    TheatreNameEdit = new QLineEdit(TheatreBox);
    TheatreNameEdit->setObjectName(QStringLiteral("TheatreNameEdit"));
    TheatreNameEdit->setGeometry(QRect(170, 60, 174, 31));
    TheatreNameEdit->setMaximumSize(QSize(16777215, 100));
    TheatreNameEdit->setFont(font2);
    TheatreNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 0, 0);"));
    TheatreIdEditTitle = new QLabel(TheatreBox);
    TheatreIdEditTitle->setText("ID");
    TheatreIdEditTitle->setObjectName(QStringLiteral("TheatreIdEditTitle"));
    TheatreIdEditTitle->setGeometry(QRect(150, 0, 21, 31));
    TheatreIdEditTitle->setFont(font13);
    TheatreIdEditTitle->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

    connect(TheatreUpdateButton,SIGNAL(clicked()),this,SLOT(UpdateTheatreSlot()));
    connect(TheatreDeleteButton,SIGNAL(clicked()),this,SLOT(DeleteTheatreSlot()));

}
void TheatreGroupBox::UpdateTheatreSlot()
{
    qDebug() << "UPDATE Theatre";
        QSqlQuery qry;
        qry.prepare("UPDATE theatres SET name=:name, seats=:seats, vip_seats=:vip_seats WHERE id=:id ");
        qry.bindValue(":name",      TheatreNameEdit->text());
        qry.bindValue(":seats",      TheatreSeatsEdit->text().toInt());
        qry.bindValue(":vip_seats", TheatreVIP_SeatsEdit->text().toInt());
        qry.bindValue(":id",        TheatreIdEdit->text().toInt());

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"UPDATE Theatre","DONE!");
        }
}

void TheatreGroupBox::DeleteTheatreSlot()
{
    qDebug() << "DELETE theatre FROM DATA BASE";
        QSqlQuery qry;
        qry.prepare("DELETE FROM theatres WHERE id=:id ");
        qry.bindValue(":id",TheatreIdEdit->text().toInt());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE theatre","DONE!");
        }
        delete this;
}
