#include "restaurant.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
/****************************************
function name:is_int
Description: can tell if the string input is an integer
parameters: string a
*****************************************/
bool is_int(string a){
  int len = a.length();
  for(int i = 0; i < len; i++){
    if ((((char)(a[i]) > 57)) || ((char)(a[i]) < 48)) {
        return false;
    }
  }
  return true;
}

/****************************************
function name: stoi
Description:takes in a string to return to an int that it is
parameters: string input
*****************************************/
int stoi(string input){
        int val;
        int res = 0;
        for(int i = (input.length()-1); i >= 0; i--) {
                val = ((int) input[i]) - 48;
                res +=  val * pow(10,(input.length() - i -1));
        }
}
/****************************************
function  Restraurant()
Description:intializes to blank fields
parameters:
*****************************************/
Restaurant::Restaurant(){
  Menu();
  employees = NULL;
  week = NULL;
  name = "";
  phone = "";
  address = "";
  num_employees = 0;
  num_weeks = 0;
  num_orders = 0;
}
/****************************************
function name:Restarant
Description: sets fields to given values
parameters: Menu, employee arrau, num employees,hours array, num weeks, name, phone, address
*****************************************/
Restaurant::Restaurant(Menu menu, employee *employees,int num_employees, hours *week,int num_weeks, string name, string phone, string address){
  this->menu = menu;
  this->employees = employees;
  this->week = week;
  this->name = name;
  this->phone = phone;
  this->address = address;
  this->num_weeks = num_weeks;
  this->num_employees = num_employees;
  this->num_orders = 0;
}
/****************************************
function name:~Restaurant()
Description: destructor
parameters:
*****************************************/
Restaurant::~Restaurant(){
  if(employees != NULL)
    delete [] employees;
  if(week != NULL)
    delete [] week;
}
/****************************************
function name:operator =
Description: operator copy
parameters: const restaurant &
*****************************************/
Restaurant &Restaurant::operator =(const Restaurant &origional){
  this->menu = origional.menu;
  this->num_employees = origional.num_employees;
  if(employees != NULL){
    delete [] employees;
  }
  this->employees = new employee[this->num_employees];
  for(int b = 0; b < this->num_employees; b++){
    this->employees[b] = (origional.employees)[b];
  }
  this->num_weeks = origional.num_weeks;
  if(week != NULL){
    delete [] week;
  }
  this->week = new hours[num_weeks];
  for(int b = 0; b < num_weeks; b++){
    this->week[b] = (origional.week)[b];
  }
  this->name = origional.name;
  this->phone = origional.name;
  this->address = origional.name;

  return *this;
}
/****************************************
function name:Restaurant op overload
Description:op overload
parameters: restaurant &
*****************************************/
Restaurant::Restaurant(const Restaurant &origional){
  this->menu = origional.menu;
  this->num_employees = origional.num_employees;
  this->employees = new employee[this->num_employees];
  for(int b = 0; b < this->num_employees; b++){
    this->employees[b] = (origional.employees)[b];
  }
  this->num_weeks = origional.num_weeks;
  this->week = new hours[num_weeks];
  for(int b = 0; b < num_weeks; b++){
    this->week[b] = (origional.week)[b];
  }
  this->name = origional.name;
  this->phone = origional.name;
  this->address = origional.name;
}

//setters
/****************************************
function name:set_menu
Description: sets to new menu
parameters: menu
*****************************************/
void Restaurant::set_menu(Menu menu){
  this->menu = menu;
}
/****************************************
function name:increment_num_orders
Description: increments the number of orders
parameters: ineger a
*****************************************/
void Restaurant::increment_num_orders(int a){
  num_orders = num_orders + a;
}
/****************************************
function name:set_employees
Description: sets to new employees
parameters: employees and new length employees
*****************************************/
void Restaurant::set_employees(employee *employees,int a){
  this->employees = employees;
  this->num_employees = a;
}
/****************************************
function name:set week
Description:sets hours array
parameters: array of hours and length
*****************************************/
void Restaurant::set_num_employees(int a){
  this->num_employees = a;
}
void Restaurant::set_week(hours *week,int num){
  this->week = week;
  this->num_weeks = num;
}
/****************************************
function name:set_name
Description: sets name of restaurant
parameters: string name
*****************************************/
void Restaurant::set_name(string name){
  this->name = name;
}
/****************************************
function name:set phone
Description: sets phone num
parameters: phone num
*****************************************/
void Restaurant::set_phone(string phone){
  this->phone = phone;
}
/****************************************
function name:set_address
Description:sets address
parameters:string address
*****************************************/
void Restaurant::set_address(string address){
  this->address = address;
}
//getters

/****************************************
function name:get_menu
Description: returns menu
parameters:
*****************************************/
Menu Restaurant::get_menu(){//done
  return menu;
}
/****************************************
function name:get_num_orders
Description: returns num orders
parameters:
*****************************************/
int Restaurant::get_num_orders(){
  return num_orders;
}
/****************************************
function name:get_employees
Description: returns employees array
parameters:
*****************************************/
employee *Restaurant::get_employees(){//done
  return employees;
}
employee Restaurant::get_specific_employee(int index){
  return employees[index];
}
/****************************************
function name:get_hours
Description: returns hours array
parameters:
*****************************************/
hours *Restaurant::get_hours(){//done
  return week;
}
/****************************************
function name:get_name
Description: returns name
parameters:
*****************************************/
string Restaurant::get_name(){
  return name;
}
/****************************************
function name:get_phone
Description: returns phone num
parameters:
*****************************************/
string Restaurant::get_phone(){
  return phone;
}
/****************************************
function name:get_c_address
Description: returns address
parameters:
*****************************************/
string Restaurant::get_address(){
  return address;
}
/****************************************
function name:get_num_employees
Description: returns num employees
parameters:
*****************************************/
int Restaurant::get_num_employees(){
  return num_employees;
}
/****************************************
function name:get_num_weeks
Description: returns number of weeks
parameters:
*****************************************/
int Restaurant::get_num_weeks(){
  return num_weeks;
}
/****************************************
function name:count_lines
Description: returns number of lines in file
parameters: ifstream file
*****************************************/
int Restaurant::count_lines(ifstream &file){
  int num = 0;
  string temp;
  while(!(&file)->eof()){
    getline(file,temp);
    num++;
  }
  return num -1;
}

/****************************************
function name:main_menu
Description:loads main menu
parameters:
*****************************************/
void Restaurant::main_menu(){
  bool logout = false;
  char input;
  int choice;
  do{
    input = start_menu_print();
    if(input == 'Q'){
      logout = true;
    }
    else if(input == 'E'){
      prompt_login();
      do{
        choice = employee_menu_print();
        logout = employee_run(choice);
      }while(logout == false);
    }
    else if(input = 'C'){
      do{
        choice = customer_menu_print();
        logout = customer_run(choice);
      }while(logout == false);
    }
  }while(logout == false);
}
/****************************************
function name:start_menu_print
Description:prints starter menu
parameters:
*****************************************/
char Restaurant::start_menu_print(){
  cout<<"Welcome to Bytes Pizza"<<endl;
  char input;
  do{
    cout<<"Are you a customer(C) or employee(E) or would you like to quit(Q)?"<<endl;
    cin>>input;
  }while(input != 'E' && input != 'Q' && input != 'C');
  return input;
}
/****************************************
function name:employee_menu_print
Description:prints the employee menu and runs employee
parameters:
*****************************************/
int Restaurant::employee_menu_print(){
  string input;
  //prompt_login();
  do{
    cout<<"1. Change hours"<<endl;
    cout<<"2. View Orders"<<endl;
    cout<<"3. Remove Order"<<endl;
    cout<<"4. Add item to menu"<<endl;
    cout<<"5. Remove Item to Menu"<<endl;
    cout<<"6. View Menu"<<endl;
    cout<<"7. View Hours"<<endl;
    cout<<"8. View Address"<<endl;
    cout<<"9. View Phone"<<endl;
    cout<<"10. Log out"<<endl;
    cin>>input;
  }while(stoi(input) < 1 || stoi(input) > 10 || is_int(input) ==false);
  return stoi(input);
}
/****************************************
function name: customer_menu_print
Description: prints menu for customer
parameters:
*****************************************/
int Restaurant::customer_menu_print(){
  string input;
  do{
    cout<<"1. View Menu"<<endl;
    cout<<"2. Search by Cost"<<endl;
    cout<<"3. Search by Ingredients"<<endl;
    cout<<"4. Place Order"<<endl;
    cout<<"5. View Hours"<<endl;
    cout<<"6. View Address"<<endl;
    cout<<"7. View Phone"<<endl;
    cout<<"8. Log out"<<endl;
    cin>>input;
  }while(stoi(input) < 1 || stoi(input) > 8 || is_int(input) == false);
  return stoi(input);
}
/****************************************
function name:employee_run
Description:runs the choice function
parameters:
*****************************************/
bool Restaurant::employee_run(int choice){
  bool keepgoing = false;
  if(choice == 1){
    change_hours();
  }
  else if(choice == 2){
    view_orders();
  }
  else if(choice == 3){
    remove_orders();
  }
  else if(choice == 4){
    add_to_menu();
  }
  else if(choice == 5){
    remove_from_menu();
  }
  else if(choice == 6){
    view_menu();
  }
  else if(choice == 7){
    view_hours();
  }
  else if(choice == 8){
    view_address();
  }
  else if(choice == 9){
    view_phone();
  }
  else if(choice == 10){
    keepgoing = true;
  }
  return keepgoing;
}
/****************************************
function name:customer_run
Description:returns if the customer returns quit or not
parameters:number choice
*****************************************/
bool Restaurant::customer_run(int choice){
  bool keepgoing = false;
  if(choice == 1){
    view_menu();
  }
  else if(choice == 2){
    search_menu_by_price();
  }
  else if(choice == 3){
    search_by_ingredients();
  }
  else if(choice == 4){
    prompt_order();
  }
  else if(choice == 5){
    view_hours();
  }
  else if(choice == 6){
    view_address();
  }
  else if(choice == 7){
    view_phone();
  }
  else if(choice == 8){
    keepgoing = true;
  }
  return keepgoing;
}
/****************************************
function name:load_data
Description: takes in all the class data from files
parameters:
*****************************************/
void Restaurant::load_data(){//reads from files to correctly populate menu, employees, hours,etc.
  ifstream file;
  string temp;
  file.open("menu.txt", ifstream::in);
  if(file.is_open()){
    load_menu(file);
  }
  else{
    cout<<"file did not open"<<endl;
  }
  file.close();
  file.open("employee.txt", ifstream::in);
  if(file.is_open()){
    load_employee(file);
  }
  else{
    cout<<"file did not open"<<endl;
  }
  file.close();

  file.open("restaurant_info.txt", ifstream::in);
  if(file.is_open()){
    load_restaurant_info(file);
  }
  else{
    cout<<"file did not open"<<endl;
  }
  file.close();
}
/****************************************
function name:load_menu
Description: takes in file for menu
parameters:file
*****************************************/
void Restaurant::load_menu(ifstream &file){
  string Pizza_name;
  Menu tmenu;
  file.clear();
  file.seekg(0);
  int len = count_lines(file);
  file.clear();
  file.seekg(0);
  //get_menu().set_num_pizzas(len);
  int Small_Cost, Medium_Cost, Large_Cost, Num_Ingredients;
  Pizza *tpizzas = new Pizza[len];
  tmenu.set_num_pizzas(len);
  for (int i = 0; i < len; i++){
    file>>Pizza_name;
    tpizzas[i].set_name(Pizza_name);
    file>>Small_Cost;
    tpizzas[i].set_small_cost(Small_Cost);
    file>>Medium_Cost;
    tpizzas[i].set_medium_cost(Medium_Cost);
    file>>Large_Cost;
    tpizzas[i].set_large_cost(Large_Cost);
    file>>Num_Ingredients;
    tpizzas[i].set_num_ingredients(Num_Ingredients);
    string *Ingredients = new string[Num_Ingredients];
    for(int b = 0; b < Num_Ingredients; b++){
      file>>Ingredients[b];
    }
    tpizzas[i].set_ingredients(Ingredients);
  }
  tmenu.set_pizzas(tpizzas);
  set_menu(tmenu);
  get_menu().set_num_pizzas(len);
}
/****************************************
function name:load_employee
Description:takes in employee files
parameters:file
*****************************************/
void Restaurant::load_employee(ifstream &file){
  file.clear();
  file.seekg(0);
  int len = count_lines(file);
  file.clear();
  file.seekg(0);
  string a;
  employee *temployees = new employee[len];
  for(int i = 0; i < len; i++){
    file>>a;
    temployees[i].id = a;
    file>>a;
    temployees[i].first_name = a;
    file>>a;
    temployees[i].last_name = a;
    file>>a;
    temployees[i].password = a;

  }
  set_num_employees(len);
  set_employees(temployees,len);
}
/****************************************
function name:restaurant_info
Description: takes in restaurant_info
parameters:file
*****************************************/
void Restaurant::load_restaurant_info(ifstream &file){
  string name1,phone1,address1;
  string a,b,c;
  int num_days;
    file>>a;
    file>>b;
    name1 = a + " " + b;
    file>>a;
    file>>b;
    file>>c;
    phone1 = a + " " + b + " " + c;
    file>>a;
    file>>b;
    file>>c;
    address1 = a + " " + b + " " + c;
    set_address(address1);
    file>>num_days;
    set_name(name1);
    set_phone(phone1);
    hours *week = new hours[num_days];
    for(int i = 0; i < num_days; i++){
      file>>week[i].day;
      file>>week[i].open_hour;
      file>>week[i].close_hour;
    }
    set_week(week,num_days);
}

/****************************************
function name:prompt_login
Description:asks for login info
parameters:
*****************************************/
void Restaurant::prompt_login(){//done
  string givenID;
  string password;
  cout<<"**************************"<<endl;
  cout<<"Login"<<endl;
  do{
    cout<<"ID: ";
    cin>>givenID;
    cout<<"PASSWORD: ";
    cin>>password;
  }while(login(givenID,password) == false);

}



void Restaurant::view_employees(){
  for(int i = 0; i < get_num_employees();i++){
    cout<<get_specific_employee(i).id<<" ";
    cout<<get_specific_employee(i).first_name<<" ";
    cout<<get_specific_employee(i).last_name<<" ";
    cout<<get_specific_employee(i).password<<" ";
    cout<<"\n";
  }
}
/****************************************
function name:login
Description:returns if succesful login
parameters:string id, password
*****************************************/
bool Restaurant::login(string id, string password){//done
  //view_employees();
  for(int i = 0; i < get_num_employees(); i++){
    if(get_specific_employee(i).id == id){
      if(get_specific_employee(i).password == password){
        return true;
      }
    }
  }
  return false;
}
/****************************************
function name:view_menu
Description: prints the menu
parameters:
*****************************************/
void Restaurant::view_menu(){ //done
  cout<<"****************************************************"<<endl;
  cout<<this->get_name()<<" menu"<<endl;
  cout<<"\n";

  for(int i = 0; i < this->get_menu().get_num_pizzas();i++){
    cout<<get_menu().get_specific_pizza(i).get_name()<<endl;
    for(int b = 0; b < get_menu().get_specific_pizza(i).get_num_ingredients(); b++){
      cout<<(get_menu().get_specific_pizza(i).get_ingredients())[b];
      if(b != get_menu().get_specific_pizza(i).get_num_ingredients() - 1)
        cout<<", ";
    }
    cout<<endl;
    cout<<"SMALL: $"<<get_menu().get_specific_pizza(i).get_small_cost()<<endl;
    cout<<"MEDIUM: $"<<get_menu().get_specific_pizza(i).get_medium_cost()<<endl;
    cout<<"LARGE: $"<<get_menu().get_specific_pizza(i).get_large_cost()<<endl;
    cout<<"\n"<<endl;
  }
  cout<<"\n";
  cout<<"****************************************************"<<endl;
}
/****************************************
function name:view hours
Description: prints store hours
parameters:
*****************************************/
void Restaurant::view_hours(){ //done
  cout<<"**********************"<<endl;
  cout<<"HOURS"<<endl;
  for(int i = 0;i < get_num_weeks(); i++){
    cout<<get_hours()[i].day<<" "<<get_hours()[i].open_hour<<" "<<get_hours()[i].close_hour<<endl;
  }
  cout<<"**********************"<<endl;
}
/****************************************
function name:view_address
Description:prints address of store
parameters:
*****************************************/
void Restaurant::view_address(){//done
  cout<<"*******************************"<<endl;
  cout<<"ADDRESS"<<endl;
  cout<<this->get_address()<<endl;
  cout<<"\n";
  cout<<"*******************************"<<endl;
}
/****************************************
function name:view phone
Description: return phone num of store
parameters:
*****************************************/
void Restaurant::view_phone(){//done
  cout<<"************************"<<endl;
  cout<<"PHONE NUMBER"<<endl;
  cout<<this->get_phone()<<endl;
  cout<<"************************"<<endl;
}
/****************************************
function name:search_menu_by_price
Description:prompts to search the meny by the price
parameters:
*****************************************/
void Restaurant::search_menu_by_price(){//done
  string costinput;
  string size;
  do{
    cout<<"please provide a price you would like to search for pizzas less than: "<<endl;
    cin>>costinput;
  }while(is_int(costinput) == false || stoi(costinput) < 0);
  do{
    cout<<"please provide a size of pizza: "<<endl;
    cin>>size;
  }while(size != "medium" && size != "small" && size != "large");
  get_menu().search_pizza_by_cost(stoi(costinput),size).print_menu();
  do{
    cout<<"do you want to place an order? (1:yes 2:no)"<<endl;
    cin>>size;
  }while(stoi(size)<1 || stoi(size) > 2);
  if(stoi(size) == 1){
    this->prompt_order();
  }
  else if(stoi(size) == 0){
    return;
  }
}
/****************************************
function name:search_by_ingredients
Description:prompts to search menu by ingredients
parameters:
*****************************************/
void Restaurant::search_by_ingredients(){//done
  string input, input2,size;
  do{
    cout<<"would you like to search by including? (0) or excluding? (1)"<<endl;
    cin>>input;
  }while(stoi(input) < 0 || stoi(input) > 1 || is_int(input) == false);
  do{
    cout<<"please give the number of inclusions or exclusions you want to apply?"<<endl;
    cin>>input2;
  }while(stoi(input2) < 0 || is_int(input2) == false);
  string *output = new string[stoi(input2)];
  if(input == "0"){//including
    for(int i = 0; i < stoi(input2);i++){
      cout<<"please give an ingredient name: "<<endl;
      cin>>output[i];
    }
    get_menu().search_pizza_by_ingredients_to_include(output,stoi(input2)).print_menu();
  }
  else if(input == "1"){//excluding
    for(int i = 0; i < stoi(input2);i++){
      cout<<"please give an ingredient name: "<<endl;
      cin>>output[i];
    }
    get_menu().search_pizza_by_ingredients_to_exclude(output,stoi(input2)).print_menu();
  }
  do{
    cout<<"do you want to place an order? (1:yes 2:no)"<<endl;
    cin>>size;
  }while(stoi(size)<1 || stoi(size) > 2);
  if(stoi(size) == 1){
    this->prompt_order();
  }
  else if(stoi(size) == 0){
    return;
  }
}
/****************************************
function name:get_CC
Description: get credit card and return it
parameters:
*****************************************/
string Restaurant::get_CC(){
  string output;
  do{
    cout<<"please provide your Credit Card number"<<endl;
    cin>>output;
  }while(is_int(output) == false);
  return output;
}
/****************************************
function name:get_c_phone
Description:gets customer phone num and returns it
parameters:
*****************************************/
string Restaurant::get_c_phone(){
  string output;
  do{
    cout<<"please provide your phone number(no spaces, no dashes, no parenthesis) "<<endl;
    cin>>output;
  }while(is_int(output) == false || output.length() < 7 || output.length() > 7);
  return output;
}
/****************************************
function name:get_c_address
Description:gets customer address and returns it
parameters:
*****************************************/
string Restaurant::get_c_address(){
  string output;
  cout<<"please provide your address"<<endl;
  cin>>output;
  return output;
}
/****************************************
function name:get_c_name
Description:gets and returns customer address
parameters:
*****************************************/
string Restaurant::get_c_name(){
  string output;
  cout<<"please provide your name"<<endl;
  cin>>output;
  return output;
}
/****************************************
function name:prompt_order
Description:prompts for the user's order
parameters:
*****************************************/
void Restaurant::prompt_order(){
  view_menu();
  int tnum_pizzas;
  string name;
  int *ordernum;
  *ordernum = 0;
  bool contains = false;
  do{
    cout<<"How many Pizza's would you like to order?: "<<endl;
    cin>>tnum_pizzas;
  }while(tnum_pizzas < 1);
  Pizza *selection = new Pizza[tnum_pizzas];
  string *sizes = new string[tnum_pizzas];
  int total_price = 0;
  for(int i = 0; i < tnum_pizzas; i++){
    int b;
    do{
      cout<<"please state the name of the pizza you want: "<<i+1<<endl;
      cin>>name;
      contains = this->get_menu().contains(name);
    }while(contains == false);
    contains = false;
    selection[i] = get_menu().get_specific_pizza(i);
    do{
      cout<<"please state the size of this pizza"<<endl;
      cin>>sizes[i];
    }while(sizes[i] != "small" && sizes[i] != "medium" && sizes[i] != "large");
    if(sizes[i] == "small")
      total_price += get_menu().get_specific_pizza(i).get_small_cost();
      //total_price += get_menu().get_pizzas()[i].get_small_cost();
    else if(sizes[i] == "medium")
      total_price += get_menu().get_specific_pizza(i).get_medium_cost();
      //total_price += get_menu().get_pizzas()[i].get_medium_cost();
    else if(sizes[i] == "large")
      total_price += get_menu().get_specific_pizza(i).get_large_cost();
      //total_price += get_menu().get_pizzas()[i].get_large_cost();
  }

  string CC = get_CC();
  string phone_num = get_c_phone();
  string address = get_c_address();
  string c_name = get_c_name();
  *ordernum = *ordernum + 1;
  place_order(selection,sizes,tnum_pizzas,CC,total_price,phone_num,address,ordernum, c_name);
}
/****************************************
function name: place_order
Description: place an order from user's requests
parameters:
*****************************************/
void Restaurant::place_order(Pizza* selection, string *sizes, int len,string CC,int total, string phone, string address, int *ordernum,string name){
  cout<<"total cost: $"<<total<<endl;
  ofstream file;
  file.open ("orders.txt");
  file<<(*ordernum)<<" "<<name<<" "<<CC<<" "<<address<<" "<<phone<<" ";
  for(int i = 0; i < len; i++){
    file<<selection[i].get_name()<<" "<<sizes[i]<<endl;
  }
  file<<"\n"<<endl;
  file.close();
  increment_num_orders(1);
}
/****************************************
function name:change_hours
Description: changes the hours of the restraurant
parameters:
*****************************************/
void Restaurant::change_hours(){//done
  string a, new_open, new_close;
  int index_to_change;
  cout<<"****************************"<<endl;
  cout<<"Change Hours"<<endl;
  cout<<"\n"<<endl;
  do{
    cout<<"Please provide which day you want to change the hours of: (first letter of the day, thursday is R, sunday is SU)" <<endl;
    cin>>a;
  }while(a != "M" && a != "T" && a!= "W" && a != "R" && a != "F" && a!= "S" && a != "SU");
  for(int i = 0; i < this->get_num_weeks(); i++){
    if(a == (this->get_hours())[i].day){
      index_to_change = i;
    }
  }
  do{
    cout<<"please give a new opening time: "<<endl;
    cin>>new_open;
    cout<<"please give a new closing time: "<<endl;
    cin>>new_close;
  }while(is_int(new_open) != true && is_int(new_close) != true);
  hours *newweek = new hours[this->get_num_weeks()];
  for(int i = 0; i < this->get_num_weeks(); i++){
    if(a == (this->get_hours())[i].day){
      newweek[i].day = a;
      newweek[i].open_hour = new_open;
      newweek[i].close_hour = new_close;
    }
    else{
      newweek[i].day = (this->get_hours())[i].day;
      newweek[i].open_hour = (this->get_hours())[i].open_hour;
      newweek[i].close_hour = (this->get_hours())[i].close_hour;
    }
  }
  delete [] get_hours();
  set_week(newweek,this->get_num_weeks());
  cout<<"**************************"<<endl;


}
/****************************************
function name:add_to_menu
Description: prompts for item to add to menu
parameters:
*****************************************/
void Restaurant::add_to_menu(){//done
  string name;
  int small_cost,medium_cost,large_cost,num_ingredients;
  string *ingredients;
  cout<<"what do you want to name the pizza?: "<<endl;
  cin>>name;
  do{
    cout<<"what is the cost of a small?:" <<endl;
    cin>>small_cost;
    cout<<"what is the cost of a medium?:" <<endl;
    cin>>medium_cost;
    cout<<"what is the cost of a large?:" <<endl;
    cin>>large_cost;
  }while(small_cost < 0 || medium_cost < 0 || large_cost < 0 );
  do{
    cout<<"please give the number of ingredients"<<endl;
    cin>>num_ingredients;
  }while(num_ingredients <=  0);
  ingredients = new string[num_ingredients];
  for(int i = 0; i < num_ingredients; i++){
    cout<<"ingredient "<<i<<": "<<endl;
    cin>>ingredients[i];
  }
  Pizza newpizza(name,small_cost,medium_cost,large_cost,num_ingredients,ingredients);
  //this->get_menu().add_to_menu(newpizza);
  Menu temp;
  temp = get_menu().add_to_menu(newpizza);
  this->set_menu(temp);
}
/****************************************
function name:remove_from_menu
Description:removes an item from the menu
parameters:
*****************************************/
void Restaurant::remove_from_menu(){//done
  string a;
  int index = 0;
  cout<<"please give the name of the pizza you would like to remove"<<endl;
  cin>>a;
  for(int i = 0; i < get_menu().get_num_pizzas(); i++){

    cout<<"name: "<<get_menu().get_specific_pizza(i).get_name()<<endl;
    if(get_menu().get_specific_pizza(i).get_name() == a){
      index = i;
    }
  }
  Menu temp;
  temp = get_menu().remove_from_menu(index);
  this->set_menu(temp);
}
/****************************************
function name: view_orders
Description: prints the orders that are present
parameters:
*****************************************/
void Restaurant::view_orders(){//done
  ifstream file;
  string input;
  file.open("orders.txt");
  if(file.is_open()){
        while(!file.eof()){
            file>>input;
            cout<<input<<" ";
        }
        cout<<endl;
  }
  else{
    cout<<"file did not open"<<endl;
  }
  file.close();
}
/****************************************
function name:remove_orders
Description: removes order from list and reprints the rest
parameters:
*****************************************/
void Restaurant::remove_orders(){//done
  int order_to_remove;
  cout<<"what order number would you like to remove?:"<<endl;
  cin>>order_to_remove;
  ifstream file;
  file.open ("orders.txt");
  string *saved = new string[get_num_orders()];
  int *ordernums = new int[get_num_orders()];
  for(int i = 0; i < get_num_orders(); i++){
    file>>ordernums[i];
    getline(file,saved[i],'\n');
  }
  file.close();
  file.open("orders.txt",ios::trunc);
  file.close();
  increment_num_orders(-1);
  ofstream fileout;
  fileout.open("orders.txt");
  for(int i = 0; i < get_num_orders(); i++){
    if(ordernums[i] != order_to_remove){
      fileout<<ordernums[i]<<" "<<saved[i]<<endl;
    }
  }
  fileout.close();
  delete [] saved;
  delete [] ordernums;
}
