#include "drawfuction.h"

drawfuction::drawfuction(QObject *parent) : QObject(parent)
{
    createChart();
}

void drawfuction::createChart()
{
    chart = new QChart();
    QLineSeries *series0 = new QLineSeries();
    series0->setName("应力曲线");
    curSeries=series0; //当前序列
    QPen    pen;
    pen.setStyle(Qt::SolidLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    pen.setWidth(2);
    pen.setColor(Qt::green);
    series0->setPen(pen); //折线序列的线条设置
    chart->addSeries(series0);

    QValueAxis *axisX = new QValueAxis;
    curAxis=axisX; //当前坐标轴
    axisX->setRange(0, 20); //设置坐标轴范围
    axisX->setLabelFormat("%.1f"); //标签格式
    axisX->setTickCount(11); //主分隔个数
    axisX->setMinorTickCount(4);
    axisX->setTitleText("time(secs)"); //标题

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);
    axisY->setTitleText("value");
    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f"); //标签格式
//    axisY->setGridLineVisible(false);
    axisY->setMinorTickCount(4);
    chart->addAxis(axisX,Qt::AlignBottom); //坐标轴添加到图表，并指定方向
    chart->addAxis(axisY,Qt::AlignLeft);
    series0->attachAxis(axisX); //序列 series0 附加坐标轴
    series0->attachAxis(axisY);
}
