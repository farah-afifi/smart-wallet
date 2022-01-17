#ifndef LANDINGPAGE_H
#define LANDINGPAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LandingPage; }
QT_END_NAMESPACE

class LandingPage : public QMainWindow
{
    Q_OBJECT

public:
    LandingPage(QWidget *parent = nullptr);
    ~LandingPage();

private slots:
    void on_loginButton_clicked();

    void on_signupButton_clicked();

private:
    Ui::LandingPage *ui;
};
#endif // LANDINGPAGE_H
