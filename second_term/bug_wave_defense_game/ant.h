#include "insect.h"
using namespace std;

#ifndef ANT_H
#define ANT_H
class ant: public insect{
	protected:
		int *food_cost;
		string *name;
	public:
		ant();
		~ant();
		virtual void action();
		int get_food_cost();
		void set_food_cost(int cost);
		void set_name(string input);
		string get_name();
		void decrement_armor();
};
#endif
