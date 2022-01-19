#include "withdrawlpage.h"
#include "ui_withdrawlpage.h"
#include "account/mainmenu.h"
#include "connectionstream/connectionStream.h"
#include <iostream>
#include <string>
#include <sstream>
WithdrawlPage::WithdrawlPage(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawlPage)
{
    ui->setupUi(this);
    ID = id;
}

WithdrawlPage::~WithdrawlPage()
{
    delete ui;
}

void WithdrawlPage::on_customButton_clicked()
{
    QString withdrawlAmount = ui->customTextEdit->toPlainText();

    ConnectionStream connStr;
    TCPStreamInfo *stream = connStr.getStream();

    stream->send("withdraw command", 50);
    stream->send(to_string(ID).c_str(), 50);
    stream->send(withdrawlAmount.toStdString().c_str(), 500);

    // on Success
    this->close();
    MainMenu mainMenu(ID);
    mainMenu.setModal(true);
    mainMenu.exec();
}
