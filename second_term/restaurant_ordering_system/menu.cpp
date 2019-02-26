#include "menu.h"
#include <iostream>
#include <string>
using namespace std;
/****************************************
function name:Menu()
Description:constructor for Menu class default
*****************************************/
Menu::Menu(){
  num_pizzas = 0;
  pizzas = NULL;
}
/****************************************
function name:Menu()
Description: returns menu
parameters: num_pizzas, pizza array
*****************************************/
Menu::Menu(int num_pizzas, Pizza *pizzas){
  this->num_pizzas = num_pizzas;
  this->pizzas = pizzas;
}
/****************************************
function name:~Menu
Description:menu destructor
*****************************************/
Menu::~Menu(){
  //out<<"called menu destructor"<<endl;
  delete [] pizzas;
}
//getters
/****************************************
function name:get_num_pizzas()
Description:returns number of pizzas
*****************************************/
Menu &Menu::operator =(const Menu &origional){
  this->num_pizzas = origional.num_pizzas;
  if(this->pizzas != NULL){
    delete [] this->pizzas;
  }
  if(this->num_pizzas == 0){
    this->pizzas = NULL;
  }
  else{
    pizzas = new Pizza[this->num_pizzas];
    for(int i = 0; i < this->num_pizzas;i++){
      this->pizzas[i] = origional.pizzas[i];
    }
  }
  return *this;
}
Menu::Menu(const Menu &origional){
  this->num_pizzas = origional.num_pizzas;
  if(this->num_pizzas == 0){
    this->pizzas = NULL;
  }
  else{
    pizzas = new Pizza[this->num_pizzas];
    for(int i = 0; i < this->num_pizzas;i++){
      this->pizzas[i] = origional.pizzas[i];
    }
  }
}

int Menu::get_num_pizzas(){//const
  return num_pizzas;
}
/****************************************
function name:get_pizzas
Description: returns pizzas field
*****************************************/
Pizza * Menu::get_pizzas()const{
  return pizzas;
}

Pizza Menu::get_specific_pizza(int index){
  return pizzas[index];
}
//setters
/****************************************
function name:set_num_pizzas
Description:sets number of pizzas to new
parameters: int number
*****************************************/
void Menu::set_num_pizzas(int num){
  num_pizzas = num;
}
/****************************************
function name:set_pizzas
Description:sets new pointer of pizzas
parameters: pizza *pizzas
*****************************************/
void Menu::set_pizzas(Pizza *pizzas){
  this->pizzas = pizzas;
}
//other
/****************************************
function name:search_pizza_by_cost
Description: returns menu of ones under cost
parameters: upper bound, size of pizza
*****************************************/
Menu Menu::search_pizza_by_cost(int upper_bound, string size){//done
  Menu updated;
  if(size == "medium"){
    for(int i = 0; i < this->get_num_pizzas();i++){
        if(get_specific_pizza(i).get_medium_cost() < upper_bound){
          updated = add_to_menu(get_specific_pizza(i));
        }
      }
    }
  else if(size == "small"){
    for(int i = 0; i < this->get_num_pizzas();i++){
        if(get_specific_pizza(i).get_small_cost() < upper_bound){
          updated = add_to_menu(get_specific_pizza(i));
        }
      }
  }
  else if(size == "large"){
    for(int i = 0; i < this->get_num_pizzas();i++){
        if(get_specific_pizza(i).get_large_cost() < upper_bound){
          updated = add_to_menu(get_specific_pizza(i));
        }
      }
  }
  return updated;
}
/****************************************
function name:search_pizza_by_ingredients_to_include
Description:returns menu of ingredients including choices
parameters: ingredients and length
*****************************************/
Menu Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients){//done
  Menu updated;
  int count = 0;
  for(int i = 0; i < this->get_num_pizzas(); i++){
    for(int b = 0; b < get_specific_pizza(i).get_num_ingredients(); b++){
      for(int a = 0; a < num_ingredients; a++){
        if(get_specific_pizza(i).get_ingredients()[b] == ingredients[a]){
          count++;
        }
      }
    }
    if(count == num_ingredients){
      updated = updated.add_to_menu(get_specific_pizza(i));
    }
    count = 0;
  }
  return updated;
}
/****************************************
function name:search_pizza_by_ingredients_to_exclude
Description:returns menu of ingredients excluding choices
parameters: ingredients and length
*****************************************/
Menu Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients){//done
  Menu updated;
  bool contains = false;
  for(int i = 0; i < this->get_num_pizzas(); i++){ //
    for(int b = 0; b < get_specific_pizza(i).get_num_ingredients(); b++){
      for(int a = 0; a < num_ingredients; a++){
        if(get_specific_pizza(i).get_ingredients()[b] == ingredients[a]){
          contains = true;
        }
      }

    }
    if(contains != true){
      updated = updated.add_to_menu(get_specific_pizza(i));
    }
    contains = false;
  }
  return updated;

}
/****************************************
function name:print_menu
Description:prints the menu
parameters:
*****************************************/
void Menu::print_menu(){//done
  cout<<"****************************************************"<<endl;
  cout<<"menu"<<endl;
  cout<<"\n";
  for(int i = 0; i < this->get_num_pizzas();i++){
    cout<<get_specific_pizza(i).get_name()<<endl;
    for(int b = 0; b < get_specific_pizza(i).get_num_ingredients(); b++){
      cout<<(get_specific_pizza(i).get_ingredients())[b];
      if(b != get_specific_pizza(i).get_num_ingredients() - 1)
        cout<<", ";
    }
    cout<<endl;
    cout<<"SMALL: $"<<get_specific_pizza(i).get_small_cost()<<endl;
    cout<<"MEDIUM: $"<<get_specific_pizza(i).get_medium_cost()<<endl;
    cout<<"LARGE: $"<<get_specific_pizza(i).get_large_cost()<<endl;
    cout<<"\n"<<endl;
  }
  cout<<"\n";
  cout<<"****************************************************"<<endl;
}
/****************************************
function name: add_to_menu
Description: adds a pizza to the menu
parameters: pizza to add
*****************************************/
Menu Menu::add_to_menu(Pizza pizza_to_add){ //
  Menu tMenu;
  Pizza *Pizzas = new Pizza[get_num_pizzas() + 1];
  for(int i = 0; i < get_num_pizzas(); i++){
    Pizzas[i] = get_pizzas()[i];
  }
  Pizzas[get_num_pizzas()] = pizza_to_add;
  tMenu.set_num_pizzas(get_num_pizzas() + 1);
  tMenu.set_pizzas(Pizzas);
  return tMenu;
}
/****************************************
function name:remove_from_menu
Description:removes pizza from menu
parameters: indexs of pizza to remove
*****************************************/
Menu Menu::remove_from_menu(int index_of_pizza_on_menu){//done
  Menu output;
  Pizza *temp = new Pizza[get_num_pizzas() - 1];
  int b = 0;
  for(int i = 0; i < get_num_pizzas(); i++){
    if(i != index_of_pizza_on_menu){
      temp[b] = get_specific_pizza(i);
      b++;
    }
  }
  output.set_num_pizzas(this->get_num_pizzas() - 1);
  output.set_pizzas(temp);
  return output;
}

bool Menu::contains(string name){
  for(int i = 0; i < this->num_pizzas; i++){
    if(this->pizzas[i].get_name() == name){
      return true;
    }
  }
  return false;
}
