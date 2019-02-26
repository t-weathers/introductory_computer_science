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
//#include "main.cpp"

#ifndef APT_CPP
#define APT_CPP

using namespace std;
Aptcomplex::Aptcomplex(){
  property_value = rand() % (600000 - 300000) + 300000;
  monthly_mortgage = rand() % (5000 - 1) + 1;
  mortgage_duration = property_value / monthly_mortgage;
  total_apts = rand() % (10 - 1) + 1;
  num_tenants = total_apts;
  apartments = new Tenant*[total_apts];
  for(int b = 0; b < total_apts; b++){
    apartments[b] = new Tenant;
  }
  for(int i = 0; i < total_apts;i++){
    apartments[i]->budget = rand() % (5000 - 500) + 500;
    apartments[i]->agreeNum = rand() % (5 - 1) + 1;
  }
  rent = rand() % (2000 - 500) + 500;
}
Aptcomplex::~Aptcomplex(){
  delete [] *apartments;
}
/********************************************************************
** Function: get_num_tenants()
** Description: gets number of tenants
** parameters: n/a
********************************************************************/
int Aptcomplex::get_num_tenants(){
  return num_tenants;
}
/********************************************************************
** Function: get_apartments
** Description: returns apartments array
** parameters: n/a
********************************************************************/
Tenant **Aptcomplex::get_apartments(){
  return apartments;
}
/********************************************************************
** Function: get_apartments_at()
** Description: returns apartments at an index
** parameters: n/a
********************************************************************/
Tenant *Aptcomplex::get_apartments_at(int index){
  return apartments[index];
}

#endif
