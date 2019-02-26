#include "wall.h"
using namespace std;

/********************************************************************
** Function: wall()
** Description: this initializes the fields of wall class
** parameters: int location
********************************************************************/
wall::wall(int location){
  *food_cost = 4;
  *armor = 4;
  *(this->location) = location;
  *name = "wall";
}
void wall::action(){

}
