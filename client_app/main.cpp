#include "onboarding/landingpage.h"
#include <iostream>
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "connectionstream/connectionStream.h"

using namespace std;
int main(int argc, char *argv[])
{
     if (argc != 3)
    {
        printf("usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }
    ConnectionStream connStr;
    TCPStreamInfo* stream1 = connStr.getStream(argv);
    delete stream1;
    
    QApplication a(argc, argv);
    LandingPage w;
    w.show();
    return a.exec();
}
