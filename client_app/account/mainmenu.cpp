#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "../transactions/withdrawlpage.h"
#include "../transactions/depositpage.h"
#include <iostream>
#include <string>
#include "connectionstream/connectionStream.h"
#include <sstream>
MainMenu::MainMenu(int id, QWidget *parent) : QDialog(parent),
                                              ui(new Ui::MainMenu)
{
    ID = id;
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
            char nTransations[50];
            char transactionType[50];
            char amount[500];
            char date[50];

            stream->receive(name, 50);
            stream->receive(nationalID, 50);
            stream->receive(moneyAmount, 500);
            stream->receive(nTransations, 50);

            int numTransactions = atoi(nTransations);
            string multiLineTransactions;
            ostringstream oss;

            for (int i = 0; i < numTransactions; i++)
            {
                stream->receive(transactionType, 50);
                stream->receive(amount, 500);
                stream->receive(date, 50);

                if(strcmp(transactionType,"Deposit"))
                    oss << transactionType <<"\t" << amount << "\t" << date << "\n";
                else
                    oss << transactionType <<"\t\t" << amount << "\t" << date << "\n";
            }
            multiLineTransactions = oss.str();

            ui->nameLabel->setText(QString::fromUtf8(name));
            ui->nationalIDLabel->setText(QString::fromUtf8(nationalID));
            ui->balanceLabel->setText(QString::fromUtf8(moneyAmount));
            ui->logMultiLineLabel->setText(QString::fromStdString(multiLineTransactions));
        }
    }
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_withdrawButton_clicked()
{
    this->close();
    WithdrawlPage withdrawPage(ID);
    withdrawPage.setModal(true);
    withdrawPage.exec();
}

void MainMenu::on_despositButton_clicked()
{
    this->close();
    DepositPage depositPage(ID);
    depositPage.setModal(true);
    depositPage.exec();
}
