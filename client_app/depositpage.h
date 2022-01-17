#ifndef DEPOSITPAGE_H
#define DEPOSITPAGE_H

#include <QDialog>

namespace Ui {
class DepositPage;
}

class DepositPage : public QDialog
{
    Q_OBJECT

public:
    explicit DepositPage(QWidget *parent = nullptr);
    ~DepositPage();

private slots:
    void on_depositButton_clicked();

private:
    Ui::DepositPage *ui;
};

#endif // DEPOSITPAGE_H
