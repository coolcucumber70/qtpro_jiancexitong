#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtosql.h"
#include "qshowsql.h"
#include    <QtSql>
#include<QString>
#include<QButtonGroup>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag=1;
    creattab();
    // 创建线程对象
    QThread* t = new QThread;
    QToSql* worker = new QToSql;
    worker->moveToThread(t);
    QThread* t2 = new QThread;
    Qshowsql* worker2 = new Qshowsql;
    worker->moveToThread(t2);

    draw=new drawfuction(this);
    ui->chartView->setChart(draw->chart);

    threadProducer=new QThreadDAQ;
    threadConsumer= new QThreadShow;

    connect(threadProducer, &QThreadDAQ::started, this, [=]()
    {
        ui->plainTextEdit->appendPlainText("Thread Producer状态: started");

    });
    connect(threadProducer,&QThreadDAQ::finished,this,[=](){
         ui->plainTextEdit->appendPlainText("Thread Producer状态: finished");
    });

    connect(threadConsumer,&QThreadShow::started,this,[=](){
         ui->plainTextEdit->appendPlainText("Thread Consumer状态: started");
    });
    connect(threadConsumer,&QThreadShow::finished,this,[=](){
         ui->plainTextEdit->appendPlainText("Thread Consumer状态: finished");
    });
    connect(this, &MainWindow::startConnect, threadProducer, &QThreadDAQ::connectServer);
    connect(this, &MainWindow::CloseConnect, threadProducer, &QThreadDAQ::disconnectServer);

    connect(threadProducer, &QThreadDAQ::connectOK, this, [=](){
         QMessageBox::information(this, "连接服务器", "已经成功连接了服务器, 恭喜!");
         m_status->setPixmap(QPixmap(":/images/connect.png").scaled(20, 20));
    });
    connect(ui->StaQuery,&QPushButton::clicked,worker2,&Qshowsql::showsql);
    connect(threadProducer, &QThreadDAQ::gameover, this, [=](){
         m_status->setPixmap(QPixmap(":/images/disconnect.png").scaled(20, 20));
         threadConsumer->terminate(); //因为threadB可能处于等待状态，所以用terminate强制结束
         threadConsumer->wait();//
         //threadConsumer->deleteLater();
         threadProducer->terminate();//结束线程的run()函数执行
         threadProducer->wait();//
         //threadProducer->deleteLater();
    });
    connect(worker,&QToSql::ConnectOk,this,[=](){
        QMessageBox::information(this, "连接数据库", "已经成功连接了数据库,插入数据吧！ 恭喜!");

    });
    connect(worker2,&Qshowsql::ConnectOk,this,[=](){
        QMessageBox::information(this, "连接数据库", "已经成功连接了数据库,显示数据吧！ 恭喜!");

    });
    connect(this,&MainWindow::sendsqlname,worker,&QToSql::connectsql);
    connect(this,&MainWindow::sendsqlname2,worker2,&Qshowsql::connectsql);
    connect(threadConsumer,&QThreadShow::newValue,worker,&QToSql::recdata);
    connect(threadConsumer,&QThreadShow::newValue,
            this,[=](int *data, int count)
    {
        int a[260];
        for(int i=0;i<260;i++)
        {
            a[i]=data[i];
        }
        QLineSeries *series=(QLineSeries *)ui->chartView->chart()->series().at(0);
        series->clear();
        int sum=(flag-1)*20;
        QString  str1=QString::asprintf("接收总数据量：%d",count);
        QString  str2=QString::asprintf("传感器编号：%d  ",flag);
        for(int i=0;i<20;i++)
        {
            series->append(i,a[i+sum]);
            str2=str2+QString::asprintf("%d, ",a[i+sum]);
        }
         //str=str+'\n';
        ui->showdate->appendPlainText(str1);
        ui->showdate->appendPlainText(str2);
    });
    connect(worker2,&Qshowsql::sendmodel,this,[=](QSqlQueryModel* q){
        ui->StableView->setModel(q);
    }
);
    t->start();
    t2->start();
    connect(bgGroup,SIGNAL(buttonClicked(int)),this,SLOT(getcheckid(int)));



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::creattab()
{
    ui->port->setText("8899");
    ui->ip->setText("127.0.0.1");
    setWindowTitle("船舶应力监测软件");
    m_status = new QLabel;
    m_status->setPixmap(QPixmap(":/images/disconnect.png").scaled(20, 20));
    ui->statusBar->addWidget(new QLabel("连接状态: "));
    ui->statusBar->addWidget(m_status);
    bgGroup = new QButtonGroup( this );
    bgGroup->addButton(ui->rbn1,1);
    bgGroup->addButton(ui->rbn2,2);
    bgGroup->addButton(ui->rbn3,3);
    bgGroup->addButton(ui->rbn3,3);
    bgGroup->addButton(ui->rbn4,4);
    bgGroup->addButton(ui->rbn5,5);
    bgGroup->addButton(ui->rbn6,6);
    bgGroup->addButton(ui->rbn7,7);
    bgGroup->addButton(ui->rbn8,8);
    bgGroup->addButton(ui->rbn9,9);
    bgGroup->addButton(ui->rbn10,10);
    bgGroup->addButton(ui->rbn11,11);\
    bgGroup->addButton(ui->rbn12,12);
    bgGroup->addButton(ui->rbn13,13);
    ui->showdate->appendPlainText("wocao");

}

void MainWindow::getcheckid(int id)
{
   flag=id;
   switch (id) {
   case 1:
      ui->PointName->setText("船体结构应力测点1‘");
      ui->PointPos->setText("#121，7250，01甲板下表面");
      ui->PointRe->setText("X向（长基线）");
      break;
   case 2:
       ui->PointName->setText("船体结构应力测点2");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 3:
       ui->PointName->setText("船体结构应力测点3");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 4:
       ui->PointName->setText("船体结构应力测点4");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 5:
       ui->PointName->setText("船体结构应力测点5");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 6:
       ui->PointName->setText("船体结构应力测点6");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 7:
       ui->PointName->setText("船体结构应力测点7");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 8:
       ui->PointName->setText("船体结构应力测点8");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 9:
       ui->PointName->setText("船体结构应力测点9");
       ui->PointPos->setText("#121，7250，01甲板下表面");
       ui->PointRe->setText("X向（长基线）");
       break;
   case 10:
       ui->PointName->setText("船体结构应力测点10");
       ui->PointPos->setText("#71,7650,1甲板圆弧外板内表面(与扁钢相交处)");
       ui->PointRe->setText("XYZ三向");
       break;
   case 11:
       ui->PointName->setText("船体加速度测点1");
       ui->PointPos->setText("#12+250,0,1甲板下表面");
       ui->PointRe->setText("加速度");
       break;
   case 12:
       ui->PointName->setText("船体加速度测点2");
       ui->PointPos->setText("#237+250,0,1甲板下表面");
       ui->PointRe->setText("加速度");
       break;
   case 13:
       ui->PointName->setText("姿态传感器");
       ui->PointPos->setText("#108，0，1甲板下");
       ui->PointRe->setText("姿态传感器");
       break;
   default:
       break;
   }
}

void MainWindow::on_TotalRbtn_clicked()
{
  ui->rbn1->setEnabled(true);
  ui->rbn2->setEnabled(true);
  ui->rbn3->setEnabled(true);
  ui->rbn4->setEnabled(false);
  ui->rbn5->setEnabled(false);
  ui->rbn6->setEnabled(false);
  ui->rbn7->setEnabled(false);
  ui->rbn8->setEnabled(false);
  ui->rbn9->setEnabled(false);
  ui->rbn10->setEnabled(false);
  ui->rbn11->setEnabled(false);
  ui->rbn12->setEnabled(false);
  ui->rbn13->setEnabled(false);

}

void MainWindow::on_LocalRbtn_clicked()
{
    ui->rbn1->setEnabled(false);
    ui->rbn2->setEnabled(false);
    ui->rbn3->setEnabled(false);
    ui->rbn4->setEnabled(true);
    ui->rbn5->setEnabled(true);
    ui->rbn6->setEnabled(true);
    ui->rbn7->setEnabled(true);
    ui->rbn8->setEnabled(true);
    ui->rbn9->setEnabled(true);
    ui->rbn10->setEnabled(false);
    ui->rbn11->setEnabled(false);
    ui->rbn12->setEnabled(false);
    ui->rbn13->setEnabled(false);
}

void MainWindow::on_AccRbtn_clicked()
{
    ui->rbn1->setEnabled(false);
    ui->rbn2->setEnabled(false);
    ui->rbn3->setEnabled(false);
    ui->rbn4->setEnabled(false);
    ui->rbn5->setEnabled(false);
    ui->rbn6->setEnabled(false);
    ui->rbn7->setEnabled(false);
    ui->rbn8->setEnabled(false);
    ui->rbn9->setEnabled(false);
    ui->rbn10->setEnabled(true);
    ui->rbn11->setEnabled(true);
    ui->rbn12->setEnabled(true);
    ui->rbn13->setEnabled(true);
}

void MainWindow::on_toolBox_2_currentChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);//ToolBox当前页与tabWidget的当前页联动
}

void MainWindow::on_btnStartThread_clicked()
{
    threadConsumer->start();
    threadProducer->start();
    ui->btnStartThread->setEnabled(false);
}
void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ui->stackedWidget_2->setCurrentIndex(currentRow);//ToolBox当前页与tabWidget的当前页联动
}

void MainWindow::on_connectServer_clicked()
{

    QString ip = ui->ip->text();
    unsigned short port = ui->port->text().toUShort();
    emit startConnect(port, ip);
    ui->connectServer->setEnabled(false);
    ui->disconnectServer->setEnabled(true);
}


void MainWindow::on_disconnectServer_clicked()
{
    emit CloseConnect();

    ui->connectServer->setEnabled(true);
    ui->disconnectServer->setEnabled(false);
}

void MainWindow::on_conectDB_clicked()
{

    QString name=QString("DRIVER={SQL SERVER};"
                         "SERVER=%1;" //服务器名称
                         "DATABASE=%2;"//数据库名
                         "UID=%3;"           //登录名
                         "PWD=%4;"        //密码
                         ).arg(ui->Tname->text())
                 .arg(ui->Sname->text())
                 .arg(ui->Aname->text())
                 .arg(ui->Pname->text());
    qDebug()<<name;
    emit sendsqlname(name,"insert");
    emit sendsqlname2(name);
}

