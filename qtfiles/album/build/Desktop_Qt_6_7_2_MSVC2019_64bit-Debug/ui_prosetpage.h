/********************************************************************************
** Form generated from reading UI file 'prosetpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROSETPAGE_H
#define UI_PROSETPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_ProSetPage
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *tips;
    QLineEdit *lineEdit_2;

    void setupUi(QWizardPage *ProSetPage)
    {
        if (ProSetPage->objectName().isEmpty())
            ProSetPage->setObjectName("ProSetPage");
        ProSetPage->resize(614, 485);
        gridLayout_2 = new QGridLayout(ProSetPage);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 5, 5, 5);
        pushButton = new QPushButton(ProSetPage);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 4, 1, 1);

        label_2 = new QLabel(ProSetPage);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(ProSetPage);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 3);

        label = new QLabel(ProSetPage);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tips = new QLabel(ProSetPage);
        tips->setObjectName("tips");

        gridLayout->addWidget(tips, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(ProSetPage);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ProSetPage);

        QMetaObject::connectSlotsByName(ProSetPage);
    } // setupUi

    void retranslateUi(QWizardPage *ProSetPage)
    {
        ProSetPage->setWindowTitle(QCoreApplication::translate("ProSetPage", "WizardPage", nullptr));
        pushButton->setText(QCoreApplication::translate("ProSetPage", "browse", nullptr));
        label_2->setText(QCoreApplication::translate("ProSetPage", "Path\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("ProSetPage", "Name\357\274\232", nullptr));
        tips->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProSetPage: public Ui_ProSetPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROSETPAGE_H
