#include "poll_chart.h"
#include <QPainter>
#include <QPen>


poll_chart::poll_chart(QWidget *parent) : QWidget(parent)
{

    /*series->append("Pulp Fiction",20);
    series->append("Snatch",12);
    series->append("The Departed",68);

    slice1=series->slices().at(0);
    slice1->setLabelVisible();

    slice1=series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    //slice1->setPen(QPen(QColor(231, 76, 60)));

    slice1->setBrush(QColor(231, 76, 60));

    slice1=series->slices().at(2);
    slice1->setLabelVisible();

    chart->addSeries(series);
    chart->setTitle("Movie Poll");
    chart->legend()->hide();


    //chartView->setRenderHint(QPointer::AntiAliasing);*/
}

void poll_chart::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size = QRectF(40,10,190,190);
    painter.setBrush(QColor(231, 76, 60));
    painter.drawPie(size,0,60*16);
    painter.setBrush(QColor(22, 160, 133));
    painter.drawPie(size,60*16,80*16);
    painter.setBrush(QColor(230, 126, 34));
    painter.drawPie(size,120*16,240*16);





}
