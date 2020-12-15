#ifndef TAB_subscription_H
#define TAB_subscription_H

#include "ui_mainwindow.h"
class tab_subscription
{
public:
    tab_subscription(Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void DisplayAllsubscription();
    void UndisplayAllsubscription();
    void Addsubscription();
    void Searchsubscription();

};

#endif // TAB_subscription_H
