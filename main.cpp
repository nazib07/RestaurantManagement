#include "mainwindow.h"
#include "adminwindow.h"
#include "addnewcatagory.h"
#include "userlogin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    MainWindow w;
//    w.show();




//    AdminWindow w;
//    w.show();

    UserLogin w;
    w.show();

    return a.exec();
}
