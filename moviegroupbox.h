#ifndef MOVIEGROUPBOX_H
#define MOVIEGROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QPlainTextEdit>
#include <QCheckBox>
#include <QPropertyAnimation>
class MovieGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit MovieGroupBox(QWidget *parent = nullptr);
    ~MovieGroupBox();

    QGroupBox      *MovieBox;
    QGroupBox      *MovieBottomBox;
    QGroupBox      *MovieDetailsBox;
    QLabel         *MovieDescriptionTitle;
    QLabel         *MovieNameTitle;
    QLabel         *MoviePriceTitle;
    QLabel         *MovieDT;
    QLabel         *MovieIdTitle;
    QLabel         *MovieIdEdit;
    QLabel         *MovieTypeTitle;
    QLabel         *MovieSubLanguageTitle;
    QLabel         *MovieDubLanguageTitle;
    QLineEdit      *MovieTypeEdit;
    QLineEdit      *MovieNameEdit;
    QLineEdit      *MoviePriceEdit;
    QLineEdit      *MovieSubLanguageEdit;
    QLineEdit      *MovieDubLanguageEdit;
    QPlainTextEdit *MovieDescriptionEdit;
    QPushButton    *MovieUpdateButton;
    QPushButton    *MovieDeleteButton;
    QPushButton    *MovieImageButton;
    QPushButton    *MovieSwipeButton;
    QPropertyAnimation *animation;
public slots:
    void UpdateMovieSlot();
    void DeleteMovieSlot();
    void Animation();

signals:

};

#endif // MOVIEGROUPBOX_H
