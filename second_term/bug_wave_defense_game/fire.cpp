#include "fire.h"
using namespace std;

/********************************************************************
** Function: fire
** Description: initializes the fire class 
** parameters: int location
********************************************************************/
fire::fire(int location){
  *food_cost = 4;
  *armor = 1;
  *(this->location) = location;
  *name = "fire";
}
void fire::action(){

}
