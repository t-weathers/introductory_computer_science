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

#ifndef PROP_CPP
#define PROP_CPP
using namespace std;
/********************************************************************
** Function:initialize_location()
** Description:initializes the random locations for the properties
** parameters:n/a
********************************************************************/
void Property::initialize_location(){
  int num = rand() % 5;
  if(num == 0){
    location = "NW";
  }
  else if(num == 1){
    location = "MW";
  }
  else if(num == 2){
    location = "NE";
  }
  else if (num  == 3){
    location = "SE";
  }
  else if(num  == 4){
    location = "SW";
  }
}
/********************************************************************
** Function:get_value
** Description: getter for property value
** parameters:n/a
********************************************************************/
float Property::get_value(){
  return property_value;
}
/********************************************************************
** Function: get_location()
** Description: gets the location of property
** parameters:n/a
********************************************************************/
string Property::get_location(){
  return location;
}
/********************************************************************
** Function: modify_value()
** Description: modifies value of a property
** parameters:n/a
********************************************************************/
void Property::modify_value(float percent){
  property_value = property_value * percent;
}
/********************************************************************
** Function:get_mortgage()
** Description:gets mortgage of a property
** parameters:n/a
********************************************************************/
float Property::get_mortgage(){
  return monthly_mortgage;
}
/********************************************************************
** Function: get_mortgage_duration()
** Description: returns duration of mortgage on property
** parameters:n/a
********************************************************************/
int Property::get_mortgage_duration(){
  return mortgage_duration;
}
/********************************************************************
** Function: set_rent()
** Description: changes rent to new value
** parameters:float new rent
********************************************************************/
void Property::set_rent(float newrent){
  this->rent = newrent;
}
/********************************************************************
** Function: get_propTax()
** Description:returns the constant property tax
** parameters:n/a
********************************************************************/
float Property::get_propTax(){
  return propTax;
}

float Property::get_rent()const{
  return rent;
}


bool operator <(const Property & one, const Property &two){
	bool output = false;
	if(one.get_rent() < two.get_rent()){
		output = true; 
	}
	return output;
}
bool operator >(const Property & one, const Property & two){
	bool output = false;
	if(one.get_rent() > two.get_rent()){
		output = true;
	}
	return output;
}

Property::Property(){
  initialize_location();
  propTax = 0.015;
  //mortgage is initialized individually because need prop value first
}
////Property::~Property(){
//}

#endif
