#ifndef SUBSCRIPTIONGROUPBOX_H
#define SUBSCRIPTIONGROUPBOX_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>

class SubscriptionGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit SubscriptionGroupBox(QWidget *parent = nullptr);

    QFrame *SubscriptionBox;
    QPushButton *SubscriptionUpdateButton;
    QPushButton *SubscriptionDeleteButton;
    QLabel *SubscriptionIdTitleEdit;
    QLabel *SubscriptionId;
    QLabel *SubscriptionNumberOfDaysEditTitle;
    QLineEdit *SubscriptionNumberOfDaysEdit;
    QCheckBox *SubscriptionFreeFoodEdit;
    QLabel *SubscriptionFreeFoodTitleEdit;
    QLabel *SubscriptionPriceDT;
    QLineEdit *SubscriptionPriceEdit;
    QLineEdit *SubscriptionNameEdit;

public slots:
    void UpdateSubscriptionSlot();
    void DeleteSubscriptionSlot();
signals:

};

#endif // SUBSCRIPTIONGROUPBOX_H
