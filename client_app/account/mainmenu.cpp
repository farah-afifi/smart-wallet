#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "../transactions/withdrawlpage.h"
#include "../transactions/depositpage.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    //Call server to get info

    // in callback update Account Info
    ui->nameLabel->setText("Farah Afifi");
    ui->ageLabel->setText("30");
    ui->nationalIDLabel->setText("FA123456");
    ui->balanceLabel->setText("$12345");
    ui->logMultiLineLabel->setText("Withdraw   $10.10   2022-01-03\nWithdraw   $23.12   2021-12-03\nDeposit   $102.12   2021-03-12");

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
