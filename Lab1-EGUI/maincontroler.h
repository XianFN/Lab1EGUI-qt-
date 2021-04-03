#ifndef MAINCONTROLER_H
#define MAINCONTROLER_H
#include "ingredient.h"
#include "recipe.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class mainControler
{
private:
    mainControler();
    static mainControler* instance;


//    mainControler(mainControler const&);
//    void operator=(mainControler const&);

public:
 ~mainControler();
    static mainControler* getInstance();


    vector<Recipe*> recipes;
    void readJson();
    void updateJson();
    void updateJson2();
    void printRecipes();
    void addNewRecipe();


};

#endif // MAINCONTROLER_H
