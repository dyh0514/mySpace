#include "subtitlewindow.h"

SubtitleWindow::SubtitleWindow(QWidget *parent) : QWidget(parent) {
    subtitleText = new QLabel("字幕将在这里显示", this);
}

void SubtitleWindow::updateSubtitle(const QString &subtitle) {
    subtitleText->setText(subtitle);
}
