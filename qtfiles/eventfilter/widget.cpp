#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    lineEdit = new MyEdit (this);
    lineEdit ->move(100,100);
    lineEdit->installEventFilter(this);
    ui->spinBox ->installEventFilter(this);
    ui->textEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget:: keyPressEvent(QKeyEvent *){
    qDebug()<<" MY Widget key press event RUNNING";
}

bool  Widget::eventFilter(QObject*watched,QEvent * event){
    if(watched ==lineEdit){
        if(event->type() == QEvent::KeyPress){
            qDebug()<<"widget EventFilter Catch LineEdit";
            return false;
        }
    }
    if(watched ==ui->textEdit){
        if(event->type() == QEvent::Wheel){
            qDebug()<<"widget EventFilter Catch TextEdit";
            if(QWheelEvent * wheelEvent=static_cast<QWheelEvent*>(event)){
                ui->textEdit->zoomIn();
            }
            else{
                ui->textEdit ->zoomOut();
            }
            return true;
        }
        return false;
    }
    if(watched ==lineEdit){
        if(event->type() == QEvent::KeyPress){
            qDebug()<<"widget EventFilter Catch LineEdit";
            return false;
        }
    }
    return QWidget::eventFilter(watched,event);
}
