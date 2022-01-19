#ifndef WITHDRAWLPAGE_H
#define WITHDRAWLPAGE_H

#include <QDialog>

namespace Ui {
class WithdrawlPage;
}

class WithdrawlPage : public QDialog
{
    Q_OBJECT
    int ID;

public:
    explicit WithdrawlPage(int ID, QWidget *parent = nullptr);
    ~WithdrawlPage();

private slots:
    void on_customButton_clicked();

private:
    Ui::WithdrawlPage *ui;
};

#endif // WITHDRAWLPAGE_H
