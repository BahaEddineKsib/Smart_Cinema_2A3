#ifndef THEATREGROUPBOX_H
#define THEATREGROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class TheatreGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit TheatreGroupBox(QWidget *parent = nullptr);

    QGroupBox *TheatreBox;
    QLabel *TheatreIdEdit;
    QLabel *TheatreNameEditTitle;
    QLabel *TheatreSeatsEditTitle;
    QLineEdit *TheatreSeatsEdit;
    QLineEdit *TheatreVIP_SeatsEdit;
    QLabel *TheatreVIP_SeatsEditTitle;
    QPushButton *TheatreUpdateButton;
    QPushButton *TheatreDeleteButton;
    QLineEdit *TheatreNameEdit;
    QLabel *TheatreIdEditTitle;

public slots:
    void UpdateTheatreSlot();
    void DeleteTheatreSlot();

signals:

};

#endif // THEATREGROUPBOX_H
