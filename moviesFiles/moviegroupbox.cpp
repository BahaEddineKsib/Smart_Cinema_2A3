#include "moviesFiles\moviegroupbox.h"
#include "database.h"
#include "moviesFiles\tab_movies.h"
#include <QMessageBox>
#include <QDebug>
#include <QLatin1String>
#include <QRect>
MovieGroupBox::MovieGroupBox(QWidget *parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(381, 531));
    this->setMaximumSize(QSize(381, 531));
    qDebug() << "CREATE MovieGroupBox";
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
    MovieImageButton->setGeometry(QRect(5, 0, 371, 241));
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/new/prefix1/imgs/deadpool.png"), QSize(), QIcon::Normal, QIcon::Off);
    MovieImageButton->setIcon(icon1);
    MovieImageButton->setIconSize(QSize(400, 400));
    MovieImageButton->setStyleSheet(QLatin1String("border: 2px solid rgba(255, 255, 255,0);\nbackground-color:rgba(255, 255, 255,0);"));
    MovieBottomBox = new QGroupBox(MovieBox);
    MovieBottomBox->setGeometry(QRect(0, 197, 381, 331));
    MovieBottomBox->setStyleSheet(QLatin1String("QGroupBox\n{\nbackground-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(59, 62, 66, 255), stop:1 rgba(255, 255, 255, 92));\nborder: 0px solid rgb(255, 255, 255);\nborder-bottom-width: 1px;\nborder-radius: 10px;\n}"));
    MovieDetailsBox = new QGroupBox(MovieBottomBox);
    MovieDetailsBox->setEnabled(true);
    MovieDetailsBox->setGeometry(QRect(0, 40, 381, 291));
    MovieDetailsBox->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MoviePriceEdit = new QLineEdit(MovieDetailsBox);
    MoviePriceEdit->setGeometry(QRect(122, 98, 140, 21));
    MoviePriceEdit->setFont(font1);
    MoviePriceEdit->setText("Price");
    MoviePriceEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
    MovieDescriptionTitle = new QLabel(MovieDetailsBox);
    MovieDescriptionTitle->setGeometry(QRect(1, 148+30, 74, 17));
    MovieDescriptionTitle->setFont(font1);
    MovieDescriptionTitle->setText("Description");
    MovieDescriptionTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MovieNameTitle = new QLabel(MovieDetailsBox);
    MovieNameTitle->setGeometry(QRect(1, 44, 38, 17));
    MovieNameTitle->setFont(font1);
    MovieNameTitle->setText("Name");
    MovieNameTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MoviePriceTitle = new QLabel(MovieDetailsBox);
    MoviePriceTitle->setGeometry(QRect(1, 98, 34, 17));
    MoviePriceTitle->setFont(font1);
    MoviePriceEdit->setText("Price");
    MoviePriceTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MovieDT = new QLabel(MovieDetailsBox);
    MovieDT->setGeometry(QRect(240, 98, 18, 17));
    MovieDT->setFont(font1);
    MovieDT->setText("DT");
    MovieDT->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MovieIdTitle = new QLabel(MovieDetailsBox);
    MovieIdTitle->setGeometry(QRect(1, 1, 30, 37));
    MovieIdTitle->setFont(font10);
    MovieIdTitle->setText("ID");
    MovieIdTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MovieIdEdit = new QLabel(MovieDetailsBox);
    MovieIdEdit->setGeometry(QRect(122, 9, 140, 21));
    MovieIdEdit->setFont(font1);
    MovieIdEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
    MovieTypeEdit = new QLineEdit(MovieDetailsBox);
    MovieTypeEdit->setGeometry(QRect(122, 71, 140, 21));
    MovieTypeEdit->setFont(font1);
    MovieTypeEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
    MovieTypeTitle = new QLabel(MovieDetailsBox);
    MovieTypeTitle->setGeometry(QRect(1, 71, 32, 17));
    MovieTypeTitle->setFont(font1);
    MovieTypeTitle->setText("Title");
    MovieTypeTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MovieNameEdit = new QLineEdit(MovieDetailsBox);
    MovieNameEdit->setGeometry(QRect(122, 44, 140, 21));
    MovieNameEdit->setFont(font1);
    MovieNameEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));

    MovieSubLanguageTitle = new QLabel(MovieDetailsBox);
    MovieSubLanguageTitle->setGeometry(QRect(1, 125, 115+50, 17));
    MovieSubLanguageTitle->setFont(font1);
    MovieSubLanguageTitle->setText("Sub Language");
    MovieSubLanguageTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MovieSubLanguageEdit = new QLineEdit(MovieDetailsBox);
    MovieSubLanguageEdit->setGeometry(QRect(122, 125, 140, 21));
    MovieSubLanguageEdit->setFont(font1);
    MovieSubLanguageEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));

    MovieDubLanguageTitle = new QLabel(MovieDetailsBox);
    MovieDubLanguageTitle->setGeometry(QRect(1, 148, 115+50, 17));
    MovieDubLanguageTitle->setFont(font1);
    MovieDubLanguageTitle->setText("Dub Language");
    MovieDubLanguageTitle->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\nbackground-color: rgba(255, 255, 255, 0);\nborder: 0px;"));
    MovieDubLanguageEdit = new QLineEdit(MovieDetailsBox);
    MovieDubLanguageEdit->setGeometry(QRect(122, 148, 140, 21));
    MovieDubLanguageEdit->setFont(font1);
    MovieDubLanguageEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\nborder-bottom-width: 2px;\nborder-radius: px;\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));


    MovieUpdateButton = new QPushButton(MovieDetailsBox);
    MovieUpdateButton->setGeometry(QRect(11, 260, 171, 21));
    MovieUpdateButton->setText("Update");
    MovieUpdateButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color: rgb(30, 227, 0);\n}\n\nQPushButton:focus\n{\n	background-color:  rgb(30, 227, 0);\n	border-color: rgba(30, 227, 0,0);\n	color:rgb(255, 255, 255);\n}\n"));
    MovieDescriptionEdit = new QPlainTextEdit(MovieDetailsBox);
    MovieDescriptionEdit->setGeometry(QRect(122, 148+30, 234, 115-30));
    QFont font16;
    font16.setFamily(QStringLiteral("Segoe UI Semilight"));
    font16.setPointSize(11);
    MovieDescriptionEdit->setFont(font16);
    MovieDescriptionEdit->setStyleSheet(QLatin1String("border: 0px solid rgb(249, 167, 43);\n\nbackground-color: rgba(255, 255, 255, 0);\ncolor: rgb(255, 255, 255);"));
    MovieDeleteButton = new QPushButton(MovieDetailsBox);
    MovieDeleteButton->setGeometry(QRect(200, 260, 171, 21));
    MovieDeleteButton->setText("Delete");
    MovieDeleteButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:rgb(50, 53, 57);\n	border-style:solid;\n	border-radius:7px;\n	border-width:1px;\nborder-color: rgb(50, 53, 57);\n	color:#ffffff;\n	font-size:16px;\nfont-family:Calibri;\n}\n\nQPushButton:hover\n{\n	background-color: #00000000;\n	border-color:red;\n}\n\nQPushButton:focus\n{\n	background-color:  red;\n	border-color: red;\n	color:rgb(255, 255, 255);\n}\n"));
    MovieSwipeButton = new QPushButton(MovieBox);
    MovieSwipeButton->setGeometry(QRect(0, 170, 381, 71));
    QFont font17;
    font17.setFamily(QStringLiteral("Candara Light"));
    font17.setPointSize(16);
    MovieSwipeButton->setFont(font17);
    MovieSwipeButton->setText("CLICK");
    MovieSwipeButton->setStyleSheet(QLatin1String("QPushButton\n{\n	background-color:#00000000;\n	border-width:0px;\n	color:#ffffff;\n}\n\nQPushButton:hover\n{\n\n	color:rgb(30, 227, 0);\n}\n\nQPushButton:focus\n{\n\n	color:rgb(30, 227, 0);\n}\n"));
    connect(MovieUpdateButton,SIGNAL(clicked()),this,SLOT(UpdateMovieSlot()));
    connect(MovieDeleteButton,SIGNAL(clicked()),this,SLOT(DeleteMovieSlot()));
    connect(MovieSwipeButton, SIGNAL(clicked()),this,SLOT(Animation()));
    Animation();
}
MovieGroupBox::~MovieGroupBox()
{
    qDebug() << "DELETE MovieGroupBox";
}
void MovieGroupBox::UpdateMovieSlot()
{
    qDebug() << "UPDATE MOVIE";
        QSqlQuery qry;
        qry.prepare("UPDATE movies SET name=:name, type=:type, price=:price, description=:description, sub_language=:sub_language, dub_language=:dub_language WHERE id=:id ");
        QString desc =                MovieDescriptionEdit->toPlainText();
        qry.bindValue(":description", desc);
        qry.bindValue(":name",        MovieNameEdit->text());
        qry.bindValue(":type",        MovieTypeEdit->text());
        qry.bindValue(":price",       MoviePriceEdit->text());
        qry.bindValue(":sub_language",MovieSubLanguageEdit->text());
        qry.bindValue(":dub_language",MovieDubLanguageEdit->text());
        qry.bindValue(":id",          MovieIdEdit->text());

        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            QMessageBox::information(nullptr,"UPDATE MOVIE","DONE!");
        }
}


void MovieGroupBox::DeleteMovieSlot()
{
    qDebug() << "DELETE MOVIE FROM DATA BASE";
        QSqlQuery qry;
        qry.prepare("DELETE FROM movies WHERE id=:id ");
        qry.bindValue(":id",MovieIdEdit->text());
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","there is a show contain this movie");
        }
        else
        {
            QMessageBox::information(nullptr,"DELETE MOVIE","DONE!");
        }
        delete this;
}

void MovieGroupBox::Animation()
{
    if(!MovieDetailsBox->isHidden())
    {
        animation = new QPropertyAnimation(MovieBottomBox,"geometry");
        animation->setDuration(100);
        animation->setStartValue(MovieBottomBox->geometry());
        animation->setEndValue(QRect(MovieBottomBox->x(),0,MovieBottomBox->width(),MovieImageButton->height()));
        animation->start();
        MovieDetailsBox->setHidden(true);
    }
    else
    {
        animation = new QPropertyAnimation(MovieBottomBox,"geometry");
        animation->setDuration(100);
        animation->setStartValue(MovieBottomBox->geometry());
        animation->setEndValue(QRect(0, 197, 381, 331));
        animation->start();
        MovieDetailsBox->setHidden(false);
    }
        qDebug() << "animation";
}

