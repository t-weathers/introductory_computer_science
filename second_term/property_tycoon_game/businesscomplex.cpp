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
using namespace std;

#ifndef BUSINESS_CPP
#define BUSINESS_CPP
Businesscomplex::Businesscomplex(){
  property_value = rand() % (600000 - 400000) + 400000;
  monthly_mortgage = rand() % (5000 - 1) + 5000;
  mortgage_duration = property_value / monthly_mortgage;
  rent = 0;
  num_businesses = rand() % (5 - 1) + 1;
  rent_array = new float[num_businesses];
  for(int i = 0; i < num_businesses; i++){
    rent_array[i] = rand() % (5000 - 2000) + 2000;
  }
  offices = new Business*[num_businesses];
  for(int i = 0; i < num_businesses; i++){
    offices[i] = new Business;
  }
  for(int b = 0; b < num_businesses; b++){
    offices[b]->budget = rand() % (10000- 2000) + 2000;
    offices[b]->agreeNum = rand() % (5 - 1) + 1;
    offices[b]->turns = 0;
  }
}
Businesscomplex::~Businesscomplex(){
  for(int i =0; i < num_businesses; i++){
    delete offices[i];
  }
  delete [] offices;
}
/********************************************************************
** Function: get_num_businesses()
** Description: return number of businesses
** parameters: n/a
********************************************************************/
int Businesscomplex::get_num_businesses(){
  return num_businesses;
}
/********************************************************************
** Function: get_rent_at
** Description: returns rent at index
** parameters: int index
********************************************************************/
float Businesscomplex::get_rent_at(int index){
  return rent_array[index];
}
/********************************************************************
** Function: get_businesses_at
** Description: returns business at an index
** parameters: index
********************************************************************/
Business *Businesscomplex::get_businesses_at(int index){
  return offices[index];
}
/********************************************************************
** Function: set_rent_at
** Description: returns the rent at a certain area
** parameters: int index, and float newrent
********************************************************************/
void Businesscomplex::set_rent_at(int index,float newrent){
  rent_array[index] = newrent;
}
/********************************************************************
** Function: \print_rents()
** Description: print the rents
** parameters: n/a
********************************************************************/
void Businesscomplex::print_rents(){
  for(int i = 0; i < num_businesses; i++){
    cout<<"[#"<<i<<" $"<<get_rent_at(i)<<"] ";
  }
  cout<<endl;
}

#endif
