#include "employee.h"
#include "..\database.h"
#include "QMessageBox"
employee::employee(int ID, QString NAME, QString EMAIL, QString USERNAME, QString PASSWORD, QString ROLE, QString  IMAGELINK, Ui::MainWindow *ui)
{
    this->ui = ui;
    id       = ID;
    name     = NAME;
    email    = EMAIL;
    username = USERNAME;
    password = PASSWORD;
    role     = ROLE;
    ImageLink= IMAGELINK;
}

int employee::StoreInDatabase()
{
        bool ID_VERIFICATION=true;
        QSqlQuery qry;

        qry.prepare("SELECT id FROM  employees");
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
        else if(id == 0 || role == "" || password == "" || username == "" || name == "" || email == "")
        {
            QMessageBox::information(nullptr,"ERROR","EMPTY INPUTS!.");
            return 0;
        }
        else
        {
            qry.prepare("INSERT INTO employees (id, role, password, username, name, email, imagelink) VALUES (:id, :role, :password, :username, :name, :email, :imagelink)");
            qry.bindValue(":id",       id);
            qry.bindValue(":role",     role);
            qry.bindValue(":password", password);
            qry.bindValue(":username", username);
            qry.bindValue(":name",     name);
            qry.bindValue(":email",    email);
            qry.bindValue(":imagelink",ImageLink);

            if(qry.exec())
            {
                QMessageBox::information(nullptr,"Success","Employee registered successfully.");

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

void employee::Display()

{
    DisplayBox = new EmployeeGroupBox(ui->EmployeesScrollAreaWidgetContents);
    DisplayBox->EmployeeId->setText(QString::number(id));
    DisplayBox->EmployeeNameEdit->setText(name);
    DisplayBox->EmployeeUsernameEdit->setText(username);
    DisplayBox->EmployeePasswordEdit->setText(password);
    DisplayBox->EmployeeEmailEdit->setText(email);
    DisplayBox->EmployeeAccessCombo->setCurrentIndex(DisplayBox->EmployeeAccessCombo->findData(role));
    QIcon icon1;
    icon1.addFile(ImageLink, QSize(), QIcon::Normal, QIcon::Off);
    DisplayBox->EmployeePhotoButtonEdit->setIcon(icon1);
    ui->verticalLayout_3->addWidget(DisplayBox);
}
//employee end

