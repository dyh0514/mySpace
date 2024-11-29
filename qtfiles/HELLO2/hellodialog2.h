#ifndef HELLODIALOG2_H
#define HELLODIALOG2_H

#include <QDialog>

namespace Ui {
class helloDialog2;
}

class helloDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit helloDialog2(QWidget *parent = nullptr);
    ~helloDialog2();

private:
    Ui::helloDialog2 *ui;
};

#endif // HELLODIALOG2_H
