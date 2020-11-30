#ifndef TICKETGROUPBOX_H
#define TICKETGROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>
class TicketGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit TicketGroupBox(QWidget *parent = nullptr);

    QGroupBox    *TicketBox;
    QPushButton  *TicketDeleteButton;
    QPushButton  *TicketUpdateButton;
    QLabel       *TicketId;
    QComboBox    *TicketShowId;
    QCheckBox    *TicketVIP;
    QLineEdit    *TicketBuyerEmail;
    QLabel       *TicketPrice;

signals:

};

#endif // TICKETGROUPBOX_H
