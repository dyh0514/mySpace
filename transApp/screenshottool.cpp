#include "ScreenshotTool.h"
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>

ScreenshotTool::ScreenshotTool(QWidget* parent) : QWidget(parent), isSelecting(false) {
    initUI();
    setGeometry(0, 0, parent->width(), parent->height());
}

ScreenshotTool::~ScreenshotTool() {}

void ScreenshotTool::initUI() {
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    setCursor(Qt::CrossCursor);
}

void ScreenshotTool::startSelection() {
    isSelecting = true;
    selectionRect = QRect(); // 清空选择区域

    // 设置工具窗口覆盖整个屏幕
    QScreen* screen = QGuiApplication::primaryScreen();
    if (!screen) {
        qDebug() << "No screen available for selection!";
        return;
    }

    // 捕获全屏内容
    fullScreenPixmap = captureFullScreen();

    // 设置工具窗口为全屏并显示
    setGeometry(screen->geometry()); // 设置窗口覆盖屏幕
    showFullScreen();

    // 确保鼠标样式为十字
    setCursor(Qt::CrossCursor);
}

void ScreenshotTool::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 绘制全屏截图
    if (!fullScreenPixmap.isNull()) {
        painter.drawPixmap(0, 0, fullScreenPixmap);
    }

    // 绘制灰色遮罩
    painter.fillRect(rect(), QColor(0, 0, 0, 100));

    // 擦除选择区域
    if (!selectionRect.isNull()) {
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        painter.fillRect(selectionRect, QColor(0, 0, 0, 0));
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

        // 绘制选择区域边框
        painter.setPen(QPen(Qt::NoPen));
        painter.drawRect(selectionRect);
    }
}

void ScreenshotTool::mousePressEvent(QMouseEvent* event) {
    if (isSelecting) {
        selectionRect.setTopLeft(event->pos());
        selectionRect.setBottomRight(event->pos());
        update(); // 触发重绘
    }
}

void ScreenshotTool::mouseMoveEvent(QMouseEvent* event) {
    if (isSelecting) {
        selectionRect.setBottomRight(event->pos());
        update(); // 实时更新选择区域
    }
}

void ScreenshotTool::mouseReleaseEvent(QMouseEvent* event) {
    if (isSelecting) {
        isSelecting = false;
        selectionRect.setBottomRight(event->pos());

        // 捕获选择区域的内容
        QPixmap selectedArea = captureArea(selectionRect);
        emit screenshotTaken(selectedArea);

        close(); // 关闭截图窗口
    }
}

QPixmap ScreenshotTool::captureFullScreen() {
    QScreen* screen = QGuiApplication::primaryScreen();
    if (!screen) {
        qDebug() << "No screen found for full-screen capture!";
        return QPixmap();
    }
    return screen->grabWindow(0);
}

QPixmap ScreenshotTool::captureArea(const QRect& area) {
    QScreen* screen = QGuiApplication::primaryScreen();
    if (!screen) {
        qDebug() << "No screen found for area capture!";
        return QPixmap();
    }
    QPixmap fullScreen = screen->grabWindow(0);
    return fullScreen.copy(area);
}
