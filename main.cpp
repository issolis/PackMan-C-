#include "widget.h"

#include <QApplication>
#include <pathfindinglist.h>
#include <graphicview.h>
#include <windowgame.h>
#include <blocklist.h>
#include <QTimer>
#include <localserver.h>
#include <QThread>
#include <QRandomGenerator>
class serverManager{
public:

    LocalServer *server;
    LocalServer *server1;
    serverManager(){
        server=new LocalServer();
        server->listen(QHostAddress::Any, 5000);
        server1=new LocalServer();
        server1->listen(QHostAddress::Any, 3000);
    }

    void waitConnection(){
        while (true) {
            if (server->waitForNewConnection()) {
                qDebug()<<("Connected");
                break;
            }
            QThread::msleep(0.001);
        }

    }
    void waitConnection1(){
        while (true) {
            if (server1->waitForNewConnection()) {
                qDebug()<<("Connected");
                break;
            }
            QThread::msleep(0.001);
        }

    }
};
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   serverManager *manager= new serverManager();
   //manager->waitConnection();
   //manager->waitConnection1();
   widget w;
   w.Server=manager->server;
   w.show();



    return a.exec();

}



