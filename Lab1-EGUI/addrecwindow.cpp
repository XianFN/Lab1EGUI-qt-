#include "addrecwindow.h"
#include "ui_addrecwindow.h"

addRecWindow::addRecWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRecWindow)
{
    ui->setupUi(this);
}

addRecWindow::~addRecWindow()
{
    delete ui;
}
