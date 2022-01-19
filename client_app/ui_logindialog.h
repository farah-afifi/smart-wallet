/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QPushButton *loginButton;
    QTextEdit *passwordTextEdit;
    QTextEdit *nationalIDTextEdit;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(420, 189);
        menubar = new QMenuBar(LoginDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 420, 22));
        statusbar = new QStatusBar(LoginDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(0, 120, 421, 51));
        passwordTextEdit = new QTextEdit(LoginDialog);
        passwordTextEdit->setObjectName(QString::fromUtf8("passwordTextEdit"));
        passwordTextEdit->setGeometry(QRect(90, 70, 311, 31));
        nationalIDTextEdit = new QTextEdit(LoginDialog);
        nationalIDTextEdit->setObjectName(QString::fromUtf8("nationalIDTextEdit"));
        nationalIDTextEdit->setGeometry(QRect(90, 30, 311, 31));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 67, 17));
        label = new QLabel(LoginDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 131, 17));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login Page", nullptr));
        loginButton->setText(QApplication::translate("LoginDialog", "Login", nullptr));
        label_2->setText(QApplication::translate("LoginDialog", "Pin code", nullptr));
        label->setText(QApplication::translate("LoginDialog", "National ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
