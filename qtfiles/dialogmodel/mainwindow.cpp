#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QDialog * w = new QDialog(this);
    // w->setModal(true);
    // w->show();
    // QDialog w;
    // w.exec();
    auto s = new QDialog(this);
    s->setWindowFlag(Qt::WindowStaysOnTopHint);
    s->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
