#include "client.h"

client::client(QObject *parent) : QObject(parent)
{
    tcpClient=new QTcpSocket(this); //创建socket变量
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));

    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));
}

void client::onConnected()
{

}

void client::onDisconnected()
{

}

void client::onSocketStateChange(QAbstractSocket::SocketState socketState)
{

}

void client::onSocketReadyRead()
{
    while(tcpClient->canReadLine())
        ui->plainTextEdit->appendPlainText("[in] "+tcpClient->readLine());
}
