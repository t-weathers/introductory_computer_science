//#include "space.h"
#include "insect.h"
using namespace std;

#ifndef BEE_H
#define BEE_H
class bee: public insect{
	protected:
		//none
	public:
		bee();
		void action();
};
#endif
