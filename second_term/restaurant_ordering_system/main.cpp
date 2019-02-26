#include "restaurant.h"
#include <iostream>
#include <string>
#include <cmath>
/******************************************************
** Program: bytes_pizza
** Author:Thomas Weathers
** Date: 04/29/2018
** Description: this acts as a full user and employee interface for the pizza restaurant
** Input: user input and 3 files, employee.txt, menu.txt, and restaurant_info.txt
** Output: user prompted responses with information in terminal and order file
******************************************************/
using namespace std;

int main(){
  Restaurant bytes;
  bytes.load_data();
  bytes.main_menu();
  return 0;
}
