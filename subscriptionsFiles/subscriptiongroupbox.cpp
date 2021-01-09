#include "subscriptiongroupbox.h"
#include <QDebug>
#include <QMessageBox>
#include "database.h"

SubscriptionGroupBox::SubscriptionGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(435, 407));
    this->setMaximumSize(QSize(435, 407));

    SubscriptionBox = new QFrame(this);
    SubscriptionBox->setObjectName(QStringLiteral("SubscriptionBox"));
    SubscriptionBox->setMinimumSize(QSize(435, 407));
    SubscriptionBox->setMaximumSize(QSize(435, 407));
    SubscriptionBox->setStyleSheet(QLatin1String("background-color:rgb(22, 160, 133);\n"
"border-radius: 20px;"));
    SubscriptionBox->setFrameShape(QFrame::StyledPanel);
    SubscriptionBox->setFrameShadow(QFrame::Raised);
    SubscriptionUpdateButton = new QPushButton(SubscriptionBox);
    SubscriptionUpdateButton->setText("Update");
    SubscriptionUpdateButton->setObjectName(QStringLiteral("SubscriptionUpdateButton"));
    SubscriptionUpdateButton->setGeometry(QRect(230, 370, 93, 28));
    SubscriptionUpdateButton->setStyleSheet(QLatin1String("background-color:rgb(230, 126, 34);\n"
"border-radius:5px;\n"
"color:white;"));
    SubscriptionDeleteButton = new QPushButton(SubscriptionBox);
    SubscriptionDeleteButton->setText("Delete");
    SubscriptionDeleteButton->setObjectName(QStringLiteral("SubscriptionDeleteButton"));
    SubscriptionDeleteButton->setGeometry(QRect(330, 370, 93, 28));
    SubscriptionDeleteButton->setStyleSheet(QLatin1String("background-color:rgb(231, 76, 60);\n"
"border-radius:5px;\n"
"color:white;"));
    SubscriptionIdTitleEdit = new QLabel(SubscriptionBox);
    SubscriptionIdTitleEdit->setText("ID");
    SubscriptionIdTitleEdit->setObjectName(QStringLiteral("SubscriptionIdTitleEdit"));
    SubscriptionIdTitleEdit->setGeometry(QRect(380, 70, 21, 16));
    SubscriptionIdTitleEdit->setStyleSheet(QStringLiteral("color:#fff"));
    SubscriptionId = new QLabel(SubscriptionBox);
    SubscriptionId->setObjectName(QStringLiteral("SubscriptionId"));
    SubscriptionId->setGeometry(QRect(400, 70, 21, 16));
    SubscriptionId->setStyleSheet(QStringLiteral("color:#fff"));
    SubscriptionNumberOfDaysEditTitle = new QLabel(SubscriptionBox);
    SubscriptionNumberOfDaysEditTitle->setText("Number Of Days");
    SubscriptionNumberOfDaysEditTitle->setObjectName(QStringLiteral("SubscriptionNumberOfDaysEditTitle"));
    SubscriptionNumberOfDaysEditTitle->setGeometry(QRect(51, 140, 141, 17));
    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    SubscriptionNumberOfDaysEditTitle->setFont(font1);
    SubscriptionNumberOfDaysEditTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    SubscriptionNumberOfDaysEdit = new QLineEdit(SubscriptionBox);
    SubscriptionNumberOfDaysEdit->setObjectName(QStringLiteral("SubscriptionNumberOfDaysEdit"));
    SubscriptionNumberOfDaysEdit->setGeometry(QRect(240, 141, 61, 21));
    SubscriptionNumberOfDaysEdit->setFont(font1);
    SubscriptionNumberOfDaysEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    SubscriptionFreeFoodEdit = new QCheckBox(SubscriptionBox);
    SubscriptionFreeFoodEdit->setObjectName(QStringLiteral("SubscriptionFreeFoodEdit"));
    SubscriptionFreeFoodEdit->setGeometry(QRect(250, 180, 31, 16));
    SubscriptionFreeFoodEdit->setStyleSheet(QLatin1String("QCheckBox\n"
"{\n"
"	color:white;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    border: 1px solid #ffffff;\n"
"	border-radius: 5px;\n"
"	\n"
"	border-color: rgb(249, 167, 43);\n"
"    background: none;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"    border: 0px solid #5A5A5A;\n"
"	border-radius: 5px;\n"
"\n"
"    background: qradialgradient(spread:pad, cx:0.494, cy:0.528182, radius:2, fx:0.494, fy:0.528, stop:0.153409 rgba(255, 171, 44, 255), stop:0.3125 rgba(252, 128, 128, 0));\n"
"}\n"
""));
    SubscriptionFreeFoodTitleEdit = new QLabel(SubscriptionBox);
    SubscriptionFreeFoodTitleEdit->setText("Free Food");
    SubscriptionFreeFoodTitleEdit->setObjectName(QStringLiteral("SubscriptionFreeFoodTitleEdit"));
    SubscriptionFreeFoodTitleEdit->setGeometry(QRect(50, 180, 131, 17));
    SubscriptionFreeFoodTitleEdit->setFont(font1);
    SubscriptionFreeFoodTitleEdit->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    SubscriptionPriceDT = new QLabel(SubscriptionBox);
    SubscriptionPriceDT->setText("DT");
    SubscriptionPriceDT->setObjectName(QStringLiteral("SubscriptionPriceDT"));
    SubscriptionPriceDT->setGeometry(QRect(230, 290, 101, 51));
    QFont font18;
    font18.setFamily(QStringLiteral("Segoe Script"));
    font18.setPointSize(36);
    SubscriptionPriceDT->setFont(font18);
    SubscriptionPriceDT->setStyleSheet(QStringLiteral("color:#fff"));
    SubscriptionPriceDT->setAlignment(Qt::AlignCenter);
    SubscriptionPriceEdit = new QLineEdit(SubscriptionBox);
    SubscriptionPriceEdit->setObjectName(QStringLiteral("SubscriptionPriceEdit"));
    SubscriptionPriceEdit->setGeometry(QRect(110, 200, 121, 221));
    QFont font19;
    font19.setFamily(QStringLiteral("Ink Free"));
    font19.setPointSize(36);
    font19.setBold(false);
    font19.setWeight(50);
    SubscriptionPriceEdit->setFont(font19);
    SubscriptionPriceEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    SubscriptionNameEdit = new QLineEdit(SubscriptionBox);
    SubscriptionNameEdit->setObjectName(QStringLiteral("SubscriptionNameEdit"));
    SubscriptionNameEdit->setGeometry(QRect(0, -10, 441, 81));
    SubscriptionNameEdit->setFont(font19);
    SubscriptionNameEdit->setLayoutDirection(Qt::RightToLeft);
    SubscriptionNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    SubscriptionNameEdit->setAlignment(Qt::AlignCenter);

    connect(SubscriptionUpdateButton,SIGNAL(clicked()),this,SLOT(UpdateSubscriptionSlot()));
    connect(SubscriptionDeleteButton,SIGNAL(clicked()),this,SLOT(DeleteSubscriptionSlot()));

}

void SubscriptionGroupBox::UpdateSubscriptionSlot()
{
    qDebug() << "UPDATE Subscription";
        QSqlQuery qry;
        qry.prepare("UPDATE Subscriptions SET name=:name, price=:price, number_of_days=:number_of_days, free_food=:free_food WHERE id=:id ");
        int FreeFood = 1;
        if(SubscriptionFreeFoodEdit->isChecked())
        {
            FreeFood = 0;
        }
        qry.bindValue(":name",SubscriptionNameEdit->text());
        qry.bindValue(":price",SubscriptionPriceEdit->text());
        qry.bindValue(":number_of_days",SubscriptionNumberOfDaysEdit->text());
        qry.bindValue(":free_food",FreeFood);
        qry.bindValue(":id",SubscriptionId->text());

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"UPDATE Subscription","DONE!");
        }
}

void SubscriptionGroupBox::DeleteSubscriptionSlot()
{
    qDebug() << "DELETE subscription FROM DATA BASE";
        QSqlQuery qry;
        qry.prepare("DELETE FROM subscriptions WHERE id=:id ");
        qry.bindValue(":id",SubscriptionId->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE Subscription","DONE!");
        }
        delete this;
}
