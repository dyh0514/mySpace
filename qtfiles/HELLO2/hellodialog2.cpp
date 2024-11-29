#include "hellodialog2.h"
#include "ui_hellodialog2.h"

helloDialog2::helloDialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::helloDialog2)
{
    ui->setupUi(this);
}

helloDialog2::~helloDialog2()
{
    delete ui;
}
