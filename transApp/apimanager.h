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
    explicit ApiManager(QObject *parent = nullptr);
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
    QNetworkAccessManager * networkManager;
    QString baidu_appid = "20241022002182259"; // 你的百度appid
    QString baidu_secret = "icqpcnauhR05cBmU34VI"; // 你的百度secret

};

#endif // APIMANAGER_H
