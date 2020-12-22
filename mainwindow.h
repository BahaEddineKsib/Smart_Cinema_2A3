#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include <QScrollArea>
#include "smtp.h"
#include "loginpage.h"
#include "employeesFiles\tab_employees.h"
#include "tab_theatres.h"
#include "moviesFiles\tab_movies.h"
#include "ticketsFiles\tab_tickets.h"
#include "clientsFiles/tab_clients.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

    loginpage *login_page;

    //dashboard tabs
    tab_employees *employees;
    tab_theatres  *theatres;
    tab_movies    *movies;
    tab_tickets   *tickets;
    tab_clients   *clients;
public slots:
    void TimeOfWork();
    void tab_theatres_show_add();
    void tab_theatres_add_theatre();
    void tab_theatres_cancel_add();
private:

    QTimer *timer;
    int seconds,minuts,hours;

    void setup_tabs();

private slots:
    void on_ExitButton_clicked();

    void on_DashboardButton_clicked();

    void on_ProfilButton_clicked();

    void on_EmployeesButton_clicked();

    void on_ProductsButton_clicked();

    void on_TicketsButton_clicked();

    void on_BillsButton_clicked();

    void on_MoviesButton_clicked();

    void on_TheatresButton_clicked();

    void on_ClientsButton_clicked();

    void on_SubscriptionsButton_clicked();

    void on_ShowsButton_clicked();

    void on_PollsButton_clicked();

    void loginpage_login();

    void on_FilmAddButton_clicked();

    void on_SearchFilmButton_clicked();

    void on_FilmAddImageButton_clicked();

    void on_TicketAddButton_clicked();

    void on_HidePrintAndSendButton_clicked();

    void on_EmployeeAddButton_clicked();

    void on_ClientAddButton_clicked();

    void on_EmployeeImageAddButton_clicked();

    void on_PrintTicketButton_clicked();

    void on_SendTicketButton_clicked();

    void sendMail();

    void mailSent(QString);


};
#endif // MAINWINDOW_H
