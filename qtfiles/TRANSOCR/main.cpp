#include "widget.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QClipboard>
#include <QString>

QString captureAndRecognizeText();
QString translateText(const QString& text);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.resize(800, 600);

    // 截图按钮
    QPushButton captureButton(&window);
    captureButton.setText("截图翻译");

    // 粘贴翻译按钮
    QPushButton pasteButton(&window);
    pasteButton.setText("粘贴翻译");

    // 显示翻译结果的文本框
    QTextEdit resultTextEdit(&window);
    // 连接信号和槽
    QObject::connect(&captureButton, &QPushButton::clicked, [&]() {
        QString text = captureAndRecognizeText();
        QString translatedText = translateText(text);
        resultTextEdit.setText(translatedText);
    });

    QObject::connect(&pasteButton, &QPushButton::clicked, [&]() {
        QClipboard *clipboard = QApplication::clipboard();
        QString text = clipboard->text();
        QString translatedText = translateText(text);
        resultTextEdit.setText(translatedText);
    });




    window.show();
    return a.exec();
}
