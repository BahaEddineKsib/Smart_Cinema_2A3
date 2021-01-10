#include "tab_theatres.h"
#include "theatre.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
tab_theatres::tab_theatres(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_theatres::DisplayAllTheatres()
{
    qDebug() << "DISPLAY ALL THEATRES";
    theatre *THEATRE;
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  theatres");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {//theatre::theatre(int ID, QString NAME, int SEATS, int VIP_SEATS, Ui::MainWindow *ui)
                THEATRE = new theatre(qry.value(qry.record().indexOf               ("id")).toInt(),
                                    qry.value(qry.record().indexOf             ("name")).toString(),
                                    qry.value(qry.record().indexOf            ("seats")).toInt(),
                                    qry.value(qry.record().indexOf  ("vip_seats")).toInt(),
                                    ui);
                THEATRE->Display();
            }
        }
}

void tab_theatres::AddTheatre()
{
    theatre* Theatre = new theatre(ui->TheatreIdAdd         ->text().toInt(),
                                      ui->TheatreNameAdd       ->text(),
                                      ui->TheatreNumberOfSeatsAdd->text().toInt(),
                                      ui->TheatreNumberOfVIPSeatsAdd   ->text().toInt(),
                                      ui);
    if(Theatre->StoreInDatabase() == 1)
    {
        Theatre->Display();
    }

}
