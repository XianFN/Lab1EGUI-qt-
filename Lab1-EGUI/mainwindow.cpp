#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include<QDebug>
#include "addrecwindow.h"
#include "maincontroler.h"
#include "recipe.h"

using json = nlohmann::json;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillQlist();
}

MainWindow::~MainWindow()
{
    delete ui;
}
int MainWindow::getSelectedIndex(string stringSelected){


    mainControler* b = mainControler::getInstance();
    vector<Recipe*> recipes = b->recipes;
      int ret=100 ;

    for(unsigned int i = 0; i < recipes.size(); i++)
    {
         Recipe* aux = recipes[i];
        if (aux->getRecName()== stringSelected) {
            ret=i;
        }

    }
    return ret;
}
void MainWindow::fillQlist(){

    mainControler* b = mainControler::getInstance();
    vector<Recipe*> recipes = b->recipes;
    ui->listWidget->clear();

    for(unsigned int i = 0; i < recipes.size(); i++)
       {
            Recipe* aux = recipes[i];
           ui->listWidget->addItem(QString::fromStdString(aux->getRecName()));
       }


}



void MainWindow::on_btn1_clicked()
{

    addRecWindow RecWindow;
    RecWindow.setModal(true);
    RecWindow.exec();

    cout <<"pulsado"<<endl;




};

void MainWindow::on_actionShopping_List_triggered()
{
    //click shopping list
}

void MainWindow::on_btnRemove_clicked()
{
     string selecteditem = ui->listWidget->currentItem()->text().toStdString();
     int i = getSelectedIndex(selecteditem);
     mainControler* b = mainControler::getInstance();
     b->recipes.erase(b->recipes.begin() + i);

//     for( unsigned int a = 0; a < recipes.size(); a = a + 1 )
//     {
//         cout << recipes[a]->getRecName()<<endl;
//     }
 //    cout << "delete i: "<< i << endl;
    // delete b->recipes[i];
     b->updateJson();
     fillQlist();
     //añadir actualizar qlist

}

void MainWindow::on_btnModify_clicked()
{

    addRecWindow RecWindow;
    connect(this, &MainWindow::editIndexSignal,&RecWindow,&addRecWindow::editIndexSlot);

    string selecteditem = ui->listWidget->currentItem()->text().toStdString();


    emit editIndexSignal(getSelectedIndex(selecteditem));

    RecWindow.setModal(true);
    RecWindow.exec();

}
