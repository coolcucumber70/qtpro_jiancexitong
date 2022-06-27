#include    "qmythread.h"
#include    <QSemaphore>
#include <QHostAddress>
#include<QTime>
#include<QTimer>

const int BufferSize = 260;
int buffer1[BufferSize];
int buffer2[BufferSize];
int readnum=1;
int curBuf=1;//当前正在写入的Buffer
QSemaphore emptyBufs(2);//信号量：空的缓冲区个数，初始资源个数为2
QSemaphore fullBufs; //满的缓冲区个数，初始资源为0

QThreadDAQ::QThreadDAQ()
{

}

void QThreadDAQ::connectServer(unsigned short port, QString ip)
{
    //qDebug() << "连接服务器线程: " << QThread::currentThread();
    m_tcp = new QTcpSocket;
    m_tcp->connectToHost(QHostAddress(ip), port);

    connect(m_tcp, &QTcpSocket::connected, this, &QThreadDAQ::connectOK);
    connect(m_tcp, &QTcpSocket::disconnected, this, [=](){
        m_tcp->close();
        m_tcp->deleteLater();
        emit gameover();
    });
}

void QThreadDAQ::disconnectServer()
{
    if (m_tcp->state()==QAbstractSocket::ConnectedState)
        m_tcp->disconnectFromHost();
}

void QThreadDAQ::run()
{
    curBuf=1; //当前写入使用的缓冲区    线程同步
    int n=emptyBufs.available();
    if (n<2)  //保证 线程启动时emptyBufs.available==2
      emptyBufs.release(2-n);
    connect(m_tcp, &QTcpSocket::readyRead, this, [=]()
    {
         QByteArray array = m_tcp->readAll();
         readnum=array.size()/4;
         emptyBufs.acquire();//获取一个空的缓冲区
         if (curBuf==1)
             {
                  memcpy(&buffer1, array.data(), BufferSize*4);
             }
         else
             {
                 memcpy(&buffer2, array.data(), BufferSize*4);
             }
         if (curBuf==1) // 切换当前写入缓冲区
           curBuf=2;
         else
           curBuf=1;

         fullBufs.release(); //有了一个满的缓冲区,available==1
    });
    exec();
}

void QThreadShow::run()
{
    m_stop=false;//启动线程时令m_stop=false

    int n=fullBufs.available();
    if (n>0)
       fullBufs.acquire(n); //将fullBufs可用资源个数初始化为0

    while(!m_stop)//循环主体
    {
        fullBufs.acquire(); //等待有缓冲区满,当fullBufs.available==0阻塞

        int bufferData[BufferSize];
        if(curBuf==1) //当前在写入的缓冲区是1，那么满的缓冲区是2
            for (int i=0;i<BufferSize;i++)
               bufferData[i]=buffer2[i]; //快速拷贝缓冲区数据
        else
            for (int i=0;i<BufferSize;i++)
               bufferData[i]=buffer1[i];

        emptyBufs.release();//释放一个空缓冲区
        emit    newValue(bufferData,readnum);//给主线程传递数据
    }
    quit();
}

QThreadShow::QThreadShow()
{

}

void QThreadShow::stopThread()
{
    m_stop=true;
}
