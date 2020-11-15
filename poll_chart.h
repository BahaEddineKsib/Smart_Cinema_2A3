#ifndef POLL_CHART_H
#define POLL_CHART_H

#include <QWidget>
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>

#include <QtCharts/QChartView>

using namespace QtCharts;

class poll_chart : public QWidget
{
    Q_OBJECT
public:
    explicit poll_chart(QWidget *parent = nullptr);

    QPieSeries *series = new QPieSeries();
    QPieSlice *slice1;
    QPieSlice *slice2;
    QPieSlice *slice3;

    QChart *chart = new QChart();

    //QChartView *chartView  = new QChartView(chart);

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif // POLL_CHART_H
