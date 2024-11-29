#include "childdialog.h"
#include "ui_childdialog.h"

childDialog::childDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::childDialog)
{
    ui->setupUi(this);
}

childDialog::~childDialog()
{
    delete ui;
}

void childDialog::on_returnBTN_clicked()
{
    accept();
}

