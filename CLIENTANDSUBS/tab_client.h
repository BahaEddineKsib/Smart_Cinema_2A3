#ifndef TAB_CLIENT_H
#define TAB_CLIENT_H

#include "ui_mainwindow.h"
class tab_client
{
public:
    tab_client(Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void DisplayAllclient();
    void UndisplayAllclient();
    void Addclient();
    void Searchclient();

};

#endif // TAB_CLIENT_H
