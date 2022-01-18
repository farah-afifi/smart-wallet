#include "depositpage.h"
#include "ui_depositpage.h"

DepositPage::DepositPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositPage)
{
    ui->setupUi(this);
}

DepositPage::~DepositPage()
{
    delete ui;
}

void DepositPage::on_depositButton_clicked()
{
    QString depositAmount = ui->depositTextEdit->toPlainText();


    // add depositAmount to account


    // on Success
    this->close();
}
