#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QSqlError>
#include <QDebug>

class Database {
public:
    static bool initialize(const QString &host, const QString &dbName, const QString &user, const QString &password) {
        QSqlDatabase db = QSqlDatabase::addDatabase("myTransApp");
        db.setHostName(host);
        db.setDatabaseName(dbName);
        db.setUserName(user);
        db.setPassword(password);
        if (!db.open()) {
            qDebug() << "Database connection failed:" << db.lastError().text();
            return false;
        }
        qDebug() << "Database connection successful!";
        return true;
    }
};

#endif // DATABASE_H
