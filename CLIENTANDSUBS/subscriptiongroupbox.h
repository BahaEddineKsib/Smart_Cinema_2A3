#ifndef subscriptionGROUPBOX_H
#define subscriptionGROUPBOX_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QPlainTextEdit>
#include <QCheckBox>
#include <QGroupBox>
class subscriptionGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit subscriptionGroupBox(QWidget *parent = nullptr);
    ~subscriptionGroupBox();

    QGroupBox      *subscriptionBox;
    QGroupBox      *subscriptionBottomBox;
    QGroupBox      *subscriptionDetailsBox;
    QLabel         *subscriptionDescriptionTitle;
    QLabel         *subscriptionNameTitle;
    QLabel         *subscriptionpriceTitle;
    QLabel         *subscriptionDT;
    QLabel         *subscriptionIdTitle;
    QLabel         *subscriptionIdEdit;
    QLineEdit      *subscriptionNameEdit;
    QLineEdit      *subscriptionpriceEdit;
    QPushButton    *subscriptionUpdateButton;
    QPushButton    *subscriptionDeleteButton;
    QPushButton    *subscriptionImageButton;
    QPushButton    *subscriptionSwipeButton;
public slots:
    void UpdatesubscriptionSlot();
    void DeletesubscriptionSlot();

signals:

};
#endif // subscriptionGROUPBOX_H
