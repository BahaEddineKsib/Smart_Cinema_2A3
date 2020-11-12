#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QHBoxLayout>
#include <QWidget>
#include <QScrollArea>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    ui->BigStack->setCurrentIndex(1);
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
}

MainWindow::~MainWindow()
{
    delete ui;
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
    ui->CurrentPageTitle->setText("Employees");
}

void MainWindow::on_ProductsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(4);
    ui->CurrentPageTitle->setText("Products");
}

void MainWindow::on_TicketsButton_clicked()
{
    ui->DashboardPages->setCurrentIndex(2);
    ui->CurrentPageTitle->setText("Tickets");
}
