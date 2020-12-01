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
    ~TicketGroupBox();

    QGroupBox    *TicketBox;
    QPushButton  *TicketDeleteButton;
    QPushButton  *TicketUpdateButton;
    QLabel       *TicketId;
    QLineEdit    *TicketShowId;
    QCheckBox    *TicketVIP;
    QLineEdit    *TicketBuyerEmail;
    QLabel       *TicketPrice;

public slots:
    void UpdateTicketSlot();
    void DeleteTicketSlot();
signals:

};

#endif // TICKETGROUPBOX_H
