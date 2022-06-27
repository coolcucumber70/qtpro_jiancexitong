#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtCharts>
#include<QQueue>
#include <QTcpSocket>
#include "sensor.h"
#include "qmythread.h"
#include "drawfuction.h"
#include<QVector>
#include<QThread>
#include    <QtSql>
#include<QButtonGroup>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<QVector<float>>SD;
    int flag=0;
private:

    QList<Sensor>* SensorList;
    QThreadDAQ*   threadProducer;
    QThreadShow*   threadConsumer;
    drawfuction* draw;
    QTimer timer;
    QLabel* m_status;
    QButtonGroup* bgGroup;


private:
    void creattab();

signals:
    void startConnect(unsigned short, QString);
    void CloseConnect();
    void sendsqlname(QString,QString);
    void sendsqlname2(QString);


private slots:
    void getcheckid(int id);

    void on_TotalRbtn_clicked();

    void on_LocalRbtn_clicked();

    void on_AccRbtn_clicked();

    void on_toolBox_2_currentChanged(int index);
    void on_btnStartThread_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_connectServer_clicked();
    void on_disconnectServer_clicked();

    void on_conectDB_clicked();
    

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
