#ifndef MYEDIT_H
#define MYEDIT_H
#include <QLineEdit>
#include <QEvent>
#include <QKeyEvent>
class MyEdit:public QLineEdit
{
        Q_OBJECT
public:

    explicit MyEdit(QWidget * parent = nullptr);
    //显式调用有参构造

protected:
    void keyPressEvent(QKeyEvent *);
    bool event(QEvent * pevent);
};

#endif // MYEDIT_H
