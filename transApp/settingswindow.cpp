// settingswindow.cpp
#include "settingswindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QColorDialog>
#include <QFontDialog>
SettingsWindow::SettingsWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("设置窗口"); // 设置窗口标题
    setFixedSize(200, 200); // 设置固定大小
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *colorButton = new QPushButton("选择背景色", this);
    layout->addWidget(colorButton);
    connect(colorButton, &QPushButton::clicked, [this]() {
        QColor color = QColorDialog::getColor(Qt::white, this, "选择背景色");
        if (color.isValid()) {
            QPalette palette = this->palette();
            palette.setColor(QPalette::Window, color);
            this->setPalette(palette);
        }
    });

    QPushButton *saveButton = new QPushButton("保存设置", this);
    layout->addWidget(saveButton);
    connect(saveButton, &QPushButton::clicked, this, &SettingsWindow::close);

    QPushButton *fontButton = new QPushButton("选择字体", this);
    layout->addWidget(fontButton);
    connect(fontButton, &QPushButton::clicked, [this]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, QFont("Arial", 12), this, "选择字体");
        if (ok) {
            // 假设有指向 TranslateWindow 的指针
            //translateWindow->setFontStyle(font);--------------------todo
        }
    });

    // 选择透明度
    QSlider *opacitySlider = new QSlider(Qt::Horizontal, this);
    opacitySlider->setRange(0, 100);
    layout->addWidget(opacitySlider);
    connect(opacitySlider, &QSlider::valueChanged, [this](int value) {
        //translateWindow->setTransparency(value / 100.0); // 转换为 [0.0, 1.0]----------todo
    });

    setLayout(layout);
    qDebug() << "SettingsWindow 构造函数被调用";
}
