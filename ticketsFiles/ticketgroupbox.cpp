#include "ticketgroupbox.h"
#include <QDebug>
#include "database.h"
#include <QMessageBox>
TicketGroupBox::TicketGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(100, 40));
    this->setMaximumSize(QSize(16777215, 40));

    TicketBox = new QGroupBox(this);
    TicketBox->setObjectName(QStringLiteral("TicketBox"));
    TicketBox->setMinimumSize(QSize(100, 40));
    TicketBox->setMaximumSize(QSize(16777215, 40));
    TicketBox->setStyleSheet(QLatin1String("QGroupBox\n{\n\n     border: 0px solid white; \n     border-radius: 0px; \n	border-bottom-width:1px;	\n	border-color:rgb(130, 135, 144);\n}\n\nQGroupBox::title\n{\ncolor: rgb(255, 255, 255);\n}"));
    TicketDeleteButton = new QPushButton(TicketBox);
    TicketDeleteButton->setObjectName(QStringLiteral("TicketDeleteButton"));
    TicketDeleteButton->setGeometry(QRect(880, 0, 61, 31));
    TicketDeleteButton->setText("Delete");
    TicketDeleteButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color:red;\n	/*color:rgb(30, 227, 0);*/\n}\n\nQPushButton:focus\n{\n	background-color:  red;\n	border-color: red;\n	color:rgb(255, 255, 255);\n}\n"));
    TicketUpdateButton = new QPushButton(TicketBox);
    TicketUpdateButton->setObjectName(QStringLiteral("TicketUpdateButton"));
    TicketUpdateButton->setGeometry(QRect(815, 0, 61, 31));
    TicketUpdateButton->setText("Update");
    TicketUpdateButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color:#00ff00;\n	/*color:rgb(30, 227, 0);*/\n}\n\nQPushButton:focus\n{\n	background-color:#00ff00;\n	border-color: #00ff00;\n	color:rgb(255, 255, 255);\n}\n"));
    TicketId = new QLabel(TicketBox);
    TicketId->setObjectName(QStringLiteral("TicketId"));
    TicketId->setGeometry(QRect(1, 10, 135, 16));
    TicketId->setMinimumSize(QSize(135, 0));
    TicketId->setMaximumSize(QSize(135, 16777215));
    QFont font14;
    font14.setFamily(QStringLiteral("Bahnschrift Light"));
    font14.setPointSize(9);
    font14.setBold(false);
    font14.setWeight(50);
    TicketId->setFont(font14);
    TicketId->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    TicketId->setAlignment(Qt::AlignCenter);
    //TicketShowId->setFont(font14);
    //TicketShowId->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    //TicketShowId->setAlignment(Qt::AlignCenter);
    TicketShowId = new QLineEdit(TicketBox);
    TicketShowId->setObjectName(QStringLiteral("TicketShowId"));
    TicketShowId->setGeometry(QRect(140, 7, 41, 16));
    TicketShowId->setMinimumSize(QSize(10, 0));
    TicketShowId->setMaximumSize(QSize(135, 16777215));
    TicketShowId->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);"));
    TicketVIP = new QCheckBox(TicketBox);
    TicketVIP->setObjectName(QStringLiteral("TicketVIP"));
    TicketVIP->setGeometry(QRect(240, 9, 16, 16));
    TicketVIP->setMinimumSize(QSize(0, 0));
    TicketVIP->setMaximumSize(QSize(122, 16777215));
    TicketVIP->setStyleSheet(QLatin1String("QCheckBox\n{\n	color:white;\n}\nQCheckBox::indicator:unchecked {\n    border: 1px solid #ffffff;\n	border-radius: 5px;\n	\n	border-color: rgb(249, 167, 43);\n    background: none;\n}\nQCheckBox::indicator:checked {\n    border: 0px solid #5A5A5A;\n	border-radius: 5px;\n\n    background: qradialgradient(spread:pad, cx:0.494, cy:0.528182, radius:2, fx:0.494, fy:0.528, stop:0.153409 rgba(255, 171, 44, 255), stop:0.3125 rgba(252, 128, 128, 0));\n}\n"));
    TicketVIP->setTristate(false);

    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    TicketBuyerEmail = new QLineEdit(TicketBox);
    TicketBuyerEmail->setObjectName(QStringLiteral("TicketEmail"));
    TicketBuyerEmail->setGeometry(QRect(350, 7, 131, 17));
    TicketBuyerEmail->setMinimumSize(QSize(100, 0));
    TicketBuyerEmail->setMaximumSize(QSize(300, 16777215));
    TicketBuyerEmail->setFont(font14);
    TicketBuyerEmail->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 1px;\nborder-radius: 5px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));

    TicketPrice = new QLabel(TicketBox);
    TicketPrice->setObjectName(QStringLiteral("TicketPrice"));
    TicketPrice->setGeometry(QRect(700, 10, 41, 16));
    QFont font15;
    font15.setFamily(QStringLiteral("Bahnschrift Light"));
    font15.setPointSize(9);
    TicketPrice->setFont(font15);
    TicketPrice->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    connect(TicketUpdateButton,SIGNAL(clicked()),this,SLOT(UpdateTicketSlot()));
    connect(TicketDeleteButton,SIGNAL(clicked()),this,SLOT(DeleteTicketSlot()));
}
TicketGroupBox::~TicketGroupBox()
{
    qDebug() << "DELETE TicketGroupBox";
}
void TicketGroupBox::UpdateTicketSlot()
{
    qDebug() << "UPDATE Ticket";
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;
        qry.prepare("UPDATE tickets SET vip_seat=:vip_seat, price=:price, buyer_email=:buyer_email, show_id=:show_id WHERE id=:id ");
        QString VIP = "1";
        if(TicketVIP->isChecked())
        {
            VIP = "0";
        }
        qry.bindValue(":vip_seat",VIP);
        qry.bindValue(":price",TicketPrice->text());
        qry.bindValue(":buyer_email",TicketBuyerEmail->text());
        qry.bindValue(":show_id",TicketShowId->text());
        qry.bindValue(":id",TicketId->text());

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"UPDATE Ticket","DONE!");
        }
    }

}

void TicketGroupBox::DeleteTicketSlot()
{
    qDebug() << "DELETE ticket FROM DATA BASE";
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;
        qry.prepare("DELETE FROM tickets WHERE id=:id ");
        qry.bindValue(":id",TicketId->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE Ticket","DONE!");
        }
        delete this;
    }
}
