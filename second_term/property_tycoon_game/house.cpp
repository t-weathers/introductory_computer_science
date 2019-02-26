#include <string>

#include "owner.h"
#include "house.h"
#include "aptcomplex.h"
#include "businesscomplex.h"
#include "property.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

#ifndef HOUSE_CPP
#define HOUSE_CPP
using namespace std;
House::House(){
  property_value = rand() % (600000 - 100000) + 100000;
  monthly_mortgage = rand() % (5000 - 1) + 1;
  mortgage_duration = property_value / monthly_mortgage;
  occupant = new Tenant;
  occupant->budget = rand() % (5000 - 500) + 500;
  occupant->agreeNum = rand() % (5 - 1) + 1;
  rent = rand() % (2000 - 500) + 500;
}
House::~House(){
  delete [] occupant

}
/********************************************************************
** Function: get_occupant()
** Description: returns occupant 
** parameters: n/a
********************************************************************/
Tenant *House::get_occupant(){
  return occupant;
}

#endif
