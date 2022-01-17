#include "landingpage.h"
#include "ui_landingpage.h"
#include "logindialog.h"
#include "signupdialog.h"

LandingPage::LandingPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LandingPage)
{
    ui->setupUi(this);
}

LandingPage::~LandingPage()
{
    delete ui;
}


void LandingPage::on_loginButton_clicked()
{
    LoginDialog loginDialog;
    loginDialog.setModal(true);
    loginDialog.exec();
}

void LandingPage::on_signupButton_clicked()
{
    SignupDialog signupDialog;
    signupDialog.setModal(true);
    signupDialog.exec();
}
