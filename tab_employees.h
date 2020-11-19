#ifndef TAB_EMPLOYEES_H
#define TAB_EMPLOYEES_H


#include "ui_mainwindow.h"

class tab_employees
{
public:
    tab_employees(Ui::MainWindow *ui);
    Ui::MainWindow *ui;

    void add_employee();
};

#endif // TAB_EMPLOYEES_H
