#include "subscriptiongroupbox.h"
#include "database.h"
#include "tab_subscription.h"
#include <QMessageBox>
#include <QDebug>
#include <QLatin1String>
subscriptionGroupBox::subscriptionGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(381, 531));
    this->setMaximumSize(QSize(381, 531));
    qDebug() << "CREATE subscriptionGroupBox";
    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    QFont font10;
    font10.setFamily(QStringLiteral("Yu Gothic UI Semilight"));
    font10.setPointSize(20);
    subscriptionBox = new QGroupBox(this);
    subscriptionBox->setMinimumSize(QSize(381, 531));
    subscriptionBox->setMaximumSize(QSize(381, 531));
    subscriptionImageButton = new QPushButton(subscriptionBox);
    subscriptionImageButton->setGeometry(QRect(5, 0, 371, 241));
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/new/prefix1/imgs/sub.png"), QSize(), QIcon::Normal, QIcon::Off);
    subscriptionImageButton->setIcon(icon1);
    subscriptionImageButton->setIconSize(QSize(400, 400));
    subscriptionImageButton->setStyleSheet(QLatin1String("border: 2px solid rgb(255, 255, 255);\nbackground-color:red;"));
    subscriptionBottomBox = new QGroupBox(subscriptionBox);
    subscriptionBottomBox->setGeometry(QRect(0, 197, 381, 331));
    subscriptionBottomBox->setStyleSheet(QLatin1String("QGroupBox\n{\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(59, 62, 66, 255), stop:1 rgba(255, 255, 255, 92));\nborder: 0px solid rgb(255, 255, 255);\nborder-bottom-width: 1px;\nborder-radius: 10px;\n}"));
    subscriptionDetailsBox = new QGroupBox(subscriptionBottomBox);
    subscriptionDetailsBox->setEnabled(true);
    subscriptionDetailsBox->setGeometry(QRect(0, 40, 381, 291));
    subscriptionDetailsBox->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    subscriptionpriceEdit = new QLineEdit(subscriptionDetailsBox);
   subscriptionpriceEdit->setGeometry(QRect(122, 98, 140, 21));
    subscriptionpriceEdit->setFont(font1);
   subscriptionpriceEdit->setText("price");
  subscriptionpriceEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
   subscriptionNameTitle = new QLabel(subscriptionDetailsBox);
   subscriptionNameTitle->setGeometry(QRect(1, 44, 38, 17));
    subscriptionNameTitle->setFont(font1);
    subscriptionNameTitle->setText("Name");
   subscriptionNameTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
   subscriptionpriceTitle = new QLabel(subscriptionDetailsBox);
  subscriptionpriceTitle->setGeometry(QRect(1, 98, 50, 17));
  subscriptionpriceTitle->setFont(font1);
   subscriptionpriceEdit->setText("price");
   subscriptionpriceTitle->setText("price");
 subscriptionpriceTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
subscriptionDT = new QLabel(subscriptionDetailsBox);
   subscriptionDT->setGeometry(QRect(240, 98, 18, 17));
   subscriptionDT->setFont(font1);
    subscriptionDT->setText("DT");
   subscriptionDT->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    subscriptionIdTitle = new QLabel(subscriptionDetailsBox);
    subscriptionIdTitle->setGeometry(QRect(1, 1, 30, 37));
    subscriptionIdTitle->setFont(font10);
    subscriptionIdTitle->setText("ID");
    subscriptionIdTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    subscriptionIdEdit = new QLabel(subscriptionDetailsBox);
    subscriptionIdEdit->setGeometry(QRect(122, 9, 140, 21));
   subscriptionIdEdit->setFont(font1);
    subscriptionIdEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
      subscriptionNameEdit = new QLineEdit(subscriptionDetailsBox);
    subscriptionNameEdit->setGeometry(QRect(122, 44, 140, 21));
    subscriptionNameEdit->setFont(font1);
    subscriptionNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
   subscriptionUpdateButton = new QPushButton(subscriptionDetailsBox);
    subscriptionUpdateButton->setGeometry(QRect(11, 260, 171, 21));
    subscriptionUpdateButton->setText("Update");
   subscriptionUpdateButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color: rgb(30, 227, 0);\n}\n\nQPushButton:focus\n{\n	background-color:  rgb(30, 227, 0);\n	border-color: rgba(30, 227, 0,0);\n	color:rgb(255, 255, 255);\n}\n"));
     QFont font16;
    font16.setFamily(QStringLiteral("Segoe UI Semilight"));
    font16.setPointSize(11);
    subscriptionDeleteButton = new QPushButton(subscriptionDetailsBox);
    subscriptionDeleteButton->setGeometry(QRect(200, 260, 171, 21));
    subscriptionDeleteButton->setText("Delete");
    subscriptionDeleteButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color:red;\n}\n\nQPushButton:focus\n{\n	background-color:  red;\n	border-color: red;\n	color:rgb(255, 255, 255);\n}\n"));
    subscriptionSwipeButton = new QPushButton(subscriptionBox);
   subscriptionSwipeButton->setGeometry(QRect(0, 170, 381, 71));
    QFont font17;
    font17.setFamily(QStringLiteral("Candara Light"));
    font17.setPointSize(16);
    subscriptionSwipeButton->setFont(font17);
    subscriptionSwipeButton->setText("CLICK");
    subscriptionSwipeButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:#00000000;\n	border-width:0px;\n	color:#ffffff;\n}\n\nQPushButton:hover\n{\n\n	color:rgb(30, 227, 0);\n}\n\nQPushButton:focus\n{\n\n	color:rgb(30, 227, 0);\n}\n"));
    connect(subscriptionUpdateButton,SIGNAL(clicked()),this,SLOT(UpdatesubscriptionSlot()));
    connect(subscriptionDeleteButton,SIGNAL(clicked()),this,SLOT(DeletesubscriptionSlot()));
}
subscriptionGroupBox::~subscriptionGroupBox()
{
    qDebug() << "DELETE subscriptionGroupBox";
}
void subscriptionGroupBox::UpdatesubscriptionSlot()
{
    qDebug() << "UPDATE subscription";
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("UPDATE subscription SET name=:name, price=:price WHERE id=:id ");
        qry.bindValue(":name",        subscriptionNameEdit->text());
        qry.bindValue(":price",       subscriptionpriceEdit->text());
        qry.bindValue(":id",          subscriptionIdEdit->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"UPDATE subscription","DONE!");
        }
    }

}

void subscriptionGroupBox::DeletesubscriptionSlot()
{
    qDebug() << "DELETE subscription FROM DATA BASE";
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("DELETE FROM subscription WHERE id=:id ");
        qry.bindValue(":id",subscriptionIdEdit->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE subscription","DONE!");
        }
        delete this;
    }
}
