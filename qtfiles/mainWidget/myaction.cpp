#include "myaction.h"
#include <QSplitter>
#include <QLabel>
#include <QSplitter>
MyAction::MyAction(QObject * parent):QWidgetAction(parent){
    //创建行编辑器
    lineEdit = new QLineEdit();
    //连接信号和槽，触发回车信号和槽函数关联
    connect(lineEdit,&QLineEdit::returnPressed,this,&MyAction::sentText);
}

void MyAction::sentText()
{
    emit getText(lineEdit->text());
    lineEdit->clear();
}
QWidget*  MyAction:: createWidget(QWidget * parent){
    if(!(parent->inherits("QMenu"))&&!(parent->inherits("QToolBar")))
    {
        return 0;
    }
    QSplitter * splitter = new QSplitter(parent);
    QLabel * label = new QLabel;
    label->setText("插入文本");
    splitter ->addWidget(label);
    splitter -> addWidget(lineEdit);
    return splitter;

}
