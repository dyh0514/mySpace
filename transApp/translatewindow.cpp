#include "translatewindow.h"
TranslateWindow::TranslateWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("翻译窗口");
    setFixedSize(300, 800);

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 源语言和目标语言选择框及转换按钮
    QHBoxLayout *languageLayout = new QHBoxLayout();

    // 标签
    QLabel *sourceLabel = new QLabel("源语言:");
    QLabel *targetLabel = new QLabel("目标语言:");

    sourceLanguageComboBox = new QComboBox();
    targetLanguageComboBox = new QComboBox();

    // 添加语言选项（示例）
    sourceLanguageComboBox->addItem("中文");
    sourceLanguageComboBox->addItem("法语");
    sourceLanguageComboBox->addItem("英语");

    targetLanguageComboBox->addItem("中文");
    targetLanguageComboBox->addItem("法语");
    targetLanguageComboBox->addItem("英语");

    QPushButton *convertButton = new QPushButton("转换");

    // 将标签和选择框加入布局
    languageLayout->addWidget(sourceLabel);
    languageLayout->addWidget(sourceLanguageComboBox);
    languageLayout->addWidget(convertButton);
    languageLayout->addWidget(targetLabel);
    languageLayout->addWidget(targetLanguageComboBox);

    mainLayout->addLayout(languageLayout);



    // API选择框
    QLabel *apiLabel = new QLabel("选择翻译API:");
    apiComboBox = new QComboBox();

    apiLabel->setFixedSize(80, 30); // 设置固定大小
    apiLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

    // 设置不同颜色
    QPalette apiPalette = apiLabel->palette();
    apiPalette.setColor(QPalette::Window, Qt::green);
    apiPalette.setColor(QPalette::WindowText, Qt::blue);
    apiLabel->setAutoFillBackground(true);
    apiLabel->setPalette(apiPalette);

    apiComboBox->addItems({"Google Translate", "Baidu Translate", "Tencent Translate"});

    mainLayout->addWidget(apiLabel);
    mainLayout->addWidget(apiComboBox);


    // 截图按钮和文本框
    screenshotButton = new QPushButton("截图");
    textInput = new QLineEdit();
    textInput->setFixedSize(280, 150); // 设置固定大小
    textInput->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    pasteButton = new QPushButton("粘贴");

    mainLayout->addWidget(screenshotButton);
    mainLayout->addWidget(textInput);
    mainLayout->addWidget(pasteButton);

    // 翻译按钮
    translateButton = new QPushButton("翻译");
    mainLayout->addWidget(translateButton);

    // 翻译结果显示区
    translationResultLabel = new QLabel();
    translationResultLabel->setFixedSize(280, 180); // 设置固定大小

    QPalette transPalette = translationResultLabel->palette();
    transPalette.setColor(QPalette::Window, Qt::green);
    transPalette.setColor(QPalette::WindowText, Qt::blue);
    translationResultLabel->setAutoFillBackground(true);
    translationResultLabel->setPalette(transPalette);

    mainLayout->addWidget(translationResultLabel);

    // 复制和保存按钮
    copyButton = new QPushButton("复制结果");
    saveButton = new QPushButton("保存结果");

    mainLayout->addWidget(copyButton);
    mainLayout->addWidget(saveButton);

    screenshotTool = new ScreenshotTool(this);
    connect(screenshotTool, &ScreenshotTool::screenshotTaken, this, &TranslateWindow::processScreenshot);

    // 连接信号和槽
    connect(screenshotButton, &QPushButton::clicked, this, &TranslateWindow::onScreenshotButtonClicked);
    connect(pasteButton, &QPushButton::clicked, this, &TranslateWindow::onPasteButtonClicked);
    connect(translateButton, &QPushButton::clicked, this, &TranslateWindow::onTranslateButtonClicked);
    connect(copyButton, &QPushButton::clicked, this, &TranslateWindow::onCopyButtonClicked);
    connect(saveButton, &QPushButton::clicked, this, &TranslateWindow::onSaveButtonClicked);

    connect(convertButton, &QPushButton::clicked, [this]() {
        int sourceIndex = sourceLanguageComboBox->currentIndex();
        int targetIndex = targetLanguageComboBox->currentIndex();

        // 交换当前选择的语言
        sourceLanguageComboBox->setCurrentIndex(targetIndex);
        targetLanguageComboBox->setCurrentIndex(sourceIndex);
    });
}

void TranslateWindow:: onPasteButtonClicked(){

}
void TranslateWindow:: onTranslateButtonClicked(){
    QString text = textInput->text(); // 获取文本框输入
    QString selectedApi = apiComboBox->currentText(); // 获取选中的API

    // 创建 ApiManager 实例
    ApiManager *apiManager = new ApiManager(this);

    // 连接翻译完成信号
    connect(apiManager, &ApiManager::translationFinished, this, [this](const QString &result) {
        qDebug()<<result;
        translationResultLabel->setText(result); // 更新翻译结果显示
    });
    qDebug()<<"更新成功";

    // 调用翻译函数
    apiManager->translate(text, selectedApi);
}
void TranslateWindow:: onCopyButtonClicked(){

}
void TranslateWindow:: onSaveButtonClicked(){

}
void TranslateWindow::onApiChanged(int index){

}

void TranslateWindow::onScreenshotButtonClicked() {
    screenshotTool->startSelection();
}
void TranslateWindow::processScreenshot(const QPixmap &screenshot) {
    // 这里可以处理截图，例如使用 OCR 识别文字
    // 示例：将截图显示在 QLabel 上
    QLabel *screenshotLabel = new QLabel(this);
    screenshotLabel->setPixmap(screenshot);
    screenshotLabel->setScaledContents(true);
    screenshotLabel->setFixedSize(300, 300); // 根据需要调整大小
    screenshotLabel->show();

    // 继续进行 OCR 识别
}
