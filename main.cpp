#include "widget.h"
#include "login.h"
#include <QApplication>
#include"connection.h"
#include<QTime>
#include<QSplashScreen>
#include<QPixmap>
int main(int argc, char *argv[])
{

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

//    QApplication a(argc, argv);
    if(!CreatConnection())
    {
        return 1;
    }
//    Widget w;
//    w.setWindowIcon(QIcon("ooopic_1520340986.ico"));
//    w.setWindowTitle(("我的音乐"));
//    w.show();
//    return a.exec();
    QApplication a(argc, argv);
    login l;
    l.show();

    return a.exec();




}

