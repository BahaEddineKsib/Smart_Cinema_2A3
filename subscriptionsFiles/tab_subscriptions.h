#ifndef TAB_SUBSCRIPTIONS_H
#define TAB_SUBSCRIPTIONS_H
#include "ui_mainwindow.h"

class tab_subscriptions
{
public:
    tab_subscriptions(Ui::MainWindow *ui);
    Ui::MainWindow *ui;
    void DisplayAllSubscriptions();
    void UndisplayAllSubscriptions();
    void AddSubscription();
};

#endif // TAB_SUBSCRIPTIONS_H
