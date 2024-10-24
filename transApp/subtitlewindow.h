#ifndef SUBTITLEWINDOW_H
#define SUBTITLEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QObject>

class SubtitleWindow : public QWidget {
    Q_OBJECT

public:
    SubtitleWindow(QWidget *parent = nullptr);
    void updateSubtitle(const QString &subtitle);

private:
    QLabel *subtitleText;
};

#endif
