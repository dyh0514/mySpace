#include "settingswindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QFontDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>


SettingsWindow::SettingsWindow(QWidget *parent, const QString &username)
    : QWidget(parent), currentUsername(username), currentOpacity(1.0) {
    setWindowTitle("设置窗口");
    setFixedSize(300, 250);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *colorButton = new QPushButton("选择背景色", this);
    layout->addWidget(colorButton);
    connect(colorButton, &QPushButton::clicked, this, &SettingsWindow::selectBackgroundColor);

    QPushButton *fontButton = new QPushButton("选择字体", this);
    layout->addWidget(fontButton);
    connect(fontButton, &QPushButton::clicked, this, &SettingsWindow::selectFont);

    opacitySlider = new QSlider(Qt::Horizontal, this);
    opacitySlider->setRange(0, 100);
    opacitySlider->setValue(100);  // 默认值为 100
    layout->addWidget(opacitySlider);
    connect(opacitySlider, &QSlider::valueChanged, this, &SettingsWindow::changeTransparency);

    QPushButton *saveButton = new QPushButton("保存设置", this);
    layout->addWidget(saveButton);
    connect(saveButton, &QPushButton::clicked, this, &SettingsWindow::saveSettings);

    setLayout(layout);

    loadSettings();
    applySettings();
    loadApiKeys();  // 加载 API 密钥
}

void SettingsWindow::selectBackgroundColor() {
    QColor color = QColorDialog::getColor(Qt::white, this, "选择背景色");
    if (color.isValid()) {
        currentBackgroundColor = color;
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, color);
        this->setPalette(palette);
        emit backgroundColorChanged(color);
    }
}

void SettingsWindow::selectFont() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Arial", 12), this, "选择字体");
    if (ok) {
        currentFont = font;
        emit fontChanged(font);
    }
}

void SettingsWindow::changeTransparency(int value) {
    currentOpacity = value / 100.0;
    setWindowOpacity(currentOpacity);
    emit transparencyChanged(currentOpacity);
}

void SettingsWindow::saveSettings() {
    QSettings settings("MyApp", "TranslateApp");
    settings.setValue("backgroundColor", currentBackgroundColor.name());
    settings.setValue("font", currentFont.toString());
    settings.setValue("opacity", currentOpacity);
    qDebug() << "设置已保存！";
}

void SettingsWindow::loadSettings() {
    QSettings settings("MyApp", "TranslateApp");
    if (settings.contains("backgroundColor")) {
        currentBackgroundColor = QColor(settings.value("backgroundColor").toString());
    } else {
        currentBackgroundColor = Qt::white;
    }

    if (settings.contains("font")) {
        currentFont.fromString(settings.value("font").toString());
    } else {
        currentFont = QFont("Arial", 12);
    }

    if (settings.contains("opacity")) {
        currentOpacity = settings.value("opacity").toDouble();
    } else {
        currentOpacity = 1.0;
    }
}

void SettingsWindow::applySettings() {
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, currentBackgroundColor);
    this->setPalette(palette);

    setWindowOpacity(currentOpacity);

    setFont(currentFont);

    qDebug() << "设置已应用！";
}

void SettingsWindow::loadApiKeys() {
    QSqlQuery query;
    query.prepare("SELECT baidu_api_key, tencent_api_key FROM users WHERE username = :username");
    query.bindValue(":username", currentUsername);

    if (query.exec() && query.next()) {
        QString baiduKey = query.value(0).toString();
        QString tencentKey = query.value(1).toString();
        qDebug() << "Loaded API Keys for user:" << currentUsername;
    } else {
        qDebug() << "Failed to load API keys:" << query.lastError().text();
    }
}

void SettingsWindow::saveApiKeys(const QString &baiduKey, const QString &tencentKey) {
    QSqlQuery query;
    query.prepare("UPDATE users SET baidu_api_key = :baiduKey, tencent_api_key = :tencentKey WHERE username = :username");
    query.bindValue(":baiduKey", baiduKey);
    query.bindValue(":tencentKey", tencentKey);
    query.bindValue(":username", currentUsername);

    if (query.exec()) {
        QMessageBox::information(this, "保存成功", "API 密钥已保存！");
    } else {
        QMessageBox::warning(this, "保存失败", "无法保存 API 密钥！");
    }
}
