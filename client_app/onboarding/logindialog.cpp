#include "logindialog.h"
#include "ui_logindialog.h"
#include "account/mainmenu.h"
#include <iostream>
#include "connectionstream/connectionStream.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_loginButton_clicked()
{
    QString nationalID = ui->nationalIDTextEdit->toPlainText();
    QString password = ui->passwordTextEdit->toPlainText();

    ConnectionStream connStr;
    TCPStreamInfo* stream = connStr.getStream();
    stream->send("login command", 50);
    stream->send(nationalID.toStdString().c_str(), 50);
    stream->send(password.toStdString().c_str(), 50);

    int len;
    char line[256];
    if((len = stream->receive(line, 10))> 0) {
        line[len] = 0;
        if(strcmp(line,"ERROR") == 0 ){
            cout << "your password or natoinal ID is incorrect!\n";
        }
        else //on success go to main menu
        {
            stream->receive(line, 50);
            this->close();
            MainMenu mainMenu(stoi(line));
            mainMenu.setModal(true);
            mainMenu.exec();
        }
     }


}
