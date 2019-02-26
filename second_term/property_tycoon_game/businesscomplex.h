#include "property.h"

using namespace std;
#ifndef BUSINESSCOMPLEX_H
#define BUSINESSCOMPLEX_H
class Businesscomplex : public Property{
	protected:
		Business **offices;
		int num_businesses;
		float *rent_array;
		//inherited mortgage
	public:
		Businesscomplex();
		~Businesscomplex();
		int get_num_businesses();
		float get_rent_at(int index);
		Business *get_businesses_at(int index);
		void set_rent_at(int index, float newrent);
		void print_rents();
};
#endif
