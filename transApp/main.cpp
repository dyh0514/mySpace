#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>

int main(int argc, char *argv[]) {
    // 使用 QApplication 而不是 QCoreApplication 来启动图形界面应用
    QApplication a(argc, argv);

    // 检查 MySQL 驱动是否可用
    if (!QSqlDatabase::isDriverAvailable("QMYSQL")) {
        qDebug() << "MySQL 驱动不可用";
        return -1;
    }

    // 添加数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");  // 数据库主机
    db.setDatabaseName("myTransApp");   // 数据库名称
    db.setUserName("root");       // 数据库用户名
    db.setPassword("263646");     // 数据库密码

    // 打开数据库连接
    if (!db.open()) {
        qDebug() << "无法连接到数据库：" << db.lastError().text();
        return -1;
    } else {
        qDebug() << "成功连接到数据库";
    }

    // 创建并显示登录窗口
    LoginWindow loginWindow;
    loginWindow.show();

    return a.exec();
}
