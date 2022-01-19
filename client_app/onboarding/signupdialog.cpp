#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "logindialog.h"
#include <iostream>
#include "connectionstream/connectionStream.h"
SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::on_signupButton_clicked()
{
    QString name = ui->nameTextEdit->toPlainText();
    QString age = ui->ageTextEdit->toPlainText();
    QString nationalID = ui->nationalIDTextEdit->toPlainText();
    QString password = ui->passwordTextEdit->toPlainText();

    if(name.toStdString() == "" || nationalID.toStdString() == "" || password.toStdString() == "" ){
        if(name.toStdString() == "")
            cout << "please enter your name!\n";
        if( nationalID.toStdString() == "")
            cout << "Please enter your national ID!\n";
        if(password.toStdString() == "")
            cout << "Password cant be empty!\n";
    }
    else{
        //call server to create account
        ConnectionStream connStr;
        TCPStreamInfo* stream = connStr.getStream();
        stream->send("sign up command", 50);
        stream->send(name.toStdString().c_str(), 50);
        stream->send(nationalID.toStdString().c_str(), 50);
        stream->send(password.toStdString().c_str(), 50);

        int len;
        char line[256];
        if((len = stream->receive(line, sizeof(line)))> 0) {
            line[len] = 0;
            if(strcmp(line,"ERROR") == 0 ){ //on failure
                cout << "this national ID has been used before!\n" <<
                "You can login directly using you national ID\n";
            }
            else //on success go to main menu
            {
                this->close();
                LoginDialog loginDialog;
                loginDialog.setModal(true);
                loginDialog.exec();
            }
        }

    }

}
