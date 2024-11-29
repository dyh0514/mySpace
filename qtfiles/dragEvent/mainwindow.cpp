#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMimeData>
#include<QDragEnterEvent>
#include <QDebug>
#include <QMimeData>
#include<QUrl>
#include <QString>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    ui->textEdit->setAcceptDrops(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dragEnterEvent(QDragEnterEvent * event)
{
    if(event->mimeData()->hasUrls()){
        //event->mimeData()->urls()[0];
        //qDebug()<<event->mimeData()->urls()[0]<<"\n";
        event->acceptProposedAction();
    }else{
        event->ignore();
    }
}
 void MainWindow::dropEvent(QDropEvent * event)
{
     const QMimeData * mimeData = event->mimeData();
    if(mimeData->hasUrls()){
        QList<QUrl> urlList = mimeData->urls();
        QString fileName = urlList[0].toLocalFile();
        if(!fileName.isEmpty()){
            QFile file (fileName);
            if(!file.open(QIODevice::ReadOnly)){
                return;
            }

            QTextStream in(&file);
            ui->textEdit->setText(in.readAll());
        }
     }else{
        event->ignore();
    }
}
