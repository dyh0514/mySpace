#ifndef MAINDIALOG_H
#define MAINDIALOG_H
#include <QMainWindow>
#include "childdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainDialog;
}
QT_END_NAMESPACE

class MainDialog : public QMainWindow
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

private slots:
    void on_enterchildBTN_clicked();

    void on_exitBTN_clicked();

private:
    Ui::MainDialog *ui;
};
#endif // MAINDIALOG_H
