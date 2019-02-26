/******************************************************
** Program: run_facts.cpp
** Author: Thomas Weathers
** Date: 04/15/2017
** Description: this is the main runner for the program
** Input:user input in the form of a string
** Output: gives the user stats about the states
******************************************************/
#include "state_facts.h"

using namespace std;

int main(int argc, char **argv){
  state *states = new state[0];
  int numstates = 0;
  char *fileInName = new char[0];
  //correct command line arguments
  if(is_valid_arguments(argc,argv)){
    fileInName = argv[find_file_index(argc,argv)]; // find file in cmd line agruments
    numstates = *argv[find_int_index(argc,argv)] - 48; // find state num in cmd line arguments
  }
  else{ //not correct command line args
    cout<<"im sorry you have not provided valid input"<<endl;
    return 0;
  }
  bool a_file = to_file_input();
  ifstream file;
  file.open (fileInName,ifstream::in);
  if (file.is_open()){
    states = create_states(numstates);
    get_state_data(states,numstates,file);
    file.close();
  }
  else{
    cout<<"file did not open"<<endl;
    return 0;
  }
  fileInName = NULL;
  if (a_file == true){ //write results to file
    to_file(states,numstates);
  }
  else{ // print out results
    to_screen(states,numstates);
    return 0;
  }
  delete_info(&states, numstates);
  return 0;
}
