#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include<QPushButton>
#include <QComboBox>
#include <QListWidget>
#include <QFontComboBox>
#include "subtitlewindow.h"
#include "translatewindow.h"
#include "settingswindow.h"
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
private :
    void setupUI();
    void addTranslateWindow();
    void addSubtitleWindow();
    void changeLanguage(int index);
    void saveTranslation(const QString &translatedText);
    void openSettings();

private:
    Ui::MainWindow *ui;

    QPushButton *translateButton;
    QPushButton *subtitleButton;
    QComboBox *languageSelector;
    QListWidget *historyList;
    SettingsWindow *settingsWindow;
};
#endif // MAINWINDOW_H
