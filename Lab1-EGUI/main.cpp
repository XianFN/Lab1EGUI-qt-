#include "mainwindow.h"
#include "addrecipewindow.h"
#include "maincontroler.h"

#include <QApplication>

int main(int argc, char *argv[])
{


   mainControler* b= mainControler::getInstance();
   b->readJson();

   QApplication a(argc, argv);
   MainWindow w;
   w.show();
   return a.exec();

}
