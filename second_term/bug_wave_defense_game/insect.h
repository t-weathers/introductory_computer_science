#include <string>
//#include "space.h"


using namespace std;

#ifndef INSECT_H
#define INSECT_H
class insect{
	protected:
		int *armor;
		int *location;//0-9
	public:
		insect();
		~insect();
		virtual int get_armor();
		void set_armor(int input);
		int get_location();
		void set_location(int input);
		virtual void action() = 0;
};
#endif
