/********************************************************************************
** Form generated from reading UI file 'childdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILDDIALOG_H
#define UI_CHILDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_childDialog
{
public:
    QLabel *label;
    QPushButton *showfatherpushButton;

    void setupUi(QDialog *childDialog)
    {
        if (childDialog->objectName().isEmpty())
            childDialog->setObjectName("childDialog");
        childDialog->resize(400, 300);
        label = new QLabel(childDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 140, 69, 19));
        showfatherpushButton = new QPushButton(childDialog);
        showfatherpushButton->setObjectName("showfatherpushButton");
        showfatherpushButton->setGeometry(QRect(100, 180, 93, 28));

        retranslateUi(childDialog);

        QMetaObject::connectSlotsByName(childDialog);
    } // setupUi

    void retranslateUi(QDialog *childDialog)
    {
        childDialog->setWindowTitle(QCoreApplication::translate("childDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("childDialog", "\345\255\220\347\225\214\351\235\242", nullptr));
        showfatherpushButton->setText(QCoreApplication::translate("childDialog", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class childDialog: public Ui_childDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDDIALOG_H
