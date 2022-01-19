#include "depositpage.h"
#include "ui_depositpage.h"
#include "account/mainmenu.h"
#include "connectionstream/connectionStream.h"
#include <iostream>
#include <string>
#include <sstream>
DepositPage::DepositPage(int id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepositPage)
{
    ui->setupUi(this);
    ID = id;
}

DepositPage::~DepositPage()
{
    delete ui;
}

void DepositPage::on_depositButton_clicked()
{
    QString depositAmount = ui->depositTextEdit->toPlainText();

    ConnectionStream connStr;
    TCPStreamInfo *stream = connStr.getStream();

    stream->send("deposit command", 50);
    stream->send(to_string(ID).c_str(), 50);
    stream->send(depositAmount.toStdString().c_str(), 500);


    // on Success
    this->close();
    MainMenu mainMenu(ID);
    mainMenu.setModal(true);
    mainMenu.exec();
}
