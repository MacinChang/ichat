#ifndef CONNECT
#define CONNECT

#include <QSqlDatabase>
#include <QSqlQuery>
static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query=QSqlQuery::QSqlQuery(db);
    query.exec("create table chatmsg (id int primary key, time vchar, speakerId vchar,listenerId vchar,chatmessage vchar)");
    query.exec("insert into chatmsg values (1,'fgh','df','fg','fasd')");
    return true;
}

#endif // CONNECT

