#include "translatewindow.h"

TranslateWindow::TranslateWindow(QWidget *parent) : QWidget(parent) {
    translationResult = new QLabel("翻译结果将在这里显示", this);
}

void TranslateWindow::displayTranslation(const QString &translation) {
    translationResult->setText(translation);
}
