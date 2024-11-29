#include "childdialog.h"
#include "ui_childdialog.h"

childDialog::childDialog(QWidget *parent)
    : QDialog(parent),_parent(parent),
        ui(new Ui::childDialog)
{
    ui->setupUi(this);
    connect(ui->showfatherpushButton,&QPushButton::clicked,this,&childDialog::showfatherDialog);
}

childDialog::~childDialog()
{
    delete ui;
}
void childDialog::showfatherDialog(){
    this->hide();
    //_parent->show();
    emit showMainSig();
}
