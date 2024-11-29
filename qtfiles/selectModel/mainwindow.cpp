#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QDebug>
#include <QItemSelection>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel * model = new QStandardItemModel(7,2,this);
    for(int row = 0; row < 7 ; row++){
        for(int column = 0; column < 4 ;column++){
            QStandardItem * item = new QStandardItem(QString("%1").arg(row*4+column));
            model->setItem(row,column,item);

        }
    }
    _table_view = new QTableView;
    _table_view->setModel(model);
    setCentralWidget(_table_view);
    this->resize(500,500);

    //选择模型
    QItemSelectionModel * selection_model= _table_view->selectionModel();
    //定义左上角和左下角的索引
    QModelIndex lefttop;
    QModelIndex rightbottom;
    lefttop=model->index(1,1,QModelIndex());
    rightbottom=model->index(5,3,QModelIndex());

    //选择区域
    QItemSelection selection (lefttop,rightbottom);
    selection_model->select(selection,QItemSelectionModel::Select);


    QTableView *tableView2 = new QTableView;
    tableView2->setModel(model);
    tableView2->resize(500,400);
    tableView2->setSelectionModel(selection_model);
    tableView2->show();

    ui->mainToolBar->addAction(tr("当前项目"),this,&MainWindow::getCurrentItem);
    ui->mainToolBar->addAction(tr("切换选中"),this,&MainWindow::toggleSelection);

    //选择模型的选择条目更改后触发updateSelectionModel
    connect(selection_model,&QItemSelectionModel::selectionChanged,this,&MainWindow::updateSelection);
    //选择模型更改后，当前项目也会改变，会触发changeCurrent
    connect(selection_model,&QItemSelectionModel::currentChanged,this,&MainWindow::changeCurrent);
};

MainWindow::~MainWindow()
{
    delete ui;
    delete _table_view;
}

void MainWindow:: getCurrentItem(){
    auto currentdata =_table_view->selectionModel()->currentIndex().data().toString();
    //          选择模型           选到索引        选择项  转成string
    qDebug()<<"current text"<<currentdata;
}

//切换
void MainWindow::toggleSelection(){
    //找到根节点下第一行第一列的索引;
    QModelIndex topleft = _table_view->model()->index(0,0,QModelIndex());
    //获得行列号
    auto max_row = _table_view->model()->rowCount(QModelIndex());
    auto max_column = _table_view->model()->columnCount(QModelIndex());

    //根据行号和列号获取右下角item的索引
    QModelIndex bottomRight = _table_view->model()->index(max_row-1,max_column-1,QModelIndex());

    //设置选择区域
    QItemSelection curSelection(topleft,bottomRight);
    _table_view->selectionModel()->select(curSelection,QItemSelectionModel::Toggle);
}
void MainWindow::updateSelection(const QItemSelection &selected, const QItemSelection &deselected){
    QModelIndex index;
    //第一种方式
    QModelIndexList indexList = selected.indexes();
    for(int i=0;i<indexList.size();i++){
        QString text = QString("(%1,%2)").arg(indexList[i].row()).arg(indexList[i].column());
        _table_view->model()->setData(indexList[i],text);
    }
    //第二种方式
     QModelIndexList list = deselected.indexes();
     foreach (index, list) {
         _table_view->model()->setData(index,"");
     }
}
void MainWindow::changeCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug()<<tr("move(%1,%2) to (%3,%4)").arg(previous.row()).arg(previous.column()).arg(current.row()).arg(current.column());
}
