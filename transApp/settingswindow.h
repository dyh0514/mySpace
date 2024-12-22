#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QSlider>
#include <QColor>
#include <QFont>
#include <QSettings>

class SettingsWindow : public QWidget {
    Q_OBJECT
public:
    // 添加username参数
    explicit SettingsWindow(QWidget *parent = nullptr, const QString &username = "");

signals:
    void backgroundColorChanged(const QColor &color);
    void fontChanged(const QFont &font);
    void transparencyChanged(double opacity);

private slots:
    void selectBackgroundColor();
    void selectFont();
    void changeTransparency(int value);
    void saveSettings();

private:
    QString currentUsername; // 存储当前用户名
    QSlider *opacitySlider;
    QColor currentBackgroundColor;
    QFont currentFont;
    double currentOpacity;

    void loadSettings();
    void applySettings();
    void loadApiKeys();
    void saveApiKeys(const QString &baiduKey, const QString &tencentKey);
};

#endif // SETTINGSWINDOW_H
