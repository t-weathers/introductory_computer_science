#include <string>
#include <iostream>
#ifndef PIZZA_H
#define PIZZA_H

using namespace std;

class Pizza {
  private:
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    string *ingredients;
  public:
    //constructors
    Pizza();
    Pizza(string name, int small_cost, int medium_cost, int large_cost, int num_ingredients, string *ingredients);
    Pizza &operator =(const Pizza &origional);
    ~Pizza();
    Pizza(const Pizza &origional);
    //getters
    string get_name()const;
    int get_small_cost()const;
    int get_medium_cost()const;
    int get_large_cost()const;
    int get_num_ingredients()const;
    string *get_ingredients()const;
    //setters
    void set_name(string);
    void set_small_cost(int);
    void set_medium_cost(int);
    void set_large_cost(int);
    void set_num_ingredients(int);
    void set_ingredients(string *);
    //deconstructor
    //~Pizza();
};
#endif
