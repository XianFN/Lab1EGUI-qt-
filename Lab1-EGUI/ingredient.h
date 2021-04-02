#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <iostream>
#include <string>
using namespace std;


class Ingredient
{
public:
    Ingredient(string NewName, float NewQuantity, string NewUnits);
    Ingredient();
    ~Ingredient();

    string IngName;
    float IngQuantity;
    string IngUnits;

    void setName(string newName);
    void setQuantity(float newQuantity);
    void setUnits(string newUnits);

    Ingredient getIngredient();

    string getIngName() ;
    float getIngQuantity() ;
    string getIngUnits() ;
};

#endif // INGREDIENT_H
