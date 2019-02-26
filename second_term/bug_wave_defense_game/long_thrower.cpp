#include "long_thrower.h"
using namespace std;

/********************************************************************
** Function: long_thrower
** Description: this initializes the long thrower ant class
** parameters: int location
********************************************************************/
long_thrower::long_thrower(int location){
  *food_cost = 3;
  *armor = 1;
  *(this->location) = location;
  *name = "long_thrower";
}
void long_thrower::action(){

}
