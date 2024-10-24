#include "screenshottool.h"

ScreenshotTool::ScreenshotTool(QWidget *parent) : QWidget(parent), selecting(false) {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    showFullScreen(); // 全屏显示窗口
}

void ScreenshotTool::startSelection() {
    selecting = true;
    show(); // 显示截图工具
}

void ScreenshotTool::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

    if (selecting) {
        QPainter painter(this);
        painter.setPen(Qt::red);
        painter.setBrush(QColor(255, 0, 0, 50)); // 半透明填充
        QRect rect(startPos, endPos);
        painter.drawRect(rect);
    }
}

void ScreenshotTool::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        selecting = true;
        startPos = event->pos();
    }
}

void ScreenshotTool::mouseMoveEvent(QMouseEvent *event) {
    if (selecting) {
        endPos = event->pos();
        update(); // 更新界面
    }
}

void ScreenshotTool::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        selecting = false;
        endPos = event->pos();
        takeScreenshot();
        update(); // 更新界面
    }
}

void ScreenshotTool::enterEvent(QEnterEvent *event) {
    QGuiApplication::setOverrideCursor(Qt::CrossCursor); // 设置十字光标
    QWidget::enterEvent(event); // 调用基类方法
}

void ScreenshotTool::leaveEvent(QEvent *event) {
    QGuiApplication::restoreOverrideCursor(); // 恢复光标
    QWidget::leaveEvent(event); // 调用基类方法
}

void ScreenshotTool::takeScreenshot() {
    QRect rect(QPoint(qMin(startPos.x(), endPos.x()), qMin(startPos.y(), endPos.y())),
               QPoint(qMax(startPos.x(), endPos.x()), qMax(startPos.y(), endPos.y())));

    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) return;

    QPixmap screenshot = screen->grabWindow(0, rect.x(), rect.y(), rect.width(), rect.height());
    emit screenshotTaken(screenshot); // 发射信号
}
