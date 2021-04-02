#ifndef RECIPE_H
#define RECIPE_H
#include "ingredient.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Recipe
{
public:
    Recipe(string RecName,  vector<string> RecDescription);
    Recipe();
    ~Recipe();
    string RecName;
    vector<string> RecDescription;
    vector<Ingredient*> RecIngredients;

    void addRecIngredient(string NewName, float NewQuantity, string NewUnits);
    void setName(string newName);
    void setDescription( vector<string> newDescription);
    void printRecipe();



    Recipe getRecipe();
    void addRecipe();
    string getRecName() ;
    vector<string> getRecDescription() ;
    vector<Ingredient *> getRecIngredients() ;
    void setRecIngredients( vector<Ingredient *> &value);
};

#endif // RECIPE_H
