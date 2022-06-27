#ifndef DRAWFUCTION_H
#define DRAWFUCTION_H
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE
class drawfuction : public QObject
{
    Q_OBJECT
public:
    explicit drawfuction(QObject *parent = nullptr);
    QLineSeries *curSeries; //当前序列
    QValueAxis *curAxis; //当前坐标轴
    QChart *chart;
    void createChart(); //创建图表


signals:

private slots:

};

#endif // DRAWFUCTION_H
