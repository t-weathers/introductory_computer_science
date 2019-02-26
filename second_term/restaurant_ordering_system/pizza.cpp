#include "pizza.h"
#include <string>
#include <iostream>

using namespace std;
//constructors
/****************************************
function name: Pizza()
Description:pizza constuctor
parameters:
*****************************************/
Pizza::Pizza(){
  name = "";
  small_cost = 0;
  medium_cost = 0;
  large_cost = 0;
  num_ingredients = 0;
  ingredients = NULL;
}
/****************************************
function name:pizza()
Description:non-default constructor
parameters: name, small cost, medium cost, large cost, num ingredients, string of ingredients
*****************************************/
Pizza::Pizza(string name, int small_cost, int medium_cost, int large_cost, int num_ingredients, string *ingredients){
  this->name = name;
  this->small_cost = small_cost;
  this->medium_cost = medium_cost;
  this->large_cost = large_cost;
  this->num_ingredients = num_ingredients;
  this->ingredients = ingredients;
}
/****************************************
function name:~Pizza
Description:Pizza destructor
*****************************************/
Pizza::~Pizza(){
  delete [] ingredients;
}
/****************************************
function name:operator =
Description:operator copy
parameters: const Pizza &
*****************************************/
Pizza &Pizza::operator =(const Pizza &origional){
  this->name = origional.name;
  this->small_cost = origional.small_cost;
  this->medium_cost = origional.medium_cost;
  this->large_cost = origional.large_cost;
  this->num_ingredients = origional.num_ingredients;
  if(this->ingredients != NULL){
    delete [] this->ingredients;
  }
  if(num_ingredients == 0){
    ingredients = NULL;
  }
  else{
    this->ingredients = new string[this->num_ingredients];
    for(int i = 0; i < this->num_ingredients; i++){
      this->ingredients[i] = origional.ingredients[i];
    }
  }
  return *this;
}

/****************************************
function name:Pizza()
Description: operator copies over
parameters: const Pizza &
*****************************************/
Pizza::Pizza(const Pizza &origional){
  this->name = origional.name;
  this->small_cost = origional.small_cost;
  this->medium_cost = origional.medium_cost;
  this->large_cost = origional.large_cost;
  this->num_ingredients = origional.num_ingredients;
  if(num_ingredients == 0){
    ingredients = NULL;
  }
  else{
    this->ingredients = new string[this->num_ingredients];
    for(int i = 0; i < this->num_ingredients; i++){
      this->ingredients[i] = origional.ingredients[i];
    }
  }
}

//getters
/****************************************
function name:get_name
Description: returns name
parameters:
*****************************************/
string Pizza::get_name()const{
  return name;
}
/****************************************
function name:get_small_cost
Description:returns cost of a small
parameters:
*****************************************/
int Pizza::get_small_cost()const{
  return small_cost;
}
/****************************************
function name: get_medium_cost
Description: returns cost of a medium
parameters:
*****************************************/
int Pizza::get_medium_cost()const{
  return medium_cost;
}
/****************************************
function name: returns cost of a large_cost
Description: returns cost of a large
parameters:
*****************************************/
int Pizza::get_large_cost()const{
  return large_cost;
}
/****************************************
function name: returns num of ingredients
Description: returns num of ingredients
parameters:
*****************************************/
int Pizza::get_num_ingredients()const{
  return num_ingredients;
}
/****************************************
function name: get_ingredients
Description: returns ingredients
parameters:
*****************************************/
string *Pizza::get_ingredients()const{
  return ingredients;
}
//setters
/****************************************
function name: set name
Description: sets name of pizza
parameters:string name
*****************************************/
void Pizza::set_name(string name){
  this->name = name;
}
/****************************************
function name: set small cost
Description: sets cost of small pizza
parameters:int cost
*****************************************/
void Pizza::set_small_cost(int cost){
  small_cost = cost;
}
/****************************************
function name: set medium_cost
Description: sets cost of medium
parameters:int cost
*****************************************/
void Pizza::set_medium_cost(int cost){
  medium_cost = cost;
}
/****************************************
function name: set large_cost
Description: sets cost of a large
parameters:int cost
*****************************************/
void Pizza::set_large_cost(int cost){
  large_cost = cost;
}
/****************************************
function name: set num_ingredients
Description: sets number of ingredients
parameters: int number
*****************************************/
void Pizza::set_num_ingredients(int num){
  num_ingredients = num;
}
/****************************************
function name: set_ingredients
Description: sets new array of ingredients
parameters: string list of ingredients
*****************************************/
void Pizza::set_ingredients(string *list){
  ingredients = list;
}
