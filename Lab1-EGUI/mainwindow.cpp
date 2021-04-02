#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include<QDebug>
#include "addrecwindow.h"

using json = nlohmann::json;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn1_clicked()
{

    addRecWindow RecWindow;
    RecWindow.setModal(true);
    RecWindow.exec();



};
