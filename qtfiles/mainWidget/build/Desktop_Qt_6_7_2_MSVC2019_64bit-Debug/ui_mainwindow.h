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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *actionnew_2;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(437, 693);
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName("actionnew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icons8_document_32_CCF_icon.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionnew->setIcon(icon);
        actionnew_2 = new QAction(MainWindow);
        actionnew_2->setObjectName("actionnew_2");
        actionnew_2->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName("mdiArea");
        mdiArea->setGeometry(QRect(10, 10, 311, 201));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 437, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        verticalLayoutWidget = new QWidget(dockWidgetContents);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 50, 211, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dockWidget);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionnew);
        menu->addAction(actionnew_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionnew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", nullptr));
        actionnew->setIconText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266(N)", nullptr));
        actionnew_2->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272DOCK(&D)", nullptr));
        actionnew_2->setIconText(QCoreApplication::translate("MainWindow", "showdock(D)", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\347\256\261", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
