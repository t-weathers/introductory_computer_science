#include "ant.h"
#include "bee.h"
#include "bodyguard.h"
#include "fire.h"
#include "harvester.h"
#include "insect.h"
#include "long_thrower.h"
#include "ninja.h"
#include "short_thrower.h"
#include "space.h"
#include "thrower.h"
#include "wall.h"


using namespace std;

#ifndef GAME_H
#define GAME_H
class game{
	private:
		int *colony_food;
		space *spaces;
		int num_bees;
		int num_ants;

	public:
		game();
		~game();
		void run_game();
		void prompt_input();
		void all_bee_turn();
		void all_ant_turn();
		bool prompt_repeat();
		bool space_left_open_ant(int start_bee);
		void determine_ant(int num, int a);
		void print_board();
		bool valid_move(int name, int location);
		bool game_over();
		void flight_of_the_bumblebee(int i );

};
#endif
