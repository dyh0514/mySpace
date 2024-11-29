#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::ClickFocus);//点一下聚焦窗口
    //id1=startTimer(1000);
    //id2=startTimer(1500);
    //id3=startTimer(2000);
    QTimer * timer = new QTimer(this);
    connect( timer,&QTimer::timeout,this,&Widget::slots_update_led);
    timer->start(1000);
}
Widget::~Widget()
{
    delete ui;

}

void Widget:: keyPressEvent(QKeyEvent * event){
    if(event->modifiers() == Qt::ControlModifier){
        if(event->key() == Qt::Key_M && windowState() != Qt::WindowFullScreen){
            setWindowState(Qt::WindowFullScreen);
            return ;
        }
        return;
    }
    if(event->key() ==Qt::Key_Escape && windowState()==Qt::WindowFullScreen){
        setWindowState(Qt::WindowNoState);
    }
    bool b_upflag =false;
    bool b_downflag =false;
    bool b_leftflag =false;
    bool b_rightflag =false;
    if(event->key() == Qt::Key_Up){
        if(event->isAutoRepeat()){//一直按住向上键；
            auto curpos = ui->pushButton->pos();
            curpos.setY(curpos.y()-5);
            ui->pushButton->move(curpos);
             return;
        }else{
            b_upflag =true;
        }
    }
    if(event->key() == Qt::Key_Down){
        if(event->isAutoRepeat()){//一直按住向下键；
            auto curpos = ui->pushButton->pos();
            curpos.setY(curpos.y()+5);
            ui->pushButton->move(curpos);
             return;
        }else{
            b_downflag =true;
        }
    }
    if(event->key() == Qt::Key_Left){
        if(event->isAutoRepeat()){//一直按住向左键；
            auto curpos = ui->pushButton->pos();
            curpos.setX(curpos.x()-5);
            ui->pushButton->move(curpos);
            return;
        }else{
            b_leftflag =true;
        }
    }
    if(event->key() == Qt::Key_Right){
        if(event->isAutoRepeat()){//一直按住向右键；
            auto curpos = ui->pushButton->pos();
            curpos.setX(curpos.x()+5);
            ui->pushButton->move(curpos);
             return;
        }else{
            b_rightflag =true;
        }
    }
    auto curpos = ui->pushButton->pos();
    if(b_upflag){
        curpos.setY(curpos.y()-5);
    }

    if(b_downflag){
        curpos.setY(curpos.y()+5);
    }

    if(b_leftflag){
        curpos.setX(curpos.x()-5);
    }

    if(b_rightflag){
        curpos.setX(curpos.x()+5);
    }
    ui->pushButton->move(curpos);
}


void Widget:: timerEvent(QTimerEvent *event){
    if(event->timerId() == id1 ){
        qDebug()<< "ID1 traggered";
    }
    if(event->timerId() == id2 ){
        qDebug()<< "ID2 traggered";
    }
    if(event->timerId() == id3 ){
        qDebug()<< "ID3 traggered";
    }

}

void Widget::slots_update_led(){
    QTime time = QTime::currentTime();
    QString  text =time.toString("hh:mm:ss");
    //qDebug()<<"current time is"<<text;
    if(time.second()%2){
        text[5]=' ';
        text[2]=' ';
    }
    ui->lcdNumber->setDigitCount(text.length());
    ui->lcdNumber->display(text);
}
