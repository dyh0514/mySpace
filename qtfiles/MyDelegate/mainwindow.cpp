#include "mainwindow.h"
#include "spinboxdelegate.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QSpinBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto * model = new QStandardItemModel(7,4,this);
    for(int row=0;row<model->rowCount();row++){
        for(int column=0;column<model->columnCount();column++)
        {
            QStandardItem * item = new QStandardItem(QString("%1").arg(row*4+column));
            model->setItem(row,column,item);
        }
    }
    QTableView * tableView = new QTableView;
    tableView->setModel(model);
    tableView->resize(500,500);
    setCentralWidget(tableView);
    tableView->show();
    //第二套模型
    auto * model2 = new QStandardItemModel(7,4,this);
    for(int row=0;row<model->rowCount();row++){
        for(int column=0;column<model->columnCount();column++)
        {
            QStandardItem * item = new QStandardItem(QString("%1").arg(row*4+column));
            model2->setItem(row,column,item);
        }
    }

    auto * delegate = new SpinBoxDelegate(this);

    QTableView * tableView2 = new QTableView();
    tableView2->setModel(model2);
    tableView2->setItemDelegate(delegate);
    tableView2->resize(500,500);
    tableView2->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tableView2;
}
