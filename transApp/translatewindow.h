#ifndef TRANSLATEWINDOW_H
#define TRANSLATEWINDOW_H
#include <QLabel>

class TranslateWindow:public QWidget{
    Q_OBJECT
public:
    TranslateWindow(QWidget *parent = nullptr);
    void displayTranslation(const QString &translation);

private:
    QLabel *translationResult;
};

#endif // TRANSLATEWINDOW_H
