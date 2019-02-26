#include "ninja.h"
using namespace std;

/********************************************************************
** Function: ninja()
** Description: this initializes the ninja class fields
** parameters: int location
********************************************************************/
ninja::ninja(int location){
  *food_cost = 6;
  *armor = 1;
  *(this->location) = location;
  *name = "ninja";
}
void ninja::action(){

}
