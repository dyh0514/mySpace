#include "loginwindow.h"
#include "mainwindow.h" // 引入 MainWindow
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent), settingsWindow(nullptr) {
    setWindowTitle("用户登录");
    setFixedSize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *usernameLabel = new QLabel("用户名:", this);
    usernameEdit = new QLineEdit(this);

    QLabel *passwordLabel = new QLabel("密码:", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("登录", this);
    registerButton = new QPushButton("注册", this);
    statusLabel = new QLabel("", this);

    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);
    layout->addWidget(registerButton);
    layout->addWidget(statusLabel);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterButtonClicked);
}

void LoginWindow::onLoginButtonClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        statusLabel->setText("请输入用户名和密码！");
        return;
    }

    if (authenticateUser(username, password)) {
        QMessageBox::information(this, "登录成功", "欢迎，" + username + "！");
        this->hide(); // 隐藏登录窗口

        // 登录成功后打开 MainWindow
        MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    } else {
        statusLabel->setText("登录失败，用户名或密码错误！");
    }
}

void LoginWindow::onRegisterButtonClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        statusLabel->setText("请输入用户名和密码！");
        return;
    }

    if (registerUser(username, password)) {
        QMessageBox::information(this, "注册成功", "用户 " + username + " 已注册成功！");
    } else {
        statusLabel->setText("注册失败，用户名可能已存在！");
    }
}

bool LoginWindow::authenticateUser(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT password_hash FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec() || !query.next()) {
        qDebug() << "Login failed:" << query.lastError().text();
        return false;
    }

    QString storedHash = query.value(0).toString();
    return hashPassword(password) == storedHash;
}

bool LoginWindow::registerUser(const QString &username, const QString &password) {
    QString hashedPassword = hashPassword(password);

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password_hash)");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", hashedPassword);

    if (!query.exec()) {
        qDebug() << "Registration failed:" << query.lastError().text();
        return false;
    }
    return true;
}

QString LoginWindow::hashPassword(const QString &password) {
    QByteArray salt = "RandomSalt"; // 替换为实际随机盐
    QByteArray hash = QCryptographicHash::hash((password + salt).toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}
