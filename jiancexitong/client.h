#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = nullptr);
private:
    QTcpSocket  *tcpClient;  //socket

signals:

public slots:
    void    onConnected();
    void    onDisconnected();
    void    onSocketStateChange(QAbstractSocket::SocketState socketState);
    void    onSocketReadyRead();//读取socket传入的数据
};

#endif // CLIENT_H
