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
public:
    mainControler();
    ~mainControler();

    vector<Recipe*> recipes;
    void readJson();
    void updateJson();
    void updateJson2();
    void printRecipes();

};

#endif // MAINCONTROLER_H
