#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

/****************************************
function name:is_int
Description: can tell if the string input is an integer
parameters: string a
*****************************************/
bool is_int(string a){
  int len = a.length();
  for(int i = 0; i < len; i++){
    if ((((char)(a[i]) > 57)) || ((char)(a[i]) < 48)) {
        return false;
    }
  }
  return true;
}

/****************************************
function name: stoi
Description:takes in a string to return to an int that it is
parameters: string input
*****************************************/
int stoi(string input){
        int val;
        int res = 0;
        for(int i = (input.length()-1); i >= 0; i--) {
                val = ((int) input[i]) - 48;
                res +=  val * pow(10,(input.length() - i -1));
        }
}

/********************************************************************
** Function: prompt_repeat
** Description: returns boolean of wnat to place ant or not
** parameters: n/a
********************************************************************/
bool game::prompt_repeat(){
  string input;
  do{
    cout<<"would you like to place an ant? (1:yes  2:no)"<<endl;
    cin>>input;
  }while(is_int(input) == false || stoi(input) < 1 || stoi(input) > 2);
  if(stoi(input) == 1){
    return true;
  }
  else{
    return false;
  }
}

/********************************************************************
** Function: prompt_input
** Description: this prompts what the user wants to place and if its valid
** parameters: n/a
********************************************************************/
void game::prompt_input(){
  string input_ant;
  string intput_location;
  do{
    do{
      do{
        cout<<"what ant would you like to place?"<<endl;
        cout<<"1. Harvester FC: 2 Armor: 1"<<endl;
        cout<<"2. Thrower FC:4 Armor:1"<<endl;
        cout<<"3. Fire FC: 4 Armor: 1"<<endl;
        cout<<"4. Long Thrower FC: 3 Armor: 1 "<<endl;
        cout<<"5. Short Thrower FC: 3 Armor: 1 "<<endl;
        cout<<"6. Wall FC: 4 Armor: 4 "<<endl;
        cout<<"7. Ninja FC: 6 Armor: 1 "<<endl;
        cout<<"8. Bodyguard FC: 4 Armor: 2 "<<endl;
        cin>>input_ant;
      }while(is_int(input_ant) == false || stoi(input_ant) < 1 || stoi(input_ant) > 8);
      do{
        cout<<"what space would you like to place it? (1-10)"<<endl;
        cin>>intput_location;
      }while(stoi(intput_location) < 1 || stoi(intput_location) > 10 || is_int(intput_location) == false);
      //place the intput_locationant
    }while(valid_move(stoi(input_ant),stoi(intput_location)-1) == false);//not valid move
    determine_ant(stoi(input_ant), stoi(intput_location)-1);
    print_board();
    cout<<"COLONY FOOD: "<<*colony_food<<endl;
  }while(prompt_repeat() == true);//not want to repeat
}

/********************************************************************
** Function: valid_move
** Description: returns boolean if the move is valid to place ant
** parameters: n/a
********************************************************************/
bool game::valid_move(int name, int location){
  if(name == 8 ){
    if(spaces[location].get_ants().size() > 0){
      return true;
    }
  }
  else if(*colony_food <= 4){
    return false;
  }
  else if(spaces[location].get_ants().size() > 0){
    return false;
  }
  else{
    return true;
  }
}

/********************************************************************
** Function: determine_ant()
** Description: this creates new ants and updates the number of ants
** parameters: int number and index of spaces
********************************************************************/
void game::determine_ant(int num, int index){
  if(num == 1){
    ant *a = new harvester(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
  else if(num == 2){
    ant *a = new thrower(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
  else if(num == 3){
    ant *a = new fire(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
  else if(num == 4){
    ant *a = new long_thrower(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
  else if(num == 5){
    ant *a = new short_thrower(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
  else if(num == 6){
    ant *a = new wall(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
  else if(num == 7){
    ant *a = new ninja(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
  else if(num == 8){
    ant *a = new bodyguard(index);
    spaces[index].add_ant(a);
    num_ants = num_ants +1;
    *colony_food = *colony_food - a->get_food_cost();
  }
}

/********************************************************************
** Function: all_ant_turn
** Description: this simulates an ant turn //did not get finished
** parameters: n/a
********************************************************************/
void game::all_ant_turn(){
  prompt_input();
}

/********************************************************************
** Function: print_board
** Description: prints out the board
** parameters: n/a
********************************************************************/
void game::print_board(){
  cout<<"QUEEN BEE"<<endl;
  for(int i = 0; i < 10; i++){
    cout<<"space "<<i+1<<" ";
    for(int b = 0; b < spaces[i].get_ants().size(); b++){
      cout<<(spaces[i].get_ants_at(b))->get_name()<<" ";
    }
    for(int c = 0; c < spaces[i].get_bees().size(); c++){
      cout<<"B ";
    }
    cout<<endl;
  }
}

/********************************************************************
** Function: all_bee_turn
** Description: this simulates the whole turn for the bees
** parameters: n/a
********************************************************************/
void game::all_bee_turn(){
  //generate a new bee
  bee *temp;
  bee t2;
  temp = &t2;
  spaces[9].generate_bee(temp);
  num_bees = num_bees + 1;
  //move bee to the left
  for(int i = 1; i < 10; i++){
      if(space_left_open_ant(i) == true){
        while(spaces[i].get_bees().size() > 0){
          spaces[i-1].generate_bee(spaces[i].get_bees_at(spaces[i].get_bees().size()-1));
          spaces[i].rem_bee();
        }
      }
  }
  for(int b = 1; b < 10; b++){
    if(space_left_open_ant(b) == false){
      flight_of_the_bumblebee(b);
    }
  }
  //implement bee attack
  cout<<"the bees have finished their turns"<<endl;
}

/********************************************************************
** Function: run_game()
** Description: this simulates and organizes all of the functions
** parameters: n/a
********************************************************************/
void game::run_game(){
  do{
    all_bee_turn();
    if(prompt_repeat() == true){
      all_ant_turn();
    }
    print_board();
  }while(game_over() == false);//game not over
  cout<<endl;
  cout<<"GAME OVER"<<endl;
  cout<<endl;
}
/********************************************************************
** Function: flight_of_the_bumblebee()
** Description: this simulates the moving of the bee and the attacking on ants
** parameters: integer index
********************************************************************/
void game::flight_of_the_bumblebee(int i){
      for(int b = 0; b < (spaces[i].get_bees()).size(); b++){
        if(space_left_open_ant(i) == false){
          if(spaces[i-1].get_ants().size() > 0){
            if(spaces[i-1].get_ants_at(0)->get_armor() > 0){
            spaces[i-1].get_ants_at(0)->decrement_armor();
            }
            if(spaces[i-1].get_ants_at(0)->get_armor() == 0){
              ant *temp = spaces[i-1].get_ants_at(0);
              spaces[i-1].rem_ant();
              delete temp;
              cout<<"an ant has died"<<endl;
              break;
            }
          }
        }
      }
    }

/********************************************************************
** Function: game_over
** Description: this returns the boolean if the game is over or not
** parameters: n/a
********************************************************************/
bool game::game_over(){
  if(num_bees == 0){
    cout<<endl;
    cout<<"THERE ARE NO MORE BEES"<<endl;
    cout<<"THE ANTS WIN"<<endl;
    return true;
  }
  else if(spaces[0].get_bees().size() > 0){
    cout<<endl;
    cout<<"THE QUEEN HAS DIED"<<endl;
    cout<<"THE BEES WIN"<<endl;
    return true;
  }
  else if(*colony_food <= 0){
    cout<<endl;
    cout<<"THERE IS NO MORE FOOD"<<endl;
    cout<<"THE BEES WIN"<<endl;
    return true;
  }
  else{
    return false;
  }
}

/********************************************************************
** Function: space_left_open_ant
** Description: this returns the boolean if there is a space open to the left
** parameters: integer starting location of bee
*******************************************************************/
bool game::space_left_open_ant(int start_bee){
  if(start_bee != 0){
    if(spaces[start_bee - 1].get_ants().size() == 0){
      return true;
    }
    else{
      return false;
    }
  }
  return false;
}

/********************************************************************
** Function: game()
** Description: this initializes the fields of the game class
** parameters: n/a
********************************************************************/
game::game(){
  spaces = new space[10];
  colony_food = new int;
  *colony_food = 50;
  num_bees = 0;
  num_ants = 0;
}

/********************************************************************
** Function: ~game()
** Description: this deletes the items on the heap for the game class
** parameters: n/a
********************************************************************/
game::~game(){
  delete [] spaces;
  delete colony_food;

}
