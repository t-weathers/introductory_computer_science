#include "property.h"
using namespace std;
#ifndef HOUSE_H
#define HOUSE_H
class House : public Property{
protected:
		Tenant *occupant;
	public:
		House();
		~House();
		Tenant *get_occupant();
};
#endif
