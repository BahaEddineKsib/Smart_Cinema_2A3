#include "tab_employees.h"
#include "employee.h"
#include "..\database.h"
#include <QDebug>
#include <QMessageBox>
tab_employees::tab_employees(Ui::MainWindow *ui)
{
    this->ui = ui;
}

void tab_employees::DisplayAllEmployees()
{
    qDebug() << "DISPLAY ALL Employees";
    employee *EMPLOYEE;
        QSqlQuery qry;
        qry.prepare("SELECT * FROM  employees");
        if(!qry.exec())
        {
            QMessageBox::information(nullptr,"Error","Failed to exec query");
        }
        else
        {
            while(qry.next())
            {
                EMPLOYEE = new employee(qry.value(qry.record().indexOf       ("id")).toInt(),
                                        qry.value(qry.record().indexOf     ("name")).toString(),
                                        qry.value(qry.record().indexOf    ("email")).toString(),
                                        qry.value(qry.record().indexOf ("username")).toString(),
                                        qry.value(qry.record().indexOf ("password")).toString(),
                                        qry.value(qry.record().indexOf     ("role")).toString(),
                                        qry.value(qry.record().indexOf("imagelink")).toString(),
                                  ui);
                EMPLOYEE->Display();
            }
        }
    }
void tab_employees::AddEmployee()
{
    employee* Employee = new employee(ui->EmployeeIdAdd         ->text().toInt(),
                                      ui->EmployeeNameAdd       ->text(),
                                      ui->EmployeeEmailAdd      ->text(),
                                      ui->EmployeeUsernameAdd   ->text(),
                                      ui->EmployeePasswordAdd   ->text(),
                                      ui->EmployeeAccessAdd     ->currentText(),
                                      ui->EmployeeImageAddButton->text(),
                                      ui);
    if(Employee->StoreInDatabase() == 1)
    {
        Employee->Display();
    }

}

