#include "theatre.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QtSql>
theatre::theatre(int ID, QString NAME, int SEATS, int VIP_SEATS, Ui::MainWindow *ui)
{
    this->ui = ui;
    id       = ID;
    name     = NAME;
    seats    = SEATS;
    VIP_Seats= VIP_SEATS;
}
int theatre::StoreInDatabase()
{
        bool ID_VERIFICATION=true;
        QSqlQuery qry;

        qry.prepare("SELECT id FROM  theatres");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
            return 0;
        }
        else
        {
            while(qry.next() && ID_VERIFICATION)
            {
                if(qry.value(qry.record().indexOf("id")).toInt() == id)
                {
                    ID_VERIFICATION=false;
                }
            }
        }

        if(ID_VERIFICATION == false)
        {
            QMessageBox::information(nullptr,"ERROR","ID ALREADY EXIST!.");
            return 0;
        }
        else if(id == 0 || name == "" || seats == 0)
        {
            QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
            return 0;
        }
        else
        {
            qry.prepare("INSERT INTO theatres (id, name, seats, vip_seats) VALUES (:id, :name, :seats, :vip_seats)");
            qry.bindValue(":id",       id);
            qry.bindValue(":name",     name);
            qry.bindValue(":seats",    seats);
            qry.bindValue(":vip_seats",VIP_Seats);

            if(qry.exec())
            {
                QMessageBox::information(nullptr,"Success","theatre registered successfully.");

            }
            else
            {
                QMessageBox::information(nullptr,"Error",qry.lastError().text());
                QMessageBox::information(nullptr,"error","database error");
                return 0;
            }
         }
    return 1;

}

void theatre::Display()
{
    DisplayBox = new TheatreGroupBox(ui->TheatresArea);
    DisplayBox->TheatreIdEdit->setText(QString::number(id));
    DisplayBox->TheatreNameEdit->setText(name);
    DisplayBox->TheatreSeatsEdit->setText(QString::number(seats));
    DisplayBox->TheatreVIP_SeatsEdit->setText(QString::number(VIP_Seats));


    ui->horizontalLayout_Theatre->addWidget(DisplayBox);
}
