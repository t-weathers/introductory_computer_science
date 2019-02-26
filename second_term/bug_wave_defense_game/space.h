
/*#include <string>
#include <cstdlib>
#include <vector>
#include "ant.h"
#include "insect.h"
#include "bee.h"
*/
#include <vector>
#include "bee.h"
#include "ant.h"

using namespace std;

#ifndef SPACE_H
#define SPACE_H
class space{
	private:
		int index;
		vector<ant*> ants;
		int num_ants;
		vector<bee*> bees;
		int num_bees;
	public:
		space();
		~space();
		void generate_bee(bee* newbee);
		vector<ant*> get_ants();
		vector<bee*> get_bees();
		bee *get_bees_at(int index);
		ant *get_ants_at(int index);
		string get_ants_name_at(int index);
		string get_bees_name_at(int index);
		void rem_bee();
		void add_ant(ant *);
		void rem_ant();
};
#endif
