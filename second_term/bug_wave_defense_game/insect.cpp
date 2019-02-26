#include "insect.h"

using namespace std;
/********************************************************************
** Function: insect()
** Description: initializes the fileds of the insect class
** parameters: n/a
********************************************************************/
insect::insect(){
  armor = new int;
  location  = new int;
}
/********************************************************************
** Function: ~insect()
** Description: this deletes the items on the heap of Insect
** parameters: n/a
********************************************************************/
insect::~insect(){
  delete armor;
  delete location;
}
/********************************************************************
** Function: get_armor()
** Description: returns integer of the armor
** parameters: n/a
********************************************************************/
int insect::get_armor(){
  return *armor;
}
/********************************************************************
** Function: set_armor
** Description: sets the new armor to a custom
** parameters: int input
********************************************************************/
void insect::set_armor(int input){
  *armor = input;
}
/********************************************************************
** Function: get_location
** Description: returns location
** parameters: n/a
********************************************************************/
int insect::get_location(){
  return *location;
}
/********************************************************************
** Function: set_location
** Description: sets the new location
** parameters: integer input of new location
********************************************************************/
void insect::set_location(int input){
  *location = input;
}
