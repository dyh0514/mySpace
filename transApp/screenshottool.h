// screenshottool.h
#ifndef SCREENSHOTTOOL_H
#define SCREENSHOTTOOL_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QScreen>
#include <QGuiApplication>
#include <QPixmap>

class ScreenshotTool : public QWidget {
    Q_OBJECT

public:
    ScreenshotTool(QWidget *parent = nullptr);
    void startSelection();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void screenshotTaken(const QPixmap &screenshot);

private:
    bool selecting;
    QPoint startPos;
    QPoint endPos;

    void takeScreenshot();
};

#endif // SCREENSHOTTOOL_H
