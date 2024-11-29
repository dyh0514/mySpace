#include "hellodialog1.h"

hellodialog1::hellodialog1():_ui(new Ui::Dialog())
{
    _ui->setupUi(this);
}
hellodialog1::~hellodialog1()
{
    delete _ui;
}
