#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QVariant>

class UserManager {
public:
    static bool registerUser(const QString &username, const QString &password) {
        QString hashedPassword = hashPassword(password);

        QSqlQuery query;
        query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password_hash)");
        query.bindValue(":username", username);
        query.bindValue(":password_hash", hashedPassword);

        if (!query.exec()) {
            qDebug() << "User registration failed:" << query.lastError().text();
            return false;
        }
        return true;
    }

    static bool loginUser(const QString &username, const QString &password) {
        QSqlQuery query;
        query.prepare("SELECT password_hash FROM users WHERE username = :username");
        query.bindValue(":username", username);

        if (!query.exec() || !query.next()) {
            qDebug() << "Login failed: User not found.";
            return false;
        }

        QString storedHash = query.value(0).toString();
        return verifyPassword(password, storedHash);
    }

    static bool updateApiKey(const QString &username, const QString &baiduKey, const QString &tencentKey) {
        QSqlQuery query;
        query.prepare("UPDATE users SET baidu_api_key = :baiduKey, tencent_api_key = :tencentKey WHERE username = :username");
        query.bindValue(":baiduKey", baiduKey);
        query.bindValue(":tencentKey", tencentKey);
        query.bindValue(":username", username);

        if (!query.exec()) {
            qDebug() << "Failed to update API keys:" << query.lastError().text();
            return false;
        }
        return true;
    }

private:
    static QString hashPassword(const QString &password) {
        QByteArray salt = "SomeRandomSalt"; // 应用真实的随机盐
        QByteArray hash = QCryptographicHash::hash((password + salt).toUtf8(), QCryptographicHash::Sha256);
        return QString(hash.toHex());
    }

    static bool verifyPassword(const QString &password, const QString &storedHash) {
        return hashPassword(password) == storedHash;
    }
};

#endif // USERMANAGER_H
