#include <string>
#include <iostream>
#include "menu.h"
#include <cmath>

#ifndef RESTAURANT_H
#define RESTAURANT_H

using namespace std;
struct employee {
  string id;
  string first_name;
  string last_name;
  string password;
};
struct hours {
  string day;
  string open_hour;
  string close_hour;
};
class Restaurant {
  private:
    Menu menu;
    employee* employees;
    hours* week;
    string name;
    string phone;
    string address;
    int num_employees;
    int num_weeks;
    int num_orders;
  public:
    //constructors
    Restaurant();
    Restaurant(Menu menu, employee *employees,int num_employees, hours *week,int num_weeks, string name, string phone, string address);
    ~Restaurant();
    Restaurant &operator=(const Restaurant &origional);
    Restaurant(const Restaurant &origional);
    //setters
    void set_num_employees(int a);
    void set_menu(Menu menu);
    void increment_num_orders(int a);
    void set_employees(employee *employees, int num_employees);
    void set_week(hours *week, int num_weeks);
    void set_name(string name);
    void set_phone(string phone);
    void set_address(string address);
    //getters
    Menu get_menu();
    employee get_specific_employee(int index);
    employee *get_employees();
    int get_num_employees();
    hours *get_hours();
    string get_name();
    string get_phone();
    string get_address();
    int get_num_weeks();
    int get_num_orders();
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    void main_menu();
    int count_lines(ifstream &file);
    char start_menu_print();
    int employee_menu_print();
    int customer_menu_print();
    bool employee_run(int choice);
    bool customer_run(int choice);
    void load_data(); //reads from files to correctly populate menu, employees, hours,etc.
    void load_menu(ifstream &file);
    void load_employee(ifstream &file);
    void load_restaurant_info(ifstream &file);
    void prompt_login();
    bool login(string id, string password);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void view_employees();
    void search_menu_by_price();
    void search_by_ingredients();
    string get_CC();
    string get_c_phone();
    string get_c_address();
    string get_c_name();
    void prompt_order();
    void place_order(Pizza* selection, string *sizes, int len,string CC,int total, string phone, string address, int *ordernum,string name);
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();
  };
  #endif
