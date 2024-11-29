#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QTextFrame>
#include <QTextDocument>
#include <QColor>
#include <QTextCursor>
#include <QAction>
#include <QDebug>
#include <QTextBlockFormat>
#include <QTextCharFormat>
#include <QTextTableFormat>
#include <QTextListFormat>
#include <QTextImageFormat>>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextDocument * doc  = ui->textEdit->document();
    QTextFrame * root_frame = doc->rootFrame();
    QTextFrameFormat  formatFrame;
    formatFrame.setBorderBrush(Qt::green);
    formatFrame . setBorder(22);
    root_frame ->setFrameFormat(formatFrame);

    QTextFrameFormat formatFrame1 ;
    formatFrame1 .setBackground(Qt::gray);
    formatFrame1.setMargin(22);
    formatFrame1 .setPadding(22);
    formatFrame1.setBorder(2);
    formatFrame1.setBorderStyle(QTextFrameFormat::BorderStyle_Dashed);
    QTextCursor     cursor = ui->textEdit->textCursor();
    cursor.insertFrame(formatFrame1);
    ui->textEdit->insertPlainText("hhhhh\n");
    ui->textEdit->insertPlainText("hello\n");
    QAction * actframe  = new QAction("frame",this);
    connect( actframe,&QAction ::triggered, this,&MainWindow::showTextFrame);
    ui->toolBar ->addAction(actframe);

    QAction * action_block = new QAction(tr("文本块"),this);
    connect(action_block,&QAction::triggered,this,&MainWindow::showTextBlock);
     ui->toolBar ->addAction(action_block);

    QAction * action_font = new QAction(tr("字体"),this);
    action_font->setCheckable(true);  // 设置为可勾选
    connect(action_font, &QAction::toggled, this, &MainWindow::setTextFont);
    ui->toolBar->addAction(action_font);

    QAction * action_table = new QAction(tr("表格"),this);
    connect(action_table, &QAction::triggered, this, &MainWindow::setTable);
    ui->toolBar->addAction(action_table);

    QAction * action_picture = new QAction(tr("图片"),this);
    connect(action_picture, &QAction::triggered, this, &MainWindow::setPicture);
    ui->toolBar->addAction(action_picture);

    QAction * action_list = new QAction(tr("列表"),this);
    connect(action_list, &QAction::triggered, this, &MainWindow::setList);
    ui->toolBar->addAction(action_list);

    QAction * action_search = new QAction(tr("查找"),this);
    connect(action_search, &QAction::triggered, this, &MainWindow::setSerch);
    ui->toolBar->addAction(action_search);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: showTextFrame(){
    auto doc = ui->textEdit->document();
    auto root_frame = doc->rootFrame();
    for(auto iter = root_frame->begin();iter!=root_frame->end();iter++){
        auto cur_frame = iter.currentFrame();
        auto cur_block = iter.currentBlock();
        if(cur_frame){
            qDebug()<<"cur_frame\n";
        }else if(cur_block.isValid()){
            qDebug()<<"cur_block"<<cur_block.text();
        }
    }
}

void MainWindow::showTextBlock(){
    QTextDocument * document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();
    for(int i=0;i<document->blockCount();i++){
        qDebug()<< tr("文本块%1文本块首行行号%2,长度%3,内容%4").arg(i).
                    arg(block.firstLineNumber()).arg(block.length()).arg(block.text());
        block=block.next();
    }
}

void MainWindow::setTextFont(bool checked){
    if(checked){
        QTextCursor  cursor = ui->textEdit->textCursor();
        QTextBlockFormat block_format ;
        block_format.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(block_format);
        block_format.setBackground(Qt::gray);
        QTextCharFormat char_format;
        char_format .setBackground(Qt::lightGray);
        char_format .setBackground(Qt::blue);
        char_format .setFont(QFont(tr("宋体"),12,QFont::Bold,true));
        char_format .setFontUnderline(true);
        cursor.setCharFormat(char_format);
        cursor.insertText("插入字体\n");
    }else{
        QTextCursor cursor = ui->textEdit->textCursor();
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignLeft);
        cursor.setBlockFormat(blockFormat);
        QTextCharFormat charFormat;
        cursor.setCharFormat(charFormat);
        cursor.insertText(tr("微软雅黑"));
    }

}

void MainWindow:: setList(){
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat listFormat;
    listFormat.setStyle(QTextListFormat::ListDecimal);
    cursor.insertList(listFormat);

}
void MainWindow:: setTable(){
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextTableFormat tableformat;
    tableformat.setCellPadding(10);
    tableformat.setCellPadding(20);
    cursor.insertTable(2,2,tableformat);
}
void MainWindow:: setPicture(){
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextImageFormat imageformat;
    imageformat.setName(":/sea.jpg");
    cursor.insertImage(imageformat);
}
void MainWindow::setSerch(){

}
