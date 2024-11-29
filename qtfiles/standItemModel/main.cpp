#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QPixmap>
#include <QTreeView>
#include <QListView>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QStandardItemModel model;
    auto * parentItem = model.invisibleRootItem();//所有节点的不可见根节点
    QStandardItem * item0 =new QStandardItem();
    item0->setText("item0");
    QPixmap pixmap0(50,50);
    pixmap0.fill(Qt::red);
    item0->setIcon(pixmap0);
    item0->setToolTip("indexA");
    parentItem ->appendRow(item0);

    parentItem = item0;
    QStandardItem * item1 =new QStandardItem();
    item1->setText("item1");
    QPixmap pixmap1(50,50);
    pixmap1.fill(Qt::green);
    item1->setIcon(pixmap1);
    item1->setToolTip("indexB");
    parentItem ->appendRow(item1);

//方式一
    // QStandardItem * item2 =new QStandardItem();
    // item2->setText("item2");
    // QPixmap pixmap2(50,50);
    // pixmap2.fill(Qt::blue);
    // item2->setIcon(pixmap2);
    // item2->setToolTip("indexC");
    // parentItem ->appendRow(item2);
//方式二
    QStandardItem * item2 = new QStandardItem();
    item2->setData("item2",Qt::EditRole);             //通过setData来设置属性
    item2->setData("indexC",Qt::ToolTipRole);
    QPixmap pixmap2(50,50);
    pixmap2.fill(Qt::blue);
    item2->setData(QIcon(pixmap2),Qt::DecorationRole);
    parentItem->appendRow(item2);


    //取出根节点下的第0行第0列的item模型索引
    QModelIndex indexA= model.index(0,0,QModelIndex());//QModelIndex()是根节点对应的索引
    qDebug()<<"model indexA row count is:"<<model.rowCount(indexA);

    //获取indexA下的0行0列
    QModelIndex indexB =model.index(0,0,indexA);
    qDebug()<<"indexB text is:"<< model.data(indexB,Qt::EditRole).toString();//找那个项，就找那个index，和相应的属性
    qDebug()<<"indexB icon is:"<< model.data(indexB,Qt::DecorationRole);
    qDebug()<<"indexB tool tip is:"<< model.data(indexB,Qt::ToolTipRole).toString();

    QModelIndex indexC =model.index(1,0,indexA);
    qDebug()<<"indexC text is:"<< model.data(indexC,Qt::EditRole).toString();//找那个项，就找那个index，和相应的属性
    qDebug()<<"indexC icon is:"<< model.data(indexC,Qt::DecorationRole);
    qDebug()<<"indexC tool tip is:"<< model.data(indexC,Qt::ToolTipRole).toString();

    QTreeView view;
    view.setModel(&model);
    view.show();



    return a.exec();
}
