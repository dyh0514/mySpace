#include "maindialog.h"
#include "ui_maindialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainDialog)
{
    ui->setupUi(this);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_enterchildBTN_clicked()
{
    this->close();
    childDialog child;
    if(child.exec()==QDialog::Accepted)
    {
        this->show();
    }else{
        return;
    }

}


void MainDialog::on_exitBTN_clicked()
{
    this->close();
}

