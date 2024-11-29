#include "myedit.h"
#include <QDebug>
MyEdit:: MyEdit(QWidget * parent) : QLineEdit(parent){

}

void MyEdit:: keyPressEvent(QKeyEvent * event){
    qDebug()<<"MyEdit PressEvent running!";
    QLineEdit::keyPressEvent(event);
    event->ignore();
}
bool MyEdit::event(QEvent * pevent){
    if(pevent->type() == QEvent::KeyPress){
        qDebug()<<"my edit event  running!";
        //return false;
    }//事件从event触发，再进入子事件 keyPressEvent
//    return true  就处理好结束了
//    return false 就返回到父节点接收
//    不返回        就从 event 到 QLineEdit::keyPressEvent 到 父节点widget
    return QLineEdit::event(pevent);
}
