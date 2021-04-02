#include "mainwindow.h"
#include "addrecipewindow.h"
#include "maincontroler.h"

#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
   mainControler MainControler  = mainControler();
    MainWindow w;
    w.show();
    return a.exec();
}
