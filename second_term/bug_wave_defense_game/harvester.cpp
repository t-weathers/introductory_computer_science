#include "harvester.h"
#include <iostream>
using namespace std;

/********************************************************************
** Function: harvester()
** Description: this initializes the fields of the harvester class
** parameters: index of the space
********************************************************************/
harvester::harvester(int index){
  *food_cost = 2;
  *armor = 2;
  *(this->location) = index;
  *name = "harvester";
}
void harvester::action(){

}
