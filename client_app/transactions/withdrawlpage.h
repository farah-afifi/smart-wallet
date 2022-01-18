#ifndef WITHDRAWLPAGE_H
#define WITHDRAWLPAGE_H

#include <QDialog>

namespace Ui {
class WithdrawlPage;
}

class WithdrawlPage : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawlPage(QWidget *parent = nullptr);
    ~WithdrawlPage();

private slots:
    void on_customButton_clicked();

private:
    Ui::WithdrawlPage *ui;
};

#endif // WITHDRAWLPAGE_H
