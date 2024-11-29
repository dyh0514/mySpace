#include "mainwindow.h"
#include "myaction.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QActionGroup>
#include <QKeySequence>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenu * editmenu = ui->menubar->addMenu(tr("编辑(&E)"));
    editmenu ->addSeparator();
    QAction* action_open = editmenu ->addAction(QIcon(":/res/edit.ico"),tr("打开文件(&O)"));
    action_open->setShortcut(QKeySequence("Ctrl+O"));
    connect(action_open,&QAction::triggered,this,&MainWindow::on_actionedit_triggered);

    QActionGroup * actgrp = new QActionGroup (this);
    QAction *action_l=actgrp->addAction(tr("左对齐"));
    action_l->setCheckable(true);

    QAction *action_r=actgrp->addAction(tr("右对齐"));
    action_r->setCheckable(true);

    QAction *action_m=actgrp->addAction(tr("居中"));
    action_m->setCheckable(true);
    editmenu -> addSeparator();
    editmenu->addAction(action_l);
    editmenu->addAction(action_r);
    editmenu->addAction(action_m);

    MyAction * action =new MyAction(this);
    editmenu->addAction(action);
    connect(action,&MyAction::getText,this,&MainWindow::slot_set_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionnew_2_triggered()
{
    ui->dockWidget->show();
}


void MainWindow::on_actionnew_triggered()
{
    QTextEdit* textedit = new QTextEdit (this);
    auto childWindow = ui->mdiArea->addSubWindow(textedit);
    childWindow->setWindowTitle("文件编辑子窗口");
    childWindow ->show();

}
void MainWindow::on_actionedit_triggered(){
    qDebug()<<"编辑文件";
}

void MainWindow:: slot_set_text(const QString&string){
    ui->textEdit->setText(string);
}
