#ifndef SCREENSHOTTOOL_H
#define SCREENSHOTTOOL_H

#include <QWidget>
#include <QPixmap>
#include <QRect>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QScreen>
#include <QGuiApplication>
#include <QPainter>

class ScreenshotTool : public QWidget
{
    Q_OBJECT

public:
    explicit ScreenshotTool(QWidget* parent = nullptr);
    ~ScreenshotTool();

    // 启动截图区域选择
    void startSelection();

    // 捕获全屏截图
    QPixmap captureFullScreen();

    // 捕获特定区域截图
    QPixmap captureArea(const QRect& area);

signals:
    // 截图完成后发出信号，传递截图结果
    void screenshotTaken(const QPixmap& screenshot);

protected:
    // 窗口绘制事件
    void paintEvent(QPaintEvent* event) override;

    // 鼠标按下事件
    void mousePressEvent(QMouseEvent* event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QMouseEvent* event) override;

    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    void initUI(); // 初始化界面
    QRect selectionRect; // 选择区域
    QPoint selectionStart; // 选择开始位置
    QPoint selectionEnd; // 选择结束位置
    bool isSelecting = false;          // 是否正在选择区域              // 选择的区域
    QPixmap fullScreenPixmap;          // 全屏截图内容
};

#endif // SCREENSHOTTOOL_H
