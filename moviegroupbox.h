#ifndef MOVIEGROUPBOX_H
#define MOVIEGROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QPlainTextEdit>
#include <QCheckBox>
class MovieGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit MovieGroupBox(QWidget *parent = nullptr);

    QGroupBox      *MovieBox;
    QPushButton    *MovieImageButton;
    QGroupBox      *MovieBottomBox;
    QGroupBox      *MovieDetailsBox;
    QLineEdit      *MoviePriceEdit;
    QLabel         *MovieDescriptionTitle;
    QLabel         *MovieNameTitle;
    QLabel         *MoviePriceTitle;
    QLabel         *MovieDT;
    QLabel         *MovieIdTitle;
    QLineEdit      *MovieIdEdit;
    QLabel         *MovieSubtitle;
    QLineEdit      *MovieTypeEdit;
    QLabel         *MovieTypeTitle;
    QLineEdit      *MovieNameEdit;
    QPushButton    *MovieUpdateButton;
    QPlainTextEdit *MovieDescriptionEdit;
    QCheckBox      *MovieFrCheck;
    QCheckBox      *MovieArCheck;
    QCheckBox      *MovieEnCheck;
    QPushButton    *MovieDeleteButton;
    QPushButton    *MovieSwipeButton;

signals:

};

#endif // MOVIEGROUPBOX_H
