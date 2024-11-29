#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimerEvent>
#include <QTimer>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void timerEvent(QTimerEvent *event);
    void slots_update_led();
private:
    Ui::Widget *ui;
    int id1;
    int id2;
    int id3;
};
#endif // WIDGET_H
