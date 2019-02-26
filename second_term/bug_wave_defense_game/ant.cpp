#include "ant.h"
using namespace std;

/********************************************************************
** Function: ant()
** Description: sets the starting values of ant
** parameters: n/a
********************************************************************/
ant::ant(){
  food_cost = new int;
  name = new string;
  *name = "ant";
}
/********************************************************************
** Function: ~ant()
** Description: deletes the members of the ant class
** parameters: n/a
********************************************************************/
ant::~ant(){
  delete food_cost;
  delete name;
}
/********************************************************************
** Function: get_food_cost
** Description: returns the food cost
** parameters: n/a
********************************************************************/
int ant::get_food_cost(){
  return *food_cost;
}
/********************************************************************
** Function: set_food_cost
** Description: sets the cost of the food of the ant
** parameters: integer new cost
********************************************************************/
void ant::set_food_cost(int cost){
  *food_cost = cost;
}

void ant::action(){

}
/********************************************************************
** Function: set_name
** Description: sets the new name of the ant
** parameters: string new name
********************************************************************/
void ant::set_name(string input){
  *name = input;
}
/********************************************************************
** Function: get_name
** Description: returns name of the string
** parameters: n/a
********************************************************************/
string ant::get_name(){
  return *name;
}
/********************************************************************
** Function: decrement_armor
** Description: decreases the armor of the ant
** parameters: n/a
********************************************************************/
void ant::decrement_armor(){
  *armor = *armor - 1;
}
