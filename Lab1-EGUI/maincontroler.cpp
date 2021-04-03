#include "maincontroler.h"
#include <nlohmann/json.hpp>
#include <nlohmann/fifo_map.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QThread>

#include "mainwindow.h"
#include "addrecipewindow.h"

#include <QApplication>

#include "recipe.h"
using namespace std;

mainControler::mainControler()
{


    // updateJson2();
    //updateJson();


}


mainControler::~mainControler(){
    delete this;
}
mainControler* mainControler::instance = 0;

mainControler* mainControler::getInstance(){

    if (instance==0) {
        instance= new mainControler();
    }


return instance;


}

void  mainControler::addNewRecipe(){ //DEPRECATED
// Recipe* newRecipe = new Recipe();
// newRecipe->setName("hola");
// newRecipe->setDescription({"asdas","sds"});
// this->recipes.push_back(newRecipe);
// updateJson();



}
void mainControler::updateJson(){

    // Open the 1.json file in the main directory by reading and writing. If the file does not exist, it will be created automatically.
    QFile file(QDir::homePath() + "/recipes.json");
    if(!file.open(QIODevice::ReadWrite)) {
        qDebug() << "File open error";
    } else {
        qDebug() <<"File open!";
    }

    file.resize(0);

    // Add a value using QJsonArray and write to the file
    QJsonArray jsonArray;
    QJsonObject jsonRecipe;


    cout << "TOTAL NUMBER OF RECIPES TO WRITTE:  "<<recipes.size()<<endl;

    for( unsigned int a = 0; a < recipes.size(); a = a + 1 )
    {
        Recipe* recipeaux= recipes[a];
        vector<Ingredient*> ingredients= recipeaux->getRecIngredients();

        string recName= recipeaux->getRecName();
        QJsonArray jsonArrayDesc;
        vector <string> vectorDescription= recipeaux->getRecDescription();

        for( unsigned int a = 0; a < vectorDescription.size(); a = a + 1 )
        {
            jsonArrayDesc.append(QString::fromStdString(vectorDescription[a].c_str()));
        }
        //TODO CAMBIAR NOMBRE VARIABLES
        //TODO quitar 0 de las unidades
        //TODO quitar orden alfabético
        //probar si se lee e escribe a vez ben

        QString qStringRecName = QString::fromUtf8(recName.c_str());
        QJsonObject jsonIngredient;
        jsonIngredient.insert(" recipe", jsonArrayDesc);


            for( unsigned int b = 0; b < ingredients.size(); b = b + 1 )
            {

                string quantityUnits= ""+ to_string(ingredients[b]->getIngQuantity())+" "+ingredients[b]->getIngUnits();
                QString qStringIngUnits = QString::fromUtf8(quantityUnits.c_str());
                QString qStringIngName = QString::fromUtf8(ingredients[b]->getIngName().c_str());

                jsonIngredient.insert(qStringIngName, qStringIngUnits);
                QThread::sleep(1);

            }

        jsonRecipe.insert(qStringRecName,jsonIngredient);

    }


    jsonArray.append(jsonRecipe);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonRecipe);


    file.write(jsonDoc.toJson());
    file.close();

    qDebug() << "Write to file";
}





void mainControler::updateJson2(){ //DEPRECATED
/*
    using json = nlohmann::json;

    //add Recipe
    json j2;

    for( unsigned int a = 0; a < recipes.size(); a = a + 1 )
    {
        Recipe* recipeaux= recipes[a];
        vector<Ingredient*> ingredients= recipeaux->getRecIngredients();

        string a1= {recipeaux->getRecName()};

        string recName= recipeaux->getRecName();
        j2 += {{recName,{{"recipe", recipeaux->getRecDescription()}}}};
        for( unsigned int b = 0; b < ingredients.size(); b = b + 1 )
        {
            string quantityUnits= ""+ to_string(ingredients[b]->getIngQuantity())+" "+ingredients[b]->getIngUnits();
            json j3 = { {"recipe", recipeaux->getRecDescription()},{ingredients[b]->IngName,quantityUnits}};
            //j2.push_back(j3);
        }



        cout<< "sfsfsdf"<<endl;

        //j2.push_back(j);


    }


    string key{"hola"};
    string key2{"adios"};
    string value{"1234"};

    json k;
    json k2;
    json k3;
    k2["hola"] = value;
    k3["bye"] = value;

    //k[""].push_back(k2);
    k2[key].push_back(k3);





    ofstream o("recipes2.json");
    o  << setw(1) << k2 << endl;
    */
}
using namespace nlohmann;

// A workaround to give to use fifo_map as map, we are just ignoring the 'less' compare
template<class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = fifo_map<K, V, fifo_map_compare<K>, A>;
using jsonf = basic_json<my_workaround_fifo_map>;

void mainControler::readJson(){


    using namespace nlohmann;

    ifstream i("recipes.json");
    jsonf j;
    i >> j;



    for (jsonf::iterator it = j.begin(); it != j.end(); ++it) {



        cout <<endl << it.key() << endl << endl;
        Recipe* recRead = new Recipe();
        jsonf a = it.value();
        recRead->setName(it.key());
        for (jsonf::iterator it2 = a.begin(); it2 != a.end(); ++it2) {

            if (it2.key()=="recipe") {
                recRead->setDescription(it2.value());
                cout << "FFFF"<< endl;

            }else{

                string ingString = it2.value();


                istringstream buf(ingString);
                istream_iterator<string> beg(buf), end;

                vector<string> readIngredient(beg, end);


                cout << readIngredient[0] << endl;
                string ingUnit="";
                for( unsigned int a = 1; a < readIngredient.size(); a = a + 1 ) {
                    ingUnit= ingUnit+ readIngredient[a];
                }
                string newName= it2.key();
                float newQuantity = stod(readIngredient[0]);
                recRead->addRecIngredient(newName,newQuantity,ingUnit);
            }

        }
        recRead->printRecipe();
        recipes.push_back(recRead);
        //añadir receta al array y borrar datos de esta receta o crear una nueva


    }
    printRecipes();



}
void mainControler::printRecipes(){
    cout << this->recipes.size() <<endl<<endl<<endl;

}








