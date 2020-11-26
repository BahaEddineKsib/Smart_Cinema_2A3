#include "ticketgroupbox.h"

TicketGroupBox::TicketGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(100, 40));
    this->setMaximumSize(QSize(16777215, 40));

    TicketBox = new QGroupBox(this);
    TicketBox->setObjectName(QStringLiteral("TicketBox"));
    TicketBox->setMinimumSize(QSize(100, 40));
    TicketBox->setMaximumSize(QSize(16777215, 40));
    TicketBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"\n"
"     border: 0px solid white; \n"
"     border-radius: 0px; \n"
"	border-bottom-width:1px;	\n"
"	border-color:rgb(130, 135, 144);\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"}"));
    TicketDeleteButton = new QPushButton(TicketBox);
    TicketDeleteButton->setObjectName(QStringLiteral("TicketDeleteButton"));
    TicketDeleteButton->setGeometry(QRect(880, 0, 61, 31));
    TicketDeleteButton->setText("Delete");
    TicketDeleteButton->setStyleSheet(QLatin1String("QPushButton\n"
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
    TicketUpdateButton = new QPushButton(TicketBox);
    TicketUpdateButton->setObjectName(QStringLiteral("TicketUpdateButton"));
    TicketUpdateButton->setGeometry(QRect(815, 0, 61, 31));
    TicketUpdateButton->setText("Update");
    TicketUpdateButton->setStyleSheet(QLatin1String("QPushButton\n"
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
"	border-color:#00ff00;\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:#00ff00;\n"
"	border-color: #00ff00;\n"
"	color:rgb(255, 255, 255);\n"
"}\n"
""));
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
    TicketShowId = new QComboBox(TicketBox);
    TicketShowId->setObjectName(QStringLiteral("TicketShowId"));
    TicketShowId->setGeometry(QRect(140, 7, 41, 16));
    TicketShowId->setMinimumSize(QSize(10, 0));
    TicketShowId->setMaximumSize(QSize(135, 16777215));
    TicketShowId->setStyleSheet(QLatin1String("QComboBox {\n"
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
    TicketVIP = new QCheckBox(TicketBox);
    TicketVIP->setObjectName(QStringLiteral("TicketVIP"));
    TicketVIP->setGeometry(QRect(240, 9, 16, 16));
    TicketVIP->setMinimumSize(QSize(0, 0));
    TicketVIP->setMaximumSize(QSize(122, 16777215));
    TicketVIP->setStyleSheet(QLatin1String("QCheckBox\n"
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
    TicketVIP->setTristate(false);
    TicketNotSub = new QRadioButton(TicketBox);
    TicketNotSub->setObjectName(QStringLiteral("TicketNotSub"));
    TicketNotSub->setGeometry(QRect(330, 9, 19, 16));
    TicketNotSub->setMinimumSize(QSize(0, 0));
    TicketNotSub->setMaximumSize(QSize(67, 16777215));
    QFont font1;
    font1.setFamily(QStringLiteral("Arial Black"));
    font1.setPointSize(9);
    font1.setBold(true);
    font1.setWeight(75);
    TicketNotSub->setFont(font1);
    TicketNotSub->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    TicketEmail = new QLineEdit(TicketBox);
    TicketEmail->setObjectName(QStringLiteral("TicketEmail"));
    TicketEmail->setGeometry(QRect(350, 7, 131, 17));
    TicketEmail->setMinimumSize(QSize(100, 0));
    TicketEmail->setMaximumSize(QSize(300, 16777215));
    TicketEmail->setFont(font14);
    TicketEmail->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n"
"border-bottom-width: 1px;\n"
"border-radius: 5px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
    TicketSub = new QRadioButton(TicketBox);
    TicketSub->setObjectName(QStringLiteral("TicketSub"));
    TicketSub->setGeometry(QRect(530, 9, 19, 16));
    TicketSub->setFont(font1);
    TicketSub->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
    TicketClient = new QComboBox(TicketBox);
    TicketClient->setObjectName(QStringLiteral("TicketClient"));
    TicketClient->setGeometry(QRect(550, 7, 81, 16));
    TicketClient->setStyleSheet(QLatin1String("QComboBox {\n"
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
    TicketPrice = new QLabel(TicketBox);
    TicketPrice->setObjectName(QStringLiteral("TicketPrice"));
    TicketPrice->setGeometry(QRect(700, 10, 41, 16));
    QFont font15;
    font15.setFamily(QStringLiteral("Bahnschrift Light"));
    font15.setPointSize(9);
    TicketPrice->setFont(font15);
    TicketPrice->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
}
