/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SignupDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *nameTextEdit;
    QTextEdit *ageTextEdit;
    QTextEdit *nationalIDTextEdit;
    QTextEdit *passwordTextEdit;
    QPushButton *signupButton;

    void setupUi(QDialog *SignupDialog)
    {
        if (SignupDialog->objectName().isEmpty())
            SignupDialog->setObjectName(QString::fromUtf8("SignupDialog"));
        SignupDialog->resize(400, 247);
        label = new QLabel(SignupDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 61, 17));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(SignupDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 71, 17));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(SignupDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 100, 81, 17));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(SignupDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 140, 81, 17));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        nameTextEdit = new QTextEdit(SignupDialog);
        nameTextEdit->setObjectName(QString::fromUtf8("nameTextEdit"));
        nameTextEdit->setGeometry(QRect(90, 10, 291, 31));
        ageTextEdit = new QTextEdit(SignupDialog);
        ageTextEdit->setObjectName(QString::fromUtf8("ageTextEdit"));
        ageTextEdit->setGeometry(QRect(90, 50, 291, 31));
        nationalIDTextEdit = new QTextEdit(SignupDialog);
        nationalIDTextEdit->setObjectName(QString::fromUtf8("nationalIDTextEdit"));
        nationalIDTextEdit->setGeometry(QRect(90, 90, 291, 31));
        passwordTextEdit = new QTextEdit(SignupDialog);
        passwordTextEdit->setObjectName(QString::fromUtf8("passwordTextEdit"));
        passwordTextEdit->setGeometry(QRect(90, 130, 291, 31));
        signupButton = new QPushButton(SignupDialog);
        signupButton->setObjectName(QString::fromUtf8("signupButton"));
        signupButton->setGeometry(QRect(0, 180, 401, 51));

        retranslateUi(SignupDialog);

        QMetaObject::connectSlotsByName(SignupDialog);
    } // setupUi

    void retranslateUi(QDialog *SignupDialog)
    {
        SignupDialog->setWindowTitle(QApplication::translate("SignupDialog", "Signup Page", nullptr));
        label->setText(QApplication::translate("SignupDialog", "Name", nullptr));
        label_2->setText(QApplication::translate("SignupDialog", "Age", nullptr));
        label_3->setText(QApplication::translate("SignupDialog", "National ID", nullptr));
        label_4->setText(QApplication::translate("SignupDialog", "Password", nullptr));
        signupButton->setText(QApplication::translate("SignupDialog", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupDialog: public Ui_SignupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
