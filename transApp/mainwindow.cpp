#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QScreen>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置主界面
    setupUI();
}
void MainWindow::setupUI() {
    translateButton = new QPushButton("开启划词翻译", this);
    translateButton->move(400, 100);
    connect(translateButton, &QPushButton::clicked, this, &MainWindow::addTranslateWindow); // 连接到翻译窗口

    subtitleButton = new QPushButton("开启实时字幕", this);
    subtitleButton->move(400, 150);
    connect(subtitleButton, &QPushButton::clicked, this, &MainWindow::addSubtitleWindow); // 连接到字幕窗口

    languageSelector = new QComboBox(this);
    languageSelector->move(400, 200);
    languageSelector->addItem("中文");
    languageSelector->addItem("英语");
    connect(languageSelector, &QComboBox::currentIndexChanged, this, &MainWindow::changeLanguage); // 连接语言选择

    QPushButton *settingsButton = new QPushButton("设置", this);
    settingsButton->move(400, 250);
    connect(settingsButton, &QPushButton::clicked, this, &MainWindow::openSettings); // 连接到设置窗口
}
void MainWindow::openSettings() {
    qDebug() << "打开设置窗口";
    SettingsWindow* settingsWindow = new SettingsWindow(this);
    settingsWindow->setWindowTitle("设置"); // 设置窗口标题，方便调试
    settingsWindow->move(400,300);
    settingsWindow->show();
}
void MainWindow::addTranslateWindow() {
    TranslateWindow * translateWindow = new TranslateWindow(); // 初始化指针
    translateWindow->resize(300,600);
    // 获取当前屏幕
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    int rightX = screenGeometry.width() - translateWindow->width(); // 计算右侧位置的 x 坐标
    int centerY = (screenGeometry.height() - translateWindow->height()) / 2; // 计算垂直中心的 y 坐标

    translateWindow->resize(300,600);

    // 设置翻译窗口的位置
    translateWindow->move(rightX, centerY);
    translateWindow->show();


}

void MainWindow::addSubtitleWindow() {
    SubtitleWindow *subtitleWindow = new SubtitleWindow();
    qDebug()<<"show chulai le1";
    subtitleWindow->show();
    qDebug()<<"show chulai le";
}

void MainWindow::changeLanguage(int index) {
    // 更新语言逻辑
}

void MainWindow::saveTranslation(const QString &translatedText) {
    historyList->addItem(translatedText);
}

MainWindow::~MainWindow()
{
    delete ui;
}
