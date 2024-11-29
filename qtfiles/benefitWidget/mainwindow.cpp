#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QListWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//listWidget-----------------------------------------------------------------
    auto * listWidget = new QListWidget (this);
    //listwidgetitem 设置
    auto * listWidgetItem = new QListWidgetItem;
    listWidgetItem -> setText("listItem");
    QPixmap pixmap (50,50);
    pixmap.fill(Qt::blue);
    listWidgetItem ->setIcon(pixmap);
    listWidgetItem ->setToolTip("this is list item");
    listWidget->insertItem(1,listWidgetItem);
    //listwidgetitem2 设置
    auto * listWidgetItem2 = new QListWidgetItem;
    listWidgetItem2 -> setText("listItem2");
    QPixmap pixmap2 (50,50);
    pixmap2.fill(Qt::blue);
    listWidgetItem2 ->setIcon(pixmap2);
    listWidgetItem2 ->setToolTip("this is list item");
    listWidget->insertItem(2,listWidgetItem2);

    //sort排序
    listWidget ->setSortingEnabled(true);
    listWidget->sortItems(Qt::DescendingOrder);
    listWidget->show();
    this->setCentralWidget(listWidget);


    listWidget ->setSelectionMode(QAbstractItemView::SingleSelection);
    listWidget->setDragEnabled(true);
    listWidget->viewport()->setAcceptDrops(true);
    listWidget->setDropIndicatorShown(true);
    listWidget->setDragDropMode(QAbstractItemView::InternalMove);
/*
//treeWidget----------------------------------------------------
    treeWidget = new QTreeWidget(this);
    //QTreeWidgetItem *  treeWidgetItem  = new QTreeWidgetItem;
    //设置表头
    QStringList headers;
    headers << "name" <<"years";
    treeWidget ->setHeaderLabels(headers);

    //设置item
    QTreeWidgetItem * grade1 = new QTreeWidgetItem(treeWidget);
    grade1->setText(0,"grade1");

    //设置item的子节点
    QTreeWidgetItem * student = new QTreeWidgetItem(grade1);
    student->setText(0,"tom");
    student->setText(1,"1996") ;

    QTreeWidgetItem * student2 = new QTreeWidgetItem(grade1,student);//后一个表明student是student的兄弟节点
    student2->setText(0,"tom1");
    student2->setText(1,"1996") ;

    QTreeWidgetItem * student3 = new QTreeWidgetItem(grade1,student2);
    student3->setText(0,"tom2");
    student3->setText(1,"1996") ;


    QTreeWidgetItem * grade2 = new QTreeWidgetItem(treeWidget,grade1);
    grade2->setText(0,"grade2");


    //删除节点
    auto * parent_student3 = student3->parent();//找到要删除节点的父节点
    auto index_student3 = parent_student3->indexOfChild(student3);//函数返回子节点的索引；
    delete parent_student3->takeChild(index_student3);//找到父节点，父节点传入student3，找到student3的索引用来删除

    //删除无子节点的item
    auto * parent_grade2 = grade2;
    assert(parent_grade2 == nullptr);
    auto  index_grade2 = treeWidget->indexOfTopLevelItem(grade2);//找到grade2的顶级节点
    delete treeWidget->takeTopLevelItem(index_grade2);//找到父节点，父节点找到对应索引的最上级item，用来删除

    treeWidget->resize(500,500);
    treeWidget->show();

//tableWidget-----------------------------------------------
    tableWidget = new QTableWidget (3,2);
    QTableWidgetItem * tableWidgetItem = new QTableWidgetItem ("QT");
    tableWidget-> setItem(1,1,tableWidgetItem);
    QTableWidgetItem * headerV = new QTableWidgetItem("first");//竖向表头
    tableWidget->setVerticalHeaderItem(0,headerV);
    QTableWidgetItem * headerH = new QTableWidgetItem("ID");//横向表头
    tableWidget->setHorizontalHeaderItem(0,headerH);
    tableWidget->show();*/
}

MainWindow::~MainWindow()
{
    delete ui;
   /* delete treeWidget;
    delete tableWidget;*/
}
