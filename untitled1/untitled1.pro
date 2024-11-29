#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loadButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.xpm *.jpg)");
    if (!filePath.isEmpty()) {
        loadImage(filePath);
    }
}

void MainWindow::loadImage(const QString &filePath) {
    if (image.load(filePath)) {
        ui->imageLabel->setPixmap(QPixmap::fromImage(image).scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
    } else {
        QMessageBox::critical(this, "Error", "Failed to load image.");
    }
}

void MainWindow::on_recognizeButton_clicked() {
    recognizeText();
}

void MainWindow::recognizeText() {
    if (image.isNull()) {
        QMessageBox::warning(this, "Error", "No image loaded.");
        return;
    }

    // Convert QImage to Pix
    Pix *pix = pixCreate(image.width(), image.height(), 8);
    if (!pix) {
        QMessageBox::critical(this, "Error", "Failed to create Pix object.");
        return;
    }

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QRgb color = image.pixel(x, y);
            l_uint32 gray = qGray(color);
            pixSetPixel(pix, x, y, gray);
        }
    }

    // Set the TESSDATA_PREFIX environment variable
    putenv("TESSDATA_PREFIX=C:/Program Files/Tesseract-OCR/");

    // Initialize Tesseract API
    tesseract::TessBaseAPI api;
    if (api.Init(NULL, "chi_sim")) {
        QMessageBox::critical(this, "Error", "Could not initialize tesseract.");
        pixDestroy(&pix);
        return;
    }

    api.SetImage(pix);
    if (api.Recognize(0) != 0) {
        QMessageBox::critical(this, "Error", "Failed to recognize text.");
        api.End();
        pixDestroy(&pix);
        return;
    }

    const char *text = api.GetUTF8Text();
    if (!text) {
        QMessageBox::critical(this, "Error", "Failed to get recognized text.");
    } else {
        ui->textEdit->setText(QString::fromUtf8(text));
        delete[] text;
    }

    // Clean up
    api.End();
    pixDestroy(&pix);
}
