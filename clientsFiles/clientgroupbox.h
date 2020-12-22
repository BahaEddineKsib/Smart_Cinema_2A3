#ifndef CLIENTGROUPBOX_H
#define CLIENTGROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
class ClientGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit ClientGroupBox(QWidget *parent = nullptr);
    QGroupBox *ClientBox;
    QLineEdit *ClientSubscriptionIdEdit;
    QLineEdit *ClientEmailEdit;
    QLineEdit *ClientNameEdit;
    QLabel *ClientId;
    QPushButton *ClientUpdateButton;
    QPushButton *ClientDeleteButton;
    QDateEdit *ClientSubscriptionDateEdit;
public slots:
    void UpdateClientSlot();
    void DeleteClientSlot();
};

#endif // CLIENTGROUPBOX_H
