#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "logindialog.h"

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


    //call server to create account




    //onSuccess
    this->close();
    LoginDialog loginDialog;
    loginDialog.setModal(true);
    loginDialog.exec();

    //onFaliure
    //show error message
}
