#include "space.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

/********************************************************************
** Function: space()
** Description: this initializes the space class
** parameters: n/a
********************************************************************/
space::space(){
  vector<ant *> temp;
  ants = temp;
  vector<bee *> temp2;
  bees = temp2;
  num_ants = 0;
  num_bees = 0;
}
/********************************************************************
** Function: ~space()
** Description: this deletes the space fields
** parameters: n/a
********************************************************************/
space::~space(){
  ants.clear();
  bees.clear();

}
/********************************************************************
** Function: generate_bee()
** Description: creates a new bee in the bee vector
** parameters: bee pointer new bee
********************************************************************/
void space::generate_bee(bee *newbee){
    bees.push_back(newbee);
}
/********************************************************************
** Function: get_ants()
** Description: returns the vector ant pointer ants
** parameters: n/a
********************************************************************/
vector<ant*> space::get_ants(){
  return ants;
}
/********************************************************************
** Function: get_bees()
** Description: returns the vector bee pointer bees
** parameters: n/a
********************************************************************/
vector<bee*> space::get_bees(){
  return bees;
}
/********************************************************************
** Function: get_bees_at()
** Description: returns the bee array at index
** parameters: int index
********************************************************************/
bee *space::get_bees_at(int index){
  return bees[index];
}
/********************************************************************
** Function: get_ants_at()
** Description: returns ant array at index
** parameters: int index
********************************************************************/
ant *space::get_ants_at(int index){
  return ants[index];
}
/********************************************************************
** Function: rem_bee
** Description: removes a bee from the bee vector
** parameters: n/a
********************************************************************/
void space::rem_bee(){
  bees.pop_back();
}
/********************************************************************
** Function: add_ant()
** Description: this adds an ant to to the ant vector
** parameters: ant pointer new
********************************************************************/
void space::add_ant(ant *newant){
  ants.push_back(newant);
}
/********************************************************************
** Function: rem_ant()
** Description: this removes an ant from the ant vector
** parameters: n/a
********************************************************************/
void space::rem_ant(){
  ants.erase(ants.begin());
}
/********************************************************************
** Function: get_ants_name_at
** Description: returns name of ant at index
** parameters: int index
********************************************************************/
string space::get_ants_name_at(int index){
  return ants[index]->get_name();
}
/********************************************************************
** Function: get_bees_name_at
** Description: reutnrs name "bee"
** parameters: int index
********************************************************************/
string space::get_bees_name_at(int index){
  return "bee";
}
