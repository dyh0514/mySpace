#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include "apimanager.h"
#include "screenshottool.h"
class TranslateWindow : public QWidget {
    Q_OBJECT

public:
    TranslateWindow(QWidget *parent = nullptr);
    void setFontStyle(const QFont &font);
    void setTransparency(double value);

private slots:
    void onScreenshotButtonClicked();
    void onPasteButtonClicked();
    void onTranslateButtonClicked();
    void onCopyButtonClicked();
    void onSaveButtonClicked();
    void processScreenshot(const QPixmap &screenshot);

public slots:
    void onApiChanged(int index);

private:
    QComboBox *sourceLanguageComboBox;
    QComboBox *targetLanguageComboBox;
    QComboBox *apiComboBox;
    QPushButton *screenshotButton;
    QLineEdit *textInput;
    QPushButton *pasteButton;
    QPushButton *translateButton;
    QLabel *translationResultLabel;
    QPushButton *copyButton;
    QPushButton *saveButton;

    ScreenshotTool *screenshotTool;
};
