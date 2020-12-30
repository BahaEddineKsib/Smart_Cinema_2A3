#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QHBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include <QMessageBox>
#include "moviesFiles\moviegroupbox.h"
#include "database.h"
#include <QFileDialog>
#include <QFile>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include "smtp.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimeOfWork()));
    timer->start(1000);
    seconds = 0;
    minuts = 0;
    hours = 0;

    QPixmap logo(":/logo/logo.png");
    ui->logo->setPixmap(logo.scaled(200,200,Qt::KeepAspectRatio));

    /***********************TEMPORARY CODE*********************************/
    /**/QPixmap ProfilIcon(":/profil_icon/profile_icon.png");
    /**/ui->ProfilPhoto->setPixmap(ProfilIcon.scaled(100,100,Qt::KeepAspectRatio));
    /**///ui->label->setPixmap(ProfilIcon.scaled(100,100,Qt::KeepAspectRatio));
    /**********************************************************************/

    //ui->BigStack->setCurrentIndex(0);       //default page set to loginpage
    ui->DashboardPages->setCurrentIndex(0); //default Dashboard page set to profil
    setup_tabs();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setup_tabs()
{
    login_page = new loginpage(ui);
    connect(ui->LoginButton, SIGNAL (clicked()),this, SLOT (loginpage_login()));

    //tabs
    employees = new tab_employees(ui);
    employees->DisplayAllEmployees();

    theatres = new tab_theatres(ui);
    connect(ui->btn_show_add_theatre, SIGNAL (clicked()),this, SLOT (tab_theatres_show_add()));
    connect(ui->btn_add_theatre, SIGNAL (clicked()),this, SLOT (tab_theatres_add_theatre()));
    connect(ui->btn_cancel_theatre, SIGNAL (clicked()),this, SLOT (tab_theatres_cancel_add()));

    movies = new  tab_movies(ui);
    movies->DisplayAllMovies();

    tickets = new tab_tickets(ui);
    tickets->DisplayAllTickets();
    ui->PrintAndSendWidget->setHidden(true);

    clients = new tab_clients(ui);
    clients->DisplayAllClients();

    subscriptions = new tab_subscriptions(ui);
    subscriptions->DisplayAllSubscriptions();
}


void MainWindow::TimeOfWork()
{
    seconds++;
    if(seconds >= 60)
    {
        seconds=0;
        minuts++;
        QString min = QString::number(minuts);
        ui->Crnt_minuts->setText(min);
    }
    if(minuts >= 60)
    {
        minuts = 0;
        hours++;
        QString h   = QString::number(hours);
        ui->Crnt_hours->setText(h);
    }

    QString sec = QString::number(seconds);
    ui->Crnt_seconds->setText(sec);



}

void MainWindow::on_ExitButton_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_DashboardButton_clicked()
{

    int x =ui->LeftSideStackedWidget->currentIndex();
    if(x == 0)
    {
        ui->LeftSideStackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->LeftSideStackedWidget->setCurrentIndex(0);

    }


}



void MainWindow::on_ProfilButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(0);
    ui->CurrentPageTitle->setText("Profil");
}


void MainWindow::on_EmployeesButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(1);
    ui->CurrentPageTitle->setText("Employees Management");
}

void MainWindow::on_ProductsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(4);
    ui->CurrentPageTitle->setText("Products Management");
}

void MainWindow::on_TicketsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(2);
    ui->CurrentPageTitle->setText("Tickets Management");
}

void MainWindow::on_BillsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(3);
    ui->CurrentPageTitle->setText("Bills Management");
}

void MainWindow::on_MoviesButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(5);
    ui->CurrentPageTitle->setText("Movies Management");
    //MovieGroupBox* m;
    //m = new MovieGroupBox(ui->MoviesArea);
    //ui->horizontalLayout_4->add
   // ui->horizontalLayout_4->removeWidget();
}

void MainWindow::on_TheatresButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(6);
    ui->CurrentPageTitle->setText("Theatres Management");
    theatres->show_theatres();
}

void MainWindow::on_ClientsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(7);
    ui->CurrentPageTitle->setText("Clients Management");
}

void MainWindow::on_SubscriptionsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(8);
    ui->CurrentPageTitle->setText("Subscriptions Management");
}

void MainWindow::on_ShowsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(9);
    ui->CurrentPageTitle->setText("Shows Management");
}


void MainWindow::on_PollsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(10);
    ui->CurrentPageTitle->setText("Polls Management");
}

void MainWindow::loginpage_login()
{
    login_page->login();
}


void MainWindow::tab_theatres_show_add()
{
    theatres->show_add_theatre();
}

void MainWindow::tab_theatres_add_theatre()
{
    theatres->add_theatre();
}

void MainWindow::tab_theatres_cancel_add()
{
    theatres->hide_add_theatre();
}
void MainWindow::on_FilmAddImageButton_clicked()
{
    qDebug() << "FilmAddImageButton_clicked" << endl;
    QString ImagePath = QFileDialog::getOpenFileName(this,"choose image");
    qDebug() << ImagePath << endl;
    ui->FilmAddImageButton->setText(ImagePath);
    qDebug() << ui->FilmAddImageButton->text() << endl;
}
void MainWindow::on_FilmAddButton_clicked()
{
    movies->AddMovie();
}
void MainWindow::on_SearchFilmButton_clicked()
{
    movies->SearchMovies();
}
void MainWindow::on_TicketAddButton_clicked()
{
    tickets->AddTicket();
}

void MainWindow::on_ClientAddButton_clicked()
{
    clients->AddClient();
}

void MainWindow::on_EmployeeAddButton_clicked()
{
    employees->AddEmployee();
}

void MainWindow::on_SubscriptionAddButton_clicked()
{
    subscriptions->AddSubscription();
}

void MainWindow::on_EmployeeImageAddButton_clicked()
{
    qDebug() << "EmployeeImageAddButton_clicked" << endl;
    QString ImagePath = QFileDialog::getOpenFileName(this,"choose image");
    qDebug() << ImagePath << endl;
    ui->EmployeeImageAddButton->setText(ImagePath);
    qDebug() << ui->EmployeeImageAddButton->text() << endl;
}

void MainWindow::on_HidePrintAndSendButton_clicked()
{
    ui->PrintAndSendWidget->setHidden(true);
}
void MainWindow::on_PrintTicketButton_clicked()
{
    QString link =QFileDialog::getExistingDirectory(this, tr("Open Directory"),"",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks)+"/"+ui->TicketIdAdd->text()+".pdf";
    QPdfWriter pdf(link);

    QPainter painter(&pdf);






    if(database::get()->db.isOpen())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  shows WHERE id = :id");
        qry.bindValue(":id",ui->TicketShowIdAdd->text());

    if(!qry.exec())
    {
        QMessageBox::information(nullptr,"Error","Failed to exec query");
    }
    else
    {
        while(qry.next())
        {


            QSqlQuery MoviesQry;
            MoviesQry.prepare("SELECT * FROM  movies WHERE id = :id");
            MoviesQry.bindValue(":id",qry.value(qry.record().indexOf("movie_id")).toString());
            if(!MoviesQry.exec())
            {
                QMessageBox::information(nullptr,"Error","Failed to exec query");
            }
            else
            {
                while(MoviesQry.next())
                {
                    qDebug() << MoviesQry.value(MoviesQry.record().indexOf("ImageLink")).toString() << "debug" << endl;
                    QImage  img(MoviesQry.value(MoviesQry.record().indexOf("ImageLink")).toString());
                    painter.drawImage(QRect(2800, 50,img.width()*(3000.0/img.height()), 3000), img);

                    QImage  temp(":/new/prefix1/imgs/TemplateTicket.PNG");
                    painter.drawImage(QRect(100, 50,temp.width()*(3000.0/temp.height()), 3000), temp);

                    painter.setFont(QFont("Gabriola", 37));
                    painter.setPen(QPen(QColor("#ffffff")));
                    painter.drawText(3020,950,MoviesQry.value(MoviesQry.record().indexOf("name")).toString());
                }
            }
            painter.setFont(QFont("Nirmala UI Semilight", 9));
            QPen penHText2(QColor("#ffd7a1"));
            painter.setPen(penHText2);
            painter.drawText(3020,2800, qry.value(qry.record().indexOf("start_date")).toString());

            QSqlQuery TheatreQry;
            TheatreQry.prepare("SELECT * FROM  theatres WHERE id = :id");
            TheatreQry.bindValue(":id",qry.value(qry.record().indexOf("theatre_id")).toString());
            if(!TheatreQry.exec())
            {
                QMessageBox::information(nullptr,"Error","Failed to exec query");
            }
            else
            {
                while(TheatreQry.next())
                {
                    painter.setFont(QFont("Nirmala UI Semilight", 9));
                    QPen penHText2(QColor("#ffd7a1"));
                    painter.setPen(penHText2);
                    painter.drawText(5500,2800,TheatreQry.value(TheatreQry.record().indexOf("name")).toString());
                }
            }

        }
    }
    }

    if(ui->TicketVIPseatAdd->isChecked())
    {
        painter.setFont(QFont("Nirmala UI Semilight", 50));
        QPen penHText(QColor("#ffd7a1"));
        painter.setPen(penHText);
        painter.drawText(3200,1800,"VIP");

    }
    painter.setFont(QFont("Nirmala UI Semilight", 8));
    QPen penHText(QColor("#ffd7a1"));
    painter.setPen(penHText);
    painter.drawText(4110,441,ui->TicketIdAdd->text());

    painter.setFont(QFont("Nirmala UI Semilight", 20));
    QPen penHText2(QColor("#ffffff"));
    painter.setPen(penHText2);
    painter.drawText(8000,2800,ui->TicketPriceAdd->text()+"DT");


    painter.end();
    QDesktopServices::openUrl(link);
}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("monemehamila@gmail.com", "Troxy26984677", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("monemehamila@gmail.com", ui->TicketBuyerEmailSend->text() , "smartcinema","welcome");
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_SendTicketButton_clicked()
{
  sendMail();
}


