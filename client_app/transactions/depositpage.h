#ifndef DEPOSITPAGE_H
#define DEPOSITPAGE_H

#include <QDialog>

namespace Ui {
class DepositPage;
}

class DepositPage : public QDialog
{
    Q_OBJECT
    int ID;

public:
    explicit DepositPage(int ID, QWidget *parent = nullptr);
    ~DepositPage();

private slots:
    void on_depositButton_clicked();

private:
    Ui::DepositPage *ui;
};

#endif // DEPOSITPAGE_H
