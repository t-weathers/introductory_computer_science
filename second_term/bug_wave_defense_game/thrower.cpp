#include "thrower.h"
using namespace std;

/********************************************************************
** Function: thrower()
** Description: intializes the trhower class fields
** parameters: int location
********************************************************************/
thrower::thrower(int location){
  *food_cost = 4;
  *armor = 1;
  *(this->location) = location;
  *name = "thrower";
}
void thrower::action(){

}
