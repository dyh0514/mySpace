/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *colorBTN;
    QPushButton *textBTN;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        colorBTN = new QPushButton(centralwidget);
        colorBTN->setObjectName("colorBTN");
        colorBTN->setGeometry(QRect(80, 80, 93, 28));
        textBTN = new QPushButton(centralwidget);
        textBTN->setObjectName("textBTN");
        textBTN->setGeometry(QRect(200, 80, 93, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(320, 80, 93, 28));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(460, 80, 93, 28));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(80, 160, 93, 28));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(210, 160, 93, 28));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 160, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(460, 160, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        colorBTN->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262", nullptr));
        textBTN->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\225\264\345\275\242", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\265\256\347\202\271\345\236\213", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\235\241\347\233\256", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\346\217\220\347\244\272", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\272\246", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\220\221\345\257\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
