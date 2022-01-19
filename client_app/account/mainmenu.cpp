#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "../transactions/withdrawlpage.h"
#include "../transactions/depositpage.h"
#include <iostream>
#include <string>
#include "connectionstream/connectionStream.h"

MainMenu::MainMenu(int ID, QWidget *parent) : QDialog(parent),
                                              ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    //Call server to get info
    ConnectionStream connStr;
    TCPStreamInfo *stream = connStr.getStream();

    stream->send("get info command", 50);
    stream->send(to_string(ID).c_str(), 50);

    int len;
    char line[256];
    if ((len = stream->receive(line, 10)) > 0)
    {
        line[len] = 0;
        if (strcmp(line, "ERROR") == 0)
        {
            cout << "OH NO ... MY CODE .. ITS BROKEN\n";
            ui->nameLabel->setText("error");
            ui->nationalIDLabel->setText("error");
            ui->balanceLabel->setText("error");
            ui->logMultiLineLabel->setText("error");

        }
        else //on success go to main menu
        {
            char name[50];
            char nationalID[50];
            char moneyAmount[500];

            stream->receive(name, 50);
            stream->receive(nationalID, 50);
            stream->receive(moneyAmount, 500);

            ui->nameLabel->setText(QString::fromUtf8(name));
            ui->nationalIDLabel->setText(QString::fromUtf8(nationalID));
            ui->balanceLabel->setText(QString::fromUtf8(moneyAmount));
            ui->logMultiLineLabel->setText("Withdw   $10.10   2022-01-03\nWithdraw   $23.12   2021-12-03\nDeposit   $102.12   2021-03-12");
        }
    }
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_withdrawButton_clicked()
{
    WithdrawlPage withdrawPage;
    withdrawPage.setModal(true);
    withdrawPage.exec();
}

void MainMenu::on_despositButton_clicked()
{
    DepositPage depositPage;
    depositPage.setModal(true);
    depositPage.exec();
}
