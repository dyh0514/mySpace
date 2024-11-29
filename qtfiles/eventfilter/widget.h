#ifndef WIDGET_H
#define WIDGET_H
#include "myedit.h"
#include <QSpinBox>
#include <QTextEdit>
#include <QWidget>


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
    void keyPressEvent(QKeyEvent *);
    bool eventFilter(QObject*watched,QEvent * event);

private:
    Ui::Widget *ui;
    MyEdit * lineEdit;
};
#endif // WIDGET_H
