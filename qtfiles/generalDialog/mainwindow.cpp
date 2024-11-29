#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QFileDialog>
#include <QInputDialog>
#include <QStringList>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QWizard>
#include <QButtonGroup>
#include <QRadioButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_colorBTN_clicked()
{
    QColorDialog colorDLG(Qt::green,this) ;
    colorDLG.setOption(QColorDialog::ShowAlphaChannel);
    colorDLG.exec();
    QColor color = colorDLG.currentColor();
    qDebug()<<color;
}


void MainWindow::on_textBTN_clicked()
{
    QString path = QDir::currentPath();
    QString title = tr("文本对话框");
    QString filter = tr("文本文件(*.txt);;图片文件(*.png *.JPG *.gif);;所以文件(*.*)");
    QString fileName = QFileDialog::getOpenFileName(this,title,path,filter);
    qDebug()<<fileName;
}


void MainWindow::on_pushButton_3_clicked()
{
    bool ok = false;
    auto intdate = QInputDialog::getInt(this,tr("整形输入对话框"),tr("请输入整形"),200,100,400,10,&ok);
    if(ok)
        qDebug()<<ok;
    else
        qDebug()<<ok;
}


void MainWindow::on_pushButton_4_clicked()
{
    bool ok = false;
    auto doubledate = QInputDialog::getDouble(this ,tr("浮点输入对话框"),tr("请输入浮点数"),2.3,1.0,3.0,3,&ok);
    qDebug()<<ok;
}


void MainWindow::on_pushButton_5_clicked()
{
    QStringList items;
    items<<"条目1"<<"条目2"<<"条目3"<<"条目4";
    bool ok = false;
    auto item =  QInputDialog::getItem(this,"条目对话框","输入或选择条目框",items,0,true,&ok);
    qDebug()<<ok<<"   "<<item ;
}


void MainWindow::on_pushButton_6_clicked()
{
    auto res = QMessageBox::question(this,"提问对话框","你成年了吗",QMessageBox::Yes,QMessageBox::No);
    if (res != QMessageBox::Yes)
    {
        qDebug()<<res;
        res = QMessageBox::information(this,"通知对话框","你可以去网吧",QMessageBox::Yes,QMessageBox::No);
        qDebug()<<res;
        if (res ==QMessageBox::Yes)
            {
            res =QMessageBox::warning(this,"警告对话框","不，你没成年",QMessageBox::Ok);
            if(res==QMessageBox::Ok)
                QMessageBox::critical(this,"关键提示对话框","去写数学吧",QMessageBox::Ok);
            }
    }
}

void MainWindow::on_pushButton_clicked()
{
    progressdialog = new QProgressDialog (tr("正在复制"),tr("取消复制"),0,5000,this);
    progressdialog ->setWindowTitle("文件复制对话框");
    progressdialog -> setWindowModality(Qt::ApplicationModal);
    timer = new QTimer (this);
    connect(timer,&QTimer::timeout,this,&MainWindow::on_updateProgressDialog);
    connect(progressdialog,&QProgressDialog::canceled,this,&MainWindow::on_concelProgressDialog);
    timer->start(2);

}
void MainWindow::on_updateProgressDialog(){
    counter++;
    if(counter>5000){
        timer->stop();
        delete timer;
        timer = nullptr;
        delete progressdialog ;
        progressdialog = nullptr;
        counter = 0;
        return ;
    }
    progressdialog ->setValue(counter);
}
void MainWindow::on_concelProgressDialog(){
    timer ->stop();
    delete timer;
    timer = nullptr;
    counter = 0;
    delete progressdialog;
    progressdialog = nullptr;
    return ;
}


void MainWindow::on_pushButton_2_clicked()
{
    auto * wizard = new QWizard (this);
    wizard ->setWindowTitle("向导对话框");
    auto wizardPage0 = new QWizardPage;
    wizardPage0->setTitle("引导程序");
    auto * label = new QLabel;
    label->setText("该程序帮你完成软件设置");
    auto layout0 = new QVBoxLayout();
    layout0 ->addWidget(label);
    wizardPage0->setLayout(layout0);
    wizard->addPage(wizardPage0);

    auto wizardpage1 = new QWizardPage;
    auto layout1 = new QVBoxLayout;
    auto btngroup = new QButtonGroup;

    auto btn1 = new QRadioButton();
    btn1->setText("vs2019");
    btngroup ->addButton(btn1);


    auto btn2 = new QRadioButton();
    btn2->setText("vs2020");
    btngroup ->addButton(btn2);

    auto btn3 = new QRadioButton();
    btn3->setText("vs2021");
    btngroup ->addButton(btn3);

    for(int i=0;i<btngroup->buttons().size();i++){
        layout1->addWidget(btngroup->buttons()[i]);
    }

    wizardpage1->setLayout(layout1);
    wizard->addPage(wizardpage1);

    wizard -> show();
    wizard -> exec();

}

