#include "qshowsql.h"
#include    <QtSql>
#include <QSqlQuery>

Qshowsql::Qshowsql(QObject *parent) : QObject(parent)
{

}

void Qshowsql::connectsql(QString name)
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(name);
    if (db.open())   //打开数据库
    {
        emit ConnectOk();
    }
}

void Qshowsql::showsql()
{
    QString qStr="SELECT TOP 1000 [ID],[dtime],[sensor1],[sensor2],[sensor3],[sensor4],[sensor5],[sensor6],[sensor7],[sensor8],"
                 "[sensor9],[sensor10],[sensor11],[sensor12],[sensor13] FROM [school].[dbo].[mytest] order by [ID] desc";
    model.setQuery(qStr);
    if (model.lastError().isValid())
    {
        return;
    }
    emit sendmodel(&model);
}
