#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "settingswindow.h"

class QLineEdit;
class QPushButton;
class QLabel;

class LoginWindow : public QWidget {
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void onLoginButtonClicked();
    void onRegisterButtonClicked();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *statusLabel;

    SettingsWindow *settingsWindow;

    bool authenticateUser(const QString &username, const QString &password);
    bool registerUser(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
};

#endif // LOGINWINDOW_H
