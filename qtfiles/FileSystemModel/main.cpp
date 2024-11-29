#include "mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    auto * splitter = new QSplitter;
    auto * model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());//设置文件系统模型目录

    QTreeView * treeView = new QTreeView(splitter);
    treeView -> setModel( model);
    treeView ->setRootIndex(model->index(QDir::currentPath())); //将目录设置为当前的目录，不设置的话就是根目录

    QListView * listView = new QListView(splitter);
    listView->setModel(model);
    listView ->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("two views onto same system");
    splitter->resize(1000,800);
    splitter->show();


    return a.exec();
}
