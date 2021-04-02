#include "ingredient.h"
#include <iostream>
#include <string>
using namespace std;


Ingredient::Ingredient(string NewName, float NewQuantity, string NewUnits)
{


    this->IngName= NewName;
    this->IngQuantity=NewQuantity;
    this->IngUnits=NewUnits;

}
Ingredient::Ingredient(){
    this->IngName="";
    this->IngQuantity=0.0;
    this->IngUnits="";
}

Ingredient::~Ingredient(){
    delete this;
}

string Ingredient::getIngUnits()
{
    return IngUnits;
}

float Ingredient::getIngQuantity()
{
    return IngQuantity;
}

string Ingredient::getIngName()
{
    return IngName;
}


void Ingredient::setName(string newName){
    this->IngName=newName;
}
void Ingredient::setQuantity(float newQuantity)
{
    this->IngQuantity=newQuantity;
}
void Ingredient::setUnits(string newUnits){
    this->IngUnits=newUnits;

}

