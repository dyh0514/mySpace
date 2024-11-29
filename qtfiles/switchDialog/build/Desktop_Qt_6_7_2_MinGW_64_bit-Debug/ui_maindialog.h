/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *enterchildBTN;
    QPushButton *exitBTN;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName("MainDialog");
        MainDialog->resize(800, 600);
        centralwidget = new QWidget(MainDialog);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 200, 69, 19));
        enterchildBTN = new QPushButton(centralwidget);
        enterchildBTN->setObjectName("enterchildBTN");
        enterchildBTN->setGeometry(QRect(180, 270, 93, 28));
        exitBTN = new QPushButton(centralwidget);
        exitBTN->setObjectName("exitBTN");
        exitBTN->setGeometry(QRect(390, 270, 93, 28));
        MainDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainDialog);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(MainDialog);
        statusbar->setObjectName("statusbar");
        MainDialog->setStatusBar(statusbar);

        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QMainWindow *MainDialog)
    {
        MainDialog->setWindowTitle(QCoreApplication::translate("MainDialog", "MainDialog", nullptr));
        label->setText(QCoreApplication::translate("MainDialog", "\344\270\273\347\225\214\351\235\242", nullptr));
        enterchildBTN->setText(QCoreApplication::translate("MainDialog", "\350\277\233\345\205\245\345\255\220\347\225\214\351\235\242", nullptr));
        exitBTN->setText(QCoreApplication::translate("MainDialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
