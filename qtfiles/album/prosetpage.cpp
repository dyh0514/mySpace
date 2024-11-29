#include "prosetpage.h"
#include "ui_prosetpage.h"
#include <QLineEdit>
#include <QDir>
ProSetPage::ProSetPage(QWidget *parent)
    : QWizardPage(parent)
    , ui(new Ui::ProSetPage)
{
    ui->setupUi(this);
    registerField("proPath",ui->lineEdit_2);
    registerField("proName*",ui->lineEdit);
    connect(ui->lineEdit,&QLineEdit::textEdited,this,&ProSetPage::completeChanged);
    connect(ui->lineEdit_2,&QLineEdit::textEdited,this,&ProSetPage::completeChanged);
    QString curPath = QDir::currentPath();
    ui->lineEdit_2->setText(curPath);
    ui->lineEdit_2->setCursorPosition(ui->lineEdit_2->text().size());
    ui->lineEdit_2->setClearButtonEnabled(true);
    ui->lineEdit->setClearButtonEnabled(true);
}

ProSetPage::~ProSetPage()
{
    delete ui;
}

bool ProSetPage::isComplete() const
{
    if(ui->lineEdit->text()==""||ui->lineEdit_2->text()==""){
        return false;
    }
    QDir dir(ui->lineEdit_2->text());
    if(!dir.exists()){
        ui->tips->setText("project path is no exists");
        return false;
    }

    //判断路径是否存在
    QString absFilePath = dir.absoluteFilePath(ui->lineEdit->text());
    QDir dist_dir(absFilePath);
    if(dist_dir.exists()){
        ui->tips->setText("project path has exists,change path name!");
        return false;
    }
    ui->tips->setText("");
    return QWizardPage::isComplete();
}
