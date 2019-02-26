#include "pizza.h"
#include <string>
#include <iostream>
#ifndef MENU_H
#define MENU_H
using namespace std;

class Menu {
  private:
    int num_pizzas;
    Pizza* pizzas;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //constructors
    Menu();
    Menu(int num_pizzas, Pizza *pizzas);
    ~Menu();
    Menu(const Menu &origional);
    Menu &operator =(const Menu &origional);
    //getters
    int get_num_pizzas(); //const
    Pizza *get_pizzas()const;
    Pizza get_specific_pizza(int index);
    //setters
    void set_num_pizzas(int);
    void set_pizzas(Pizza *);
    //other
    void print_menu();
    Menu search_pizza_by_cost(int upper_bound, string size);
    Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
    Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
    Menu add_to_menu(Pizza pizza_to_add);//add to menu and update num pizzas
    Menu remove_from_menu(int index_of_pizza_on_menu);
    bool contains(string name);
};
#endif
