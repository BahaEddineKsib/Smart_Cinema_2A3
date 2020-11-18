#include "moviegroupbox.h"
#include <QDebug>
#include <QLatin1String>
MovieGroupBox::MovieGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(381, 531));
    this->setMaximumSize(QSize(381, 531));
    qDebug() << "SO WHAT THEN ?";
    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    QFont font10;
    font10.setFamily(QStringLiteral("Yu Gothic UI Semilight"));
    font10.setPointSize(20);
    MovieBox = new QGroupBox(this);
    MovieBox->setMinimumSize(QSize(381, 531));
    MovieBox->setMaximumSize(QSize(381, 531));
    MovieImageButton = new QPushButton(MovieBox);
    MovieImageButton->setObjectName(QStringLiteral("MovieImageButton"));
    MovieImageButton->setGeometry(QRect(5, 0, 371, 241));
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/new/prefix1/imgs/deadpool.png"), QSize(), QIcon::Normal, QIcon::Off);
    MovieImageButton->setIcon(icon1);
    MovieImageButton->setIconSize(QSize(400, 400));
    MovieImageButton->setStyleSheet(QLatin1String("border: 2px solid rgb(255, 255, 255);\n"
                                                  "background-color:red;"));
    MovieBottomBox = new QGroupBox(MovieBox);
    MovieBottomBox->setObjectName(QStringLiteral("MovieBottomBox"));
    MovieBottomBox->setGeometry(QRect(0, 197, 381, 331));
    MovieBottomBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(59, 62, 66, 255), stop:1 rgba(255, 255, 255, 92));\n"
"border: 0px solid rgb(255, 255, 255);\n"
"border-bottom-width: 1px;\n"
"border-radius: 10px;\n"
"}"));
    MovieDetailsBox = new QGroupBox(MovieBottomBox);
    MovieDetailsBox->setObjectName(QStringLiteral("MovieDetailsBox"));
    MovieDetailsBox->setEnabled(true);
    MovieDetailsBox->setGeometry(QRect(0, 40, 381, 291));
    MovieDetailsBox->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MoviePriceEdit = new QLineEdit(MovieDetailsBox);
    MoviePriceEdit->setObjectName(QStringLiteral("MoviePriceEdit"));
    MoviePriceEdit->setGeometry(QRect(122, 98, 140, 21));
    MoviePriceEdit->setFont(font1);
    MoviePriceEdit->setText("Price");
    MoviePriceEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    MovieDescriptionTitle = new QLabel(MovieDetailsBox);
    MovieDescriptionTitle->setObjectName(QStringLiteral("MovieDescriptionTitle"));
    MovieDescriptionTitle->setGeometry(QRect(1, 148, 74, 17));
    MovieDescriptionTitle->setFont(font1);
    MovieDescriptionTitle->setText("Description");
    MovieDescriptionTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MovieNameTitle = new QLabel(MovieDetailsBox);
    MovieNameTitle->setObjectName(QStringLiteral("MovieNameTitle"));
    MovieNameTitle->setGeometry(QRect(1, 44, 38, 17));
    MovieNameTitle->setFont(font1);
    MovieNameTitle->setText("Name");
    MovieNameTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MoviePriceTitle = new QLabel(MovieDetailsBox);
    MoviePriceTitle->setObjectName(QStringLiteral("MoviePriceTitle"));
    MoviePriceTitle->setGeometry(QRect(1, 98, 34, 17));
    MoviePriceTitle->setFont(font1);
    MoviePriceEdit->setText("Price");
    MoviePriceTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MovieDT = new QLabel(MovieDetailsBox);
    MovieDT->setObjectName(QStringLiteral("MovieDT"));
    MovieDT->setGeometry(QRect(240, 98, 18, 17));
    MovieDT->setFont(font1);
    MovieDT->setText("DT");
    MovieDT->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MovieIdTitle = new QLabel(MovieDetailsBox);
    MovieIdTitle->setObjectName(QStringLiteral("MovieIdTitle"));
    MovieIdTitle->setGeometry(QRect(1, 1, 26, 37));
    MovieIdTitle->setFont(font10);
    MovieIdTitle->setText("ID");
    MovieIdTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MovieIdEdit = new QLineEdit(MovieDetailsBox);
    MovieIdEdit->setObjectName(QStringLiteral("MovieIdEdit"));
    MovieIdEdit->setGeometry(QRect(122, 9, 140, 21));
    MovieIdEdit->setFont(font1);
    MovieIdEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    MovieSubtitle = new QLabel(MovieDetailsBox);
    MovieSubtitle->setObjectName(QStringLiteral("MovieSubtitle"));
    MovieSubtitle->setGeometry(QRect(1, 125, 115, 17));
    MovieSubtitle->setFont(font1);
    MovieSubtitle->setText("Available Subtitle");
    MovieSubtitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MovieTypeEdit = new QLineEdit(MovieDetailsBox);
    MovieTypeEdit->setObjectName(QStringLiteral("MovieTypeEdit"));
    MovieTypeEdit->setGeometry(QRect(122, 71, 140, 21));
    MovieTypeEdit->setFont(font1);
    MovieTypeEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    MovieTypeTitle = new QLabel(MovieDetailsBox);
    MovieTypeTitle->setObjectName(QStringLiteral("MovieTypeTitle"));
    MovieTypeTitle->setGeometry(QRect(1, 71, 32, 17));
    MovieTypeTitle->setFont(font1);
    MovieTypeTitle->setText("Title");
    MovieTypeTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;"));
    MovieNameEdit = new QLineEdit(MovieDetailsBox);
    MovieNameEdit->setObjectName(QStringLiteral("MovieNameEdit"));
    MovieNameEdit->setGeometry(QRect(122, 44, 140, 21));
    MovieNameEdit->setFont(font1);
    MovieNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 2px;\n"
"border-radius: px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    MovieUpdateButton = new QPushButton(MovieDetailsBox);
    MovieUpdateButton->setObjectName(QStringLiteral("MovieUpdateButton"));
    MovieUpdateButton->setGeometry(QRect(11, 260, 171, 21));
    MovieUpdateButton->setText("Update");
    MovieUpdateButton->setStyleSheet(QLatin1String("QPushButton\n"
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
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
""));
    MovieDescriptionEdit = new QPlainTextEdit(MovieDetailsBox);
    MovieDescriptionEdit->setObjectName(QStringLiteral("MovieDescriptionEdit"));
    MovieDescriptionEdit->setGeometry(QRect(122, 148, 234, 115));
    QFont font16;
    font16.setFamily(QStringLiteral("Segoe UI Semilight"));
    font16.setPointSize(11);
    MovieDescriptionEdit->setFont(font16);
    MovieDescriptionEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    MovieFrCheck = new QCheckBox(MovieDetailsBox);
    MovieFrCheck->setObjectName(QStringLiteral("MovieFrCheck"));
    MovieFrCheck->setGeometry(QRect(123, 126, 32, 16));
    MovieFrCheck->setText("FR");
    MovieFrCheck->setStyleSheet(QLatin1String("QCheckBox\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    border: 1px solid #ffffff;\n"
"	border-radius: 5px;\n"
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
    MovieArCheck = new QCheckBox(MovieDetailsBox);
    MovieArCheck->setObjectName(QStringLiteral("MovieArCheck"));
    MovieArCheck->setGeometry(QRect(171, 126, 33, 16));
    MovieArCheck->setText("AR");
    MovieArCheck->setStyleSheet(QLatin1String("QCheckBox\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"    border: 1px solid #ffffff;\n"
"	border-radius: 5px;\n"
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
    MovieEnCheck = new QCheckBox(MovieDetailsBox);
    MovieEnCheck->setObjectName(QStringLiteral("MovieEnCheck"));
    MovieEnCheck->setGeometry(QRect(220, 126, 32, 16));
    MovieEnCheck->setText("EN");
    MovieEnCheck->setStyleSheet(QLatin1String("QCheckBox\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;\n"
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
    MovieDeleteButton = new QPushButton(MovieDetailsBox);
    MovieDeleteButton->setObjectName(QStringLiteral("MovieDeleteButton"));
    MovieDeleteButton->setGeometry(QRect(200, 260, 171, 21));
    MovieDeleteButton->setText("Delete");
    MovieDeleteButton->setStyleSheet(QLatin1String("QPushButton\n"
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
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  red;\n"
"	border-color: red;\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
""));
    MovieSwipeButton = new QPushButton(MovieBox);
    MovieSwipeButton->setObjectName(QStringLiteral("MovieSwipeButton"));
    MovieSwipeButton->setGeometry(QRect(0, 170, 381, 71));
    QFont font17;
    font17.setFamily(QStringLiteral("Candara Light"));
    font17.setPointSize(16);
    MovieSwipeButton->setFont(font17);
    MovieSwipeButton->setText("CLICK");
    MovieSwipeButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background-color:#00000000;\n"
"	border-width:0px;\n"
"	color:#ffffff;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"\n"
"	color:rgb(30, 227, 0);\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"\n"
"	color:rgb(30, 227, 0);\n"
"}\n"
""));
}
