#ifndef CLIENTGROUPBOX_H
#define CLIENTGROUPBOX_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QPlainTextEdit>
#include <QCheckBox>
#include <QGroupBox>
class clientGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit clientGroupBox(QWidget *parent = nullptr);
    ~clientGroupBox();

    QGroupBox      *clientBox;
    QGroupBox      *clientBottomBox;
    QGroupBox      *clientDetailsBox;
    QLabel         *clientDescriptionTitle;
    QLabel         *clientNameTitle;
    QLabel         *clientEmailTitle;
    QLabel         *clientDT;
    QLabel         *clientIdTitle;
    QLabel         *clientIdEdit;
    QLineEdit      *clientNameEdit;
    QLineEdit      *clientEmailEdit;
    QPushButton    *clientUpdateButton;
    QPushButton    *clientDeleteButton;
    QPushButton    *clientImageButton;
    QPushButton    *clientSwipeButton;
public slots:
    void UpdateclientSlot();
    void DeleteclientSlot();

signals:

};
#endif // CLIENTGROUPBOX_H
