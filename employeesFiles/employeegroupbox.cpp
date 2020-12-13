#include "employeegroupbox.h"
#include "..\database.h"
#include <QMessageBox>
EmployeeGroupBox::EmployeeGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(100, 155));
    this->setMaximumSize(QSize(16777215, 155));

    EmployesBox = new QGroupBox(this);
    EmployesBox->setObjectName(QStringLiteral("EmployesBox"));
    EmployesBox->setMinimumSize(QSize(100, 155));
    EmployesBox->setMaximumSize(QSize(16777215, 155));
    EmployesBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"\n"
"     border: 0px solid white; \n"
"     border-radius: 0px; \n"
"	border-bottom-width:2px;	\n"
"	border-color:rgb(249, 167, 43)\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"}"));
    EmployeeUpdateButton = new QPushButton(EmployesBox);
    EmployeeUpdateButton->setObjectName(QStringLiteral("EmployeeUpdateButton"));
    EmployeeUpdateButton->setGeometry(QRect(340, 130, 111, 20));
    EmployeeUpdateButton->setText("update");
    EmployeeUpdateButton->setStyleSheet(QLatin1String("QPushButton\n"
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
    EmployeeDeleteButton = new QPushButton(EmployesBox);
    EmployeeDeleteButton->setObjectName(QStringLiteral("EmployeeDeleteButton"));
    EmployeeDeleteButton->setGeometry(QRect(460, 130, 111, 20));
    EmployeeDeleteButton->setText("delete");
    EmployeeDeleteButton->setStyleSheet(QLatin1String("QPushButton\n"
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
    EmployeePhotoButtonEdit = new QPushButton(EmployesBox);
    EmployeePhotoButtonEdit->setObjectName(QStringLiteral("EmployeePhotoButtonEdit"));
    EmployeePhotoButtonEdit->setGeometry(QRect(22, 17, 141, 121));
    EmployeePhotoButtonEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    QIcon icon1;
    icon1.addFile(QStringLiteral("../../Pictures/Camera Roll/WIN_20201128_23_54_27_Pro.jpg"), QSize(), QIcon::Normal, QIcon::Off);
    EmployeePhotoButtonEdit->setIcon(icon1);
    EmployeePhotoButtonEdit->setIconSize(QSize(200, 200));
    EmployeeNameEdit = new QLineEdit(EmployesBox);
    EmployeeNameEdit->setObjectName(QStringLiteral("EmployeeNameEdit"));
    EmployeeNameEdit->setGeometry(QRect(283, 35, 123, 20));
    QFont font10;
    font10.setFamily(QStringLiteral("Arial"));
    font10.setPointSize(9);
    font10.setBold(false);
    font10.setWeight(50);
    font10.setKerning(true);
    EmployeeNameEdit->setFont(font10);
    EmployeeNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 1px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    EmployeeNameTitle = new QLabel(EmployesBox);
    EmployeeNameTitle->setObjectName(QStringLiteral("EmployeeNameTitle"));
    EmployeeNameTitle->setGeometry(QRect(191, 34, 48, 22));
    EmployeeNameTitle->setFont(font1);
    EmployeeNameTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    EmployeeNameTitle->setText("Name");
    EmployeeEmailEdit = new QLineEdit(EmployesBox);
    EmployeeEmailEdit->setObjectName(QStringLiteral("EmployeeEmailEdit"));
    EmployeeEmailEdit->setGeometry(QRect(564, 35, 123, 20));
    QFont font11;
    font11.setFamily(QStringLiteral("Arial"));
    font11.setPointSize(9);
    font11.setBold(false);
    font11.setWeight(50);
    EmployeeEmailEdit->setFont(font11);
    EmployeeEmailEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 1px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    EmployeeContactTitle = new QLabel(EmployesBox);
    EmployeeContactTitle->setObjectName(QStringLiteral("EmployeeContactTitle"));
    EmployeeContactTitle->setGeometry(QRect(477, 34, 66, 22));
    EmployeeContactTitle->setFont(font1);
    EmployeeContactTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    EmployeeContactTitle->setText("Contact");
    EmployeeUsernameTitle = new QLabel(EmployesBox);
    EmployeeUsernameTitle->setObjectName(QStringLiteral("EmployeeUsernameTitle"));
    EmployeeUsernameTitle->setGeometry(QRect(191, 66, 85, 22));
    EmployeeUsernameTitle->setFont(font1);
    EmployeeUsernameTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    EmployeeUsernameTitle->setText("Username");
    EmployeeUsernameEdit = new QLineEdit(EmployesBox);
    EmployeeUsernameEdit->setObjectName(QStringLiteral("EmployeeUsernameEdit"));
    EmployeeUsernameEdit->setGeometry(QRect(283, 67, 123, 20));
    EmployeeUsernameEdit->setFont(font11);
    EmployeeUsernameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 1px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    EmployeePasswordTitle = new QLabel(EmployesBox);
    EmployeePasswordTitle->setObjectName(QStringLiteral("EmployeePasswordTitle"));
    EmployeePasswordTitle->setGeometry(QRect(477, 66, 80, 22));
    EmployeePasswordTitle->setFont(font1);
    EmployeePasswordTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    EmployeePasswordTitle->setText("Password");
    EmployeePasswordEdit = new QLineEdit(EmployesBox);
    EmployeePasswordEdit->setObjectName(QStringLiteral("EmployeePasswordEdit"));
    EmployeePasswordEdit->setGeometry(QRect(564, 67, 123, 20));
    EmployeePasswordEdit->setFont(font11);
    EmployeePasswordEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 1px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    EmployeeAccessCombo = new QComboBox(EmployesBox);
    EmployeeAccessCombo->setObjectName(QStringLiteral("EmployeeAccessCombo"));
    EmployeeAccessCombo->setGeometry(QRect(191, 98, 491, 18));
    EmployeeAccessCombo->setMinimumSize(QSize(90, 0));
    EmployeeAccessCombo->addItem("EMPLOYEE");
    EmployeeAccessCombo->addItem("MANAGER");
    EmployeeAccessCombo->setStyleSheet(QLatin1String("QComboBox {\n"
"	border: 0px solid #333333;\n"
"\n"
"	background: #00000000;\n"
"	color: #ffffff;\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	color: #ffffff;\n"
"\n"
"\n"
"}\n"
"QComboBox::down-arrow {\n"
"	color: #ffffff;\n"
"\n"
"\n"
"}\n"
" \n"
"QComboBox QAbstractItemView{\n"
"	/*background-color: #4f4f4f;\n"
"	color: #999999;*/\n"
" 	color: #ffffff;\n"
"	/*selection-background-color: #999999;\n"
"	selection-color: #4f4f4f;*/\n"
"}\n"
""));
    QFont font9;
    font9.setFamily(QStringLiteral("Yu Gothic UI Semilight"));
    font9.setPointSize(20);
    EmployeeIdTitle = new QLabel(EmployesBox);
    EmployeeIdTitle->setObjectName(QStringLiteral("EmployeeIdTitle"));
    EmployeeIdTitle->setGeometry(QRect(361, -9, 31, 45));
    EmployeeIdTitle->setFont(font9);
    EmployeeIdTitle->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    EmployeeIdTitle->setText("ID");
    EmployeeId = new QLabel(EmployesBox);
    EmployeeId->setObjectName(QStringLiteral("EmployeeId"));
    EmployeeId->setGeometry(QRect(399, -9, 138, 45));
    EmployeeId->setFont(font9);
    EmployeeId->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

    connect(EmployeeUpdateButton,SIGNAL(clicked()),this,SLOT(UpdateEmployeeSlot()));
    connect(EmployeeDeleteButton,SIGNAL(clicked()),this,SLOT(DeleteEmployeeSlot()));
}
void EmployeeGroupBox::UpdateEmployeeSlot()
{
    qDebug() << "UPDATE EMPLOYEE";
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;

        qry.prepare("UPDATE employees SET name=:name, email=:email, username=:username, password=:password, role=:role WHERE id=:id ");

        qry.bindValue(":name",    EmployeeNameEdit    ->text()        );
        qry.bindValue(":email",   EmployeeEmailEdit   ->text()        );
        qry.bindValue(":username",EmployeeUsernameEdit->text()        );
        qry.bindValue(":password",EmployeePasswordEdit->text()        );
        qry.bindValue(":role",    EmployeeAccessCombo ->currentText() );
        qry.bindValue(":id",      EmployeeId          ->text()        );

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"UPDATE EMPLOYEE","DONE!");
        }
    }

}

void EmployeeGroupBox::DeleteEmployeeSlot()
{
    qDebug() << "DELETE EMPLOYEE FROM DATA BASE";
    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;
        qry.prepare("DELETE FROM employees WHERE id=:id ");
        qry.bindValue(":id",EmployeeId->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE Employee","DONE!");
        }
        delete this;
    }
}
