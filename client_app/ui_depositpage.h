/********************************************************************************
** Form generated from reading UI file 'depositpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITPAGE_H
#define UI_DEPOSITPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DepositPage
{
public:
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QPushButton *depositButton;
    QTextEdit *depositTextEdit;

    void setupUi(QDialog *DepositPage)
    {
        if (DepositPage->objectName().isEmpty())
            DepositPage->setObjectName(QString::fromUtf8("DepositPage"));
        DepositPage->resize(351, 165);
        menubar = new QMenuBar(DepositPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 351, 22));
        statusbar = new QStatusBar(DepositPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));
        depositButton = new QPushButton(DepositPage);
        depositButton->setObjectName(QString::fromUtf8("depositButton"));
        depositButton->setGeometry(QRect(70, 100, 221, 41));
        depositTextEdit = new QTextEdit(DepositPage);
        depositTextEdit->setObjectName(QString::fromUtf8("depositTextEdit"));
        depositTextEdit->setGeometry(QRect(20, 50, 311, 31));

        retranslateUi(DepositPage);

        QMetaObject::connectSlotsByName(DepositPage);
    } // setupUi

    void retranslateUi(QDialog *DepositPage)
    {
        DepositPage->setWindowTitle(QApplication::translate("DepositPage", "Deposit Page", nullptr));
        depositButton->setText(QApplication::translate("DepositPage", "deposit", nullptr));
        depositTextEdit->setPlaceholderText(QApplication::translate("DepositPage", "$123.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositPage: public Ui_DepositPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITPAGE_H
