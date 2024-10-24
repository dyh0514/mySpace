#include "apimanager.h"
#include <QDebug>
#include <QElapsedTimer>
ApiManager::ApiManager(QObject *parent)
    : QObject{parent},networkManager(new QNetworkAccessManager(this))
{

}
void ApiManager::translate(const QString &text, const QString &api) {
    // 根据API进行翻译的具体实现
    if (api == "Google Translate") {
        // 调用Google翻译的逻辑
    } else if (api == "Baidu Translate") {
        // 调用百度翻译的逻辑
        translateWithBaidu(text);
    } else if (api == "Tencent Translate") {
        // 调用腾讯翻译的逻辑
    }

    // 模拟翻译结果
    QString result;
    emit translationFinished(result);
}
void ApiManager::translateWithBaidu(const QString &text){
    qDebug()<<"translateWithBaidu1";
    QString url = QString("https://fanyi-api.baidu.com/api/trans/vip/translate");
    QString salt = QString::number(QDateTime::currentMSecsSinceEpoch());
    QString sign = QString(QCryptographicHash::hash((baidu_appid + text + salt + baidu_secret).toUtf8(), QCryptographicHash::Md5).toHex());

    QUrl queryUrl(url);
    QUrlQuery query;
    query.addQueryItem("q", text);
    query.addQueryItem("from", "auto");  // 自动检测源语言
    query.addQueryItem("to", "zh");  // 目标语言
    query.addQueryItem("appid", baidu_appid);
    query.addQueryItem("salt", salt);
    query.addQueryItem("sign", sign);
    queryUrl.setQuery(query);

    QNetworkRequest request;
    request.setUrl(queryUrl);//-----------------------------------error
    QNetworkReply *reply = networkManager->get(request);
    qDebug()<<"translateWithBaidu2";
    connect(reply, &QNetworkReply::finished, this, &ApiManager::onTranslationReply);
}

void ApiManager::onTranslationReply(){
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    QElapsedTimer timer; // 添加定时器
    timer.start();

    if (reply) {
        qDebug() << "Reply received after" << timer.elapsed() << "ms";
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            // 解析 JSON 响应
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            if (jsonResponse.isObject()) {
                QJsonObject jsonObject = jsonResponse.object();
                QString translatedText = jsonObject["trans_result"].toArray()[0].toObject()["dst"].toString();
                emit translationFinished(translatedText);
            }
        } else {
            emit translationFinished("翻译失败");
        }
        reply->deleteLater();
    }

    qDebug() << "Total processing time:" << timer.elapsed() << "ms";
}

void ApiManager::ocrRecognize(const QImage &image) {
    // 将 QImage 转换为 QByteArray
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG"); // 将图像保存为 PNG 格式

    // 发送 OCR 请求（需要实现具体 API 调用）
    // 这里需要设置合适的 API URL 和请求头，上传 byteArray
}
