#include "bodyguard.h"
using namespace std;

/********************************************************************
** Function: bodyguard
** Description: initializes the bodyguard class with the starting fields
** parameters: int location
********************************************************************/
bodyguard::bodyguard(int location){
  *food_cost = 4;
  *armor = 2;
  *(this->location) = location;
  *name = "bodyguard";
}
void bodyguard::action(){

}
