#ifndef TAB_CLIENTS_H
#define TAB_CLIENTS_H
#include "ui_mainwindow.h"

class tab_clients
{
public:
    tab_clients(Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void DisplayAllClients();
    void UndisplayAllClients();
    void AddClient();
    void SearchClients();
};

#endif // TAB_CLIENTS_H
