#ifndef HELLODIALOG1_H
#define HELLODIALOG1_H
#include"ui_hellodialog.h"
#include <QDialog>

class hellodialog1 : public QDialog
{
public:

    hellodialog1();
    ~hellodialog1();
private:
    Ui::Dialog * _ui;
};

#endif // HELLODIALOG1_H
