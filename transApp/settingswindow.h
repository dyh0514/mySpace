#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class SettingsWindow : public QWidget {
    Q_OBJECT
public:
    explicit SettingsWindow(QWidget *parent = nullptr);
private:
    QComboBox *languageComboBox;
};

#endif // SETTINGSWINDOW_H
