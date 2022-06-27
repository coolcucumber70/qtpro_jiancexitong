#ifndef QMYTHREAD_H
#define QMYTHREAD_H

//#include    <QObject>
#include <QTcpSocket>
#include    <QThread>

class QThreadDAQ : public QThread
{
    Q_OBJECT

private:
    QTcpSocket* m_tcp;
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    QThreadDAQ();
    void connectServer(unsigned short port, QString ip);
    void disconnectServer();
    void stopThread();
signals:
    void connectOK();    
    void gameover();
};

class QThreadShow : public QThread
{
    Q_OBJECT
private:
    bool    m_stop=false; //停止线程
protected:
    void    run() Q_DECL_OVERRIDE;
public:
    QThreadShow();
    void    stopThread();
signals:
    void    newValue(int *data,int count);
};
#endif // QMYTHREAD_H
