#include "clientgroupbox.h"
#include "database.h"
#include "tab_client.h"
#include <QMessageBox>
#include <QDebug>
#include <QLatin1String>
clientGroupBox::clientGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(381, 531));
    this->setMaximumSize(QSize(381, 531));
    qDebug() << "CREATE clientGroupBox";
    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    QFont font10;
    font10.setFamily(QStringLiteral("Yu Gothic UI Semilight"));
    font10.setPointSize(20);
    clientBox = new QGroupBox(this);
    clientBox->setMinimumSize(QSize(381, 531));
    clientBox->setMaximumSize(QSize(381, 531));
    clientImageButton = new QPushButton(clientBox);
    clientImageButton->setGeometry(QRect(5, 0, 371, 241));
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/new/prefix1/imgs/images.png"), QSize(), QIcon::Normal, QIcon::Off);
    clientImageButton->setIcon(icon1);
    clientImageButton->setIconSize(QSize(400, 400));
    clientImageButton->setStyleSheet(QLatin1String("border: 2px solid rgb(255, 255, 255);\nbackground-color:red;"));
    clientBottomBox = new QGroupBox(clientBox);
    clientBottomBox->setGeometry(QRect(0, 197, 381, 331));
    clientBottomBox->setStyleSheet(QLatin1String("QGroupBox\n{\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(59, 62, 66, 255), stop:1 rgba(255, 255, 255, 92));\nborder: 0px solid rgb(255, 255, 255);\nborder-bottom-width: 1px;\nborder-radius: 10px;\n}"));
    clientDetailsBox = new QGroupBox(clientBottomBox);
    clientDetailsBox->setEnabled(true);
    clientDetailsBox->setGeometry(QRect(0, 40, 381, 291));
    clientDetailsBox->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    clientEmailEdit = new QLineEdit(clientDetailsBox);
   clientEmailEdit->setGeometry(QRect(122, 98, 140, 21));
    clientEmailEdit->setFont(font1);
   clientEmailEdit->setText("Email");
  clientEmailEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
    clientNameTitle = new QLabel(clientDetailsBox);
   clientNameTitle->setGeometry(QRect(1, 44, 38, 17));
    clientNameTitle->setFont(font1);
    clientNameTitle->setText("Name");
   clientNameTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
   clientEmailTitle = new QLabel(clientDetailsBox);
  clientEmailTitle->setGeometry(QRect(1, 98, 50, 17));
  clientEmailTitle->setFont(font1);
   clientEmailEdit->setText("Email");
   clientEmailTitle->setText("Email");
 clientEmailTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
clientDT = new QLabel(clientDetailsBox);
   clientDT->setGeometry(QRect(240, 98, 18, 17));
   clientDT->setFont(font1);
    clientDT->setText("DT");
   clientDT->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    clientIdTitle = new QLabel(clientDetailsBox);
    clientIdTitle->setGeometry(QRect(1, 1, 30, 37));
    clientIdTitle->setFont(font10);
    clientIdTitle->setText("ID");
    clientIdTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    clientIdEdit = new QLabel(clientDetailsBox);
    clientIdEdit->setGeometry(QRect(122, 9, 140, 21));
   clientIdEdit->setFont(font1);
    clientIdEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
      clientNameEdit = new QLineEdit(clientDetailsBox);
    clientNameEdit->setGeometry(QRect(122, 44, 140, 21));
    clientNameEdit->setFont(font1);
    clientNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
   clientUpdateButton = new QPushButton(clientDetailsBox);
    clientUpdateButton->setGeometry(QRect(11, 260, 171, 21));
    clientUpdateButton->setText("Update");
   clientUpdateButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color: rgb(30, 227, 0);\n}\n\nQPushButton:focus\n{\n	background-color:  rgb(30, 227, 0);\n	border-color: rgba(30, 227, 0,0);\n	color:rgb(255, 255, 255);\n}\n"));
     QFont font16;
    font16.setFamily(QStringLiteral("Segoe UI Semilight"));
    font16.setPointSize(11);
    clientDeleteButton = new QPushButton(clientDetailsBox);
    clientDeleteButton->setGeometry(QRect(200, 260, 171, 21));
    clientDeleteButton->setText("Delete");
    clientDeleteButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color:red;\n}\n\nQPushButton:focus\n{\n	background-color:  red;\n	border-color: red;\n	color:rgb(255, 255, 255);\n}\n"));
    clientSwipeButton = new QPushButton(clientBox);
   clientSwipeButton->setGeometry(QRect(0, 170, 381, 71));
    QFont font17;
    font17.setFamily(QStringLiteral("Candara Light"));
    font17.setPointSize(16);
    clientSwipeButton->setFont(font17);
    clientSwipeButton->setText("CLICK");
    clientSwipeButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:#00000000;\n	border-width:0px;\n	color:#ffffff;\n}\n\nQPushButton:hover\n{\n\n	color:rgb(30, 227, 0);\n}\n\nQPushButton:focus\n{\n\n	color:rgb(30, 227, 0);\n}\n"));
    connect(clientUpdateButton,SIGNAL(clicked()),this,SLOT(UpdateclientSlot()));
    connect(clientDeleteButton,SIGNAL(clicked()),this,SLOT(DeleteclientSlot()));
}
clientGroupBox::~clientGroupBox()
{
    qDebug() << "DELETE clientGroupBox";
}
void clientGroupBox::UpdateclientSlot()
{
    qDebug() << "UPDATE CLIENT";
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("UPDATE client SET name=:name, Email=:Email WHERE id=:id ");
        qry.bindValue(":name",        clientNameEdit->text());
        qry.bindValue(":Email",       clientEmailEdit->text());
        qry.bindValue(":id",          clientIdEdit->text());
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

void clientGroupBox::DeleteclientSlot()
{
    qDebug() << "DELETE CLIENT FROM DATA BASE";
    if(database::get()->db.open())
    {
        QSqlQuery qry;
        qry.prepare("DELETE FROM client WHERE id=:id ");
        qry.bindValue(":id",clientIdEdit->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE CLIENT","DONE!");
        }
        delete this;
    }
}
