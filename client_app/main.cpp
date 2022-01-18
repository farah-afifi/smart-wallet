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
    TCPStreamInfo* stream = ConnectionStream().getStream(argv);
    stream = ConnectionStream().getStream();
    if(stream)
    cout << "hello world!\n";
    
    QApplication a(argc, argv);
    LandingPage w;
    w.show();
    return a.exec();
}
