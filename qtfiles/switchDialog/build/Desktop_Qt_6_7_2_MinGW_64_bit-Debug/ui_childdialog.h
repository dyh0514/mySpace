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
    QPushButton *returnBTN;
    QPushButton *exitBTN;
    QLabel *label;

    void setupUi(QDialog *childDialog)
    {
        if (childDialog->objectName().isEmpty())
            childDialog->setObjectName("childDialog");
        childDialog->resize(400, 300);
        returnBTN = new QPushButton(childDialog);
        returnBTN->setObjectName("returnBTN");
        returnBTN->setGeometry(QRect(70, 150, 93, 28));
        exitBTN = new QPushButton(childDialog);
        exitBTN->setObjectName("exitBTN");
        exitBTN->setGeometry(QRect(220, 150, 93, 28));
        label = new QLabel(childDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 80, 69, 19));

        retranslateUi(childDialog);
        QObject::connect(exitBTN, &QPushButton::clicked, childDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(childDialog);
    } // setupUi

    void retranslateUi(QDialog *childDialog)
    {
        childDialog->setWindowTitle(QCoreApplication::translate("childDialog", "Dialog", nullptr));
        returnBTN->setText(QCoreApplication::translate("childDialog", "\350\277\233\345\205\245\344\270\273\347\225\214\351\235\242", nullptr));
        exitBTN->setText(QCoreApplication::translate("childDialog", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("childDialog", "\345\255\220\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class childDialog: public Ui_childDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDDIALOG_H
