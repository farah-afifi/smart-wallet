/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *withdrawButton;
    QPushButton *despositButton;
    QLabel *nameLabel;
    QLabel *nationalIDLabel;
    QLabel *balanceLabel;
    QLabel *logMultiLineLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(708, 550);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 691, 531));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 141, 51));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 60, 81, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 100, 81, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 140, 181, 17));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 160, 191, 17));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 310, 141, 51));
        label_7->setFont(font);
        withdrawButton = new QPushButton(centralwidget);
        withdrawButton->setObjectName(QString::fromUtf8("withdrawButton"));
        withdrawButton->setGeometry(QRect(20, 380, 281, 141));
        despositButton = new QPushButton(centralwidget);
        despositButton->setObjectName(QString::fromUtf8("despositButton"));
        despositButton->setGeometry(QRect(410, 380, 271, 141));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(110, 60, 411, 17));
        nationalIDLabel = new QLabel(centralwidget);
        nationalIDLabel->setObjectName(QString::fromUtf8("nationalIDLabel"));
        nationalIDLabel->setGeometry(QRect(150, 100, 411, 17));
        balanceLabel = new QLabel(centralwidget);
        balanceLabel->setObjectName(QString::fromUtf8("balanceLabel"));
        balanceLabel->setGeometry(QRect(240, 140, 411, 17));
        logMultiLineLabel = new QLabel(centralwidget);
        logMultiLineLabel->setObjectName(QString::fromUtf8("logMultiLineLabel"));
        logMultiLineLabel->setGeometry(QRect(40, 190, 641, 111));
        logMultiLineLabel->setFrameShape(QFrame::WinPanel);
        logMultiLineLabel->setFrameShadow(QFrame::Raised);
        logMultiLineLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        logMultiLineLabel->setWordWrap(false);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 715, 22));
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 22));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainMenu", "Account Info", nullptr));
        label_2->setText(QApplication::translate("MainMenu", "Name:", nullptr));
        label_4->setText(QApplication::translate("MainMenu", "National ID:", nullptr));
        label_5->setText(QApplication::translate("MainMenu", "Current Account Balance:", nullptr));
        label_6->setText(QApplication::translate("MainMenu", "Transaction Log History:", nullptr));
        label_7->setText(QApplication::translate("MainMenu", "Actions", nullptr));
        withdrawButton->setText(QApplication::translate("MainMenu", "Withdraw", nullptr));
        despositButton->setText(QApplication::translate("MainMenu", "Deposit", nullptr));
        nameLabel->setText(QApplication::translate("MainMenu", "Farah Afifi", nullptr));
        nationalIDLabel->setText(QApplication::translate("MainMenu", "FA123456", nullptr));
        balanceLabel->setText(QApplication::translate("MainMenu", "$12345.00", nullptr));
        logMultiLineLabel->setText(QApplication::translate("MainMenu", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
