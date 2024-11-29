#include "maindialog.h"
#include "childdialog.h"
#include <QApplication>
#include <QDialog>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    childDialog childdialog;
    auto res =childdialog.exec();
    if(res==QDialog::Accepted){
        w.show();
        a.exec();
    }else{
        qDebug()<<"reject,exit";
        return 0;
    }

}
