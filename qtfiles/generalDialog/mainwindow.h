#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_colorBTN_clicked();

    void on_textBTN_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_updateProgressDialog();

    void on_concelProgressDialog();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer * timer;
    QProgressDialog * progressdialog;
    int counter;

};
#endif // MAINWINDOW_H
