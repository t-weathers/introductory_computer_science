#include "house.h"
#include "aptcomplex.h"
#include "businesscomplex.h"
#include "property.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;
#ifndef OWNER_H
#define OWNER_H
class Owner{
	protected:
		float wallet;
		House *houses;
		int num_houses;
		Aptcomplex *apts;
		int num_apts;
		Businesscomplex *businesses;
		int num_businesses;
		int total_properties;
		int num_turn;
	public:
		Owner();
		~Owner();
		void run_game();
		void natural_disaster();
		void hurricane();
		void tornado();
		void earthquake();
		void wildfire();
		void stock_market_crash();
		void gentrification();
		void pay_property_tax();
		void pay_mortgages();
		void collect_rent();
		void collect_house_rent();
		void collect_apts_rent();
		void collect_business_rent();
		void print_properties_w_rent();
		void change_rent();
		void change_apt_rent();
		void change_house_rent();
		void change_business_rent();
		void buy_property(House *house_market,int *len1, Businesscomplex *business_market,int *len2, Aptcomplex *apt_market,int *len3);
		int * print_properties_on_market(House *house_market,int *len1, Businesscomplex *business_market,int *len2, Aptcomplex *apt_market,int *len3);
		bool prompt_buy_property();
		bool able_to_sell(string type, int index1);
		bool prompt_to_sell();
		void sell_property();
		int randomize_number(int a, int b);
		float stof(string input);
		bool is_float(string a);
		int stoi(string i);
		bool is_int(string a);
};
#endif
