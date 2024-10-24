#ifndef APIMANAGER_H
#define APIMANAGER_H

#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonArray>
#include <QCryptographicHash>
#include <QDebug>
#include <QBuffer>
#include <QImage>

class ApiManager : public QObject
{
    Q_OBJECT
public:
    // 获取单例实例
    static ApiManager& instance() {
        static ApiManager instance; // 懒汉式单例
        return instance;
    }

    // 禁止拷贝构造和赋值
    ApiManager(const ApiManager&) = delete;
    ApiManager& operator=(const ApiManager&) = delete;

    explicit ApiManager(QObject *parent = nullptr); // 构造函数私有化
    void translate(const QString &text, const QString &api);

private:
    void translateWithBaidu(const QString &text);
    //void translateWithTencent(const QString &text);
    // 添加其他API的函数------------------------------------todo

    void ocrRecognize(const QImage &image);

private slots:
    void onTranslationReply();

signals:
    void translationFinished(const QString &result);

public:
    QNetworkAccessManager *networkManager;
    QString baidu_appid = "20241022002182259"; // 你的百度appid
    QString baidu_secret = "icqpcnauhR05cBmU34VI"; // 你的百度secret
};

#endif // APIMANAGER_H
