#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT
    int ID;
public:
    explicit MainMenu( int ID, QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_withdrawButton_clicked();

    void on_despositButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
