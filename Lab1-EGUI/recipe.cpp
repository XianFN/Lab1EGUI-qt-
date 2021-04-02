#include "recipe.h"
#include <vector>
#include <string>
#include "ingredient.h"
using namespace std;

Recipe::Recipe(string RecName,  vector<string> RecDescription)
{
    this->RecName=RecName;
    this->RecDescription=RecDescription;
    this->RecIngredients=vector<Ingredient*>();

}
Recipe::Recipe(){

    this->RecName="";
    this->RecDescription= vector<string>();
    this->RecIngredients=vector<Ingredient*>();
  //  Ingredient newIngredient =Ingredient();
}


Recipe::~Recipe(){
    delete this;
}

vector<Ingredient *> Recipe::getRecIngredients()
{
    return RecIngredients;
}

void Recipe::setRecIngredients( vector<Ingredient *> &value)
{
    RecIngredients = value;
}

vector<string> Recipe::getRecDescription()
{
    return RecDescription;
}

string Recipe::getRecName()
{
    return RecName;
}

void Recipe::addRecIngredient(string NewName, float NewQuantity, string NewUnits){

     RecIngredients.push_back(new Ingredient(NewName,NewQuantity,NewUnits));

}

void Recipe::setName(string newName){

    this->RecName=newName;
}
void Recipe::setDescription(vector<string> newDescription){

    this->RecDescription=newDescription;
}
void Recipe::printRecipe(){
    cout << "      RECIPE        "<< endl;
    cout << endl << this->RecName << endl;

    for( unsigned int a = 1; a < this->RecDescription.size(); a = a + 1 ) {

           cout << this->RecDescription[a] << endl;
    }





}
