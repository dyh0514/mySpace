#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // qt4 方式
    // connect(ui->showchildpushbuttom,SIGNAL(clicked(bool)),this,SLOT(showChildDialog()));
    // qt4 风格的slot和signal 只是宏转换，字符串定义不能检测编译错误
    // connect(ui->showchildpushbuttom,SIGNAL(chicked(bool)),this,SLOT(showChildDialog(1,2,3)));

    //qt5 方式推荐
    connect(ui->showchildpushbuttom, &QPushButton::clicked, this, &MainWindow::showChildDialog);
    _child_dialog = new childDialog(this);
    connect(_child_dialog,&childDialog::showMainSig,this,&MainWindow::showMainDialog);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete _child_dialog;
}

void MainWindow:: showChildDialog()
{
    // auto childDialog1 = new QDialog(this);
    // childDialog1->show();
    _child_dialog->show();
    //ui->hide();
    this->hide();

}
void MainWindow::showMainDialog()
{
    this->show();
    _child_dialog->hide();
}
