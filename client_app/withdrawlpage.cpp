#include "withdrawlpage.h"
#include "ui_withdrawlpage.h"

WithdrawlPage::WithdrawlPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawlPage)
{
    ui->setupUi(this);
}

WithdrawlPage::~WithdrawlPage()
{
    delete ui;
}

void WithdrawlPage::on_customButton_clicked()
{
    QString withdrawlAmount = ui->customTextEdit->toPlainText();

    // Subtract withdrawlAmount from server

    // on Success
    this->close();
}
