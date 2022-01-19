/********************************************************************************
** Form generated from reading UI file 'withdrawlpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWLPAGE_H
#define UI_WITHDRAWLPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_WithdrawlPage
{
public:
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QPushButton *customButton;
    QLabel *label;
    QPushButton *withdraw10Button;
    QLabel *label_2;
    QTextEdit *customTextEdit;
    QPushButton *withdraw100Button;
    QPushButton *withdraw50Button;

    void setupUi(QDialog *WithdrawlPage)
    {
        if (WithdrawlPage->objectName().isEmpty())
            WithdrawlPage->setObjectName(QString::fromUtf8("WithdrawlPage"));
        WithdrawlPage->resize(337, 146);
        menubar = new QMenuBar(WithdrawlPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 327, 22));
        statusbar = new QStatusBar(WithdrawlPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));
        customButton = new QPushButton(WithdrawlPage);
        customButton->setObjectName(QString::fromUtf8("customButton"));
        customButton->setGeometry(QRect(230, 80, 81, 31));
        label = new QLabel(WithdrawlPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 42, 111, 20));
        withdraw10Button = new QPushButton(WithdrawlPage);
        withdraw10Button->setObjectName(QString::fromUtf8("withdraw10Button"));
        withdraw10Button->setGeometry(QRect(130, 40, 51, 25));
        label_2 = new QLabel(WithdrawlPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 67, 31));
        customTextEdit = new QTextEdit(WithdrawlPage);
        customTextEdit->setObjectName(QString::fromUtf8("customTextEdit"));
        customTextEdit->setGeometry(QRect(80, 80, 141, 31));
        withdraw100Button = new QPushButton(WithdrawlPage);
        withdraw100Button->setObjectName(QString::fromUtf8("withdraw100Button"));
        withdraw100Button->setGeometry(QRect(250, 40, 51, 25));
        withdraw50Button = new QPushButton(WithdrawlPage);
        withdraw50Button->setObjectName(QString::fromUtf8("withdraw50Button"));
        withdraw50Button->setGeometry(QRect(190, 40, 51, 25));

        retranslateUi(WithdrawlPage);

        QMetaObject::connectSlotsByName(WithdrawlPage);
    } // setupUi

    void retranslateUi(QDialog *WithdrawlPage)
    {
        WithdrawlPage->setWindowTitle(QApplication::translate("WithdrawlPage", "Withdrawl Page", nullptr));
        customButton->setText(QApplication::translate("WithdrawlPage", "Withdraw", nullptr));
        label->setText(QApplication::translate("WithdrawlPage", "Quick Amount", nullptr));
        withdraw10Button->setText(QApplication::translate("WithdrawlPage", "$10", nullptr));
        label_2->setText(QApplication::translate("WithdrawlPage", "Custom", nullptr));
        withdraw100Button->setText(QApplication::translate("WithdrawlPage", "$100", nullptr));
        withdraw50Button->setText(QApplication::translate("WithdrawlPage", "$50", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WithdrawlPage: public Ui_WithdrawlPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWLPAGE_H
