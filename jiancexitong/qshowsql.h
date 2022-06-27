#ifndef QSHOWSQL_H
#define QSHOWSQL_H

#include <QObject>
#include    <QtSql>
#include <QSqlQuery>
class Qshowsql : public QObject
{
    Q_OBJECT
public:
    explicit Qshowsql(QObject *parent = nullptr);
    void showsql();
    QSqlDatabase db;
    QSqlQueryModel model;
     void connectsql(QString name);

signals:
     void ConnectOk();
     void sendmodel(QSqlQueryModel*q);

public slots:
};

#endif // QSHOWSQL_H
