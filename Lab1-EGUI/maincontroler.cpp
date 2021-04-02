#include "maincontroler.h"
#include <nlohmann/json.hpp>
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

#include "recipe.h"
using namespace std;

mainControler::mainControler()
{
    readJson();
    // updateJson2();
    updateJson();


}
mainControler::~mainControler(){
    delete this;
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
    for( unsigned int a = 0; a < recipes.size(); a = a + 1 )
    {



        QJsonObject jsonRecipe;

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
        //intentar quitar primeros corchetes
        //probar si se lee e escribe a vez ben

        QString str3 = QString::fromUtf8(recName.c_str());
        QJsonArray jsonIngredients;
        QJsonObject jsonIngredient;
        jsonIngredient.insert("recipe", jsonArrayDesc);


        for( unsigned int b = 0; b < ingredients.size(); b = b + 1 )
        {

            string quantityUnits= ""+ to_string(ingredients[b]->getIngQuantity())+" "+ingredients[b]->getIngUnits();

            QString str2 = QString::fromUtf8(quantityUnits.c_str());
            QString str = QString::fromUtf8(ingredients[b]->getIngName().c_str());
            jsonIngredient.insert(str, str2);
    // good? 1 seg? 0.5?
            QThread::sleep(1);

        }

        jsonIngredients.append(jsonIngredient);
        jsonRecipe.insert(str3,jsonIngredients);
        jsonArray.append(jsonRecipe);



    }



    QJsonDocument jsonDoc;
    jsonDoc.setArray(jsonArray);

    file.write(jsonDoc.toJson());
    file.close();

    qDebug() << "Write to file";
}





void mainControler::updateJson2(){ //DEPRECATED

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
}

void mainControler::readJson(){

    using jsonf = nlohmann::json;


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








