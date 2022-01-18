#include "logindialog.h"
#include "ui_logindialog.h"
#include "account/mainmenu.h"

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



    // on Success
    this->close();
    MainMenu mainMenu;
    mainMenu.setModal(true);
    mainMenu.exec();
}
