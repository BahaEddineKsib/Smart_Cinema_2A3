#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QHBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include <QMessageBox>
#include <moviegroupbox.h>
#include "database.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->BigStack->setCurrentIndex(1);
    //ui->DashboardPages->setCurrentIndex(0);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimeOfWork()));
    timer->start(1000);
    seconds = 0;
    minuts = 0;
    hours = 0;

    QPixmap logo(":/logo/logo.png");
    ui->logo->setPixmap(logo.scaled(200,200,Qt::KeepAspectRatio));

    QPixmap ProfilIcon(":/profil_icon/profile_icon.png");
    ui->ProfilPhoto->setPixmap(ProfilIcon.scaled(100,100,Qt::KeepAspectRatio));
    //ui->label_41->setPixmap(ProfilIcon.scaled(100,100,Qt::KeepAspectRatio));
    ui->label->setPixmap(ProfilIcon.scaled(100,100,Qt::KeepAspectRatio));

    ui->BigStack->setCurrentIndex(0); //default page set to loginpage

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
    connect(ui->add_employee_btn, SIGNAL (clicked()),this, SLOT (tab_employees_add_employee()));

    theatres = new tab_theatres(ui);
    connect(ui->btn_show_add_theatre, SIGNAL (clicked()),this, SLOT (tab_theatres_show_add()));
    connect(ui->btn_add_theatre, SIGNAL (clicked()),this, SLOT (tab_theatres_add_theatre()));
    connect(ui->btn_cancel_theatre, SIGNAL (clicked()),this, SLOT (tab_theatres_cancel_add()));


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

void MainWindow::tab_employees_add_employee()
{
    employees->add_employee();
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






