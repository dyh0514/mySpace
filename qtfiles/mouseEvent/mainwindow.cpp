#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCursor>
#include <QMouseEvent>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);//设置鼠标后不能回退

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: mousePressEvent(QMouseEvent * event){
    if(event->button()== Qt::LeftButton){
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);//这样设置，可以回退鼠标功能
        offset = event->globalPos()-pos();
    }
    else if(event->button()== Qt::RightButton){
        QCursor cursor(QPixmap(":/mouse.png"));
        QApplication::setOverrideCursor(cursor);
    }
}
void MainWindow::  mouseReleaseEvent(QMouseEvent * event){
    QApplication::restoreOverrideCursor();//松开返回原图标，拳头抓取变为张手松开
}
void MainWindow:: mouseDoubleClickEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        if(windowState() == Qt:: WindowFullScreen){
            setWindowState(Qt::WindowNoState);
        }
        else {
            setWindowState(Qt::WindowFullScreen);
        }
    }
}
void MainWindow::  mouseMoveEvent(QMouseEvent *event){
    //在鼠标移动中，保证窗口也移动
    if(event->buttons() & Qt::LeftButton){//取出所有事件按位与左键点击
        QPoint windows = event->globalPos()-offset;
        this->move(windows);
    }
}

void MainWindow:: wheelEvent(QWheelEvent *event){
    if(event->Delta()>0){
        ui->textEdit->zoomIn();
    }else{
        ui->textEdit->zoomOut();
    }
}
