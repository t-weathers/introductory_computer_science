#include "short_thrower.h"
using namespace std;

/********************************************************************
** Function: short_thrower()
** Description: this initializes the short_thrower class fields
** parameters: int location
********************************************************************/
short_thrower::short_thrower(int location){
  *food_cost = 3;
  *armor = 1;
  *(this->location) = location;
  *name = "short_thrower";
}
void short_thrower::action(){

}
