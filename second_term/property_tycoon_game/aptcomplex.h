#include "property.h"


using namespace std;
#ifndef APTCOMPLEX_H
#define APTCOMPLEX_H
class Aptcomplex : public Property{
protected:
		Tenant **apartments;
		int num_tenants;
		int total_apts;
		//inherit mortgage
		//inherit rent
	public:
		Aptcomplex();
		~Aptcomplex();
		int get_num_tenants();
		Tenant **get_apartments();
		Tenant *get_apartments_at(int index);
};
#endif
