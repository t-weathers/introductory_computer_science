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
/******************************************************
** Program: real-estate tycoon
** Author:Thomas Weathers
** Date: 05/13/2018
** Description: this is a tycoon game for real estate agents to buy and sell and try to make profit
** Input: user prompted rent and buying options
** Output: returns the game board and the options for the user
******************************************************/

using namespace std;

#ifndef MAIN_CPP
#define MAIN_CPP

int main(){
	srand(time(NULL));
	Owner runner;
	runner.run_game();
	return 0;

}
#endif
