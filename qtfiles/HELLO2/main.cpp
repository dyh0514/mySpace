#include<QApplication>
#include<QDialog>
#include <QLabel>
#include "hellodialog1.h"
#include "hellodialog2.h"
int main(int argc,char * argv[])
{
    QApplication a(argc,argv);
    //QDialog w;
    //w.resize(400,300);
    //QLabel label(&w);
    //label.move(120,120);
    //label.setText("helloworld;");
    // Ui::Dialog ui;
    // ui.setupUi(&w);
    // w.show();
    //hellodialog1 dialog;
    //dialog.show();
    helloDialog2 dialog2;
    dialog2.show();
    return a.exec();
}
