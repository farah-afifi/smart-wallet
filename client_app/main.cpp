#include "onboarding/landingpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LandingPage w;
    w.show();
    return a.exec();
}
