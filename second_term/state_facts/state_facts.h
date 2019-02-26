#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;
//structs
struct county {
  string name; //name of county
  string *city; // array of city names in county
  int cities; //number of cities in county
  int population; //total population of county
  float avg_income; //avg household income
  float avg_house; //avg household price
};

struct state {
  string name; //name of state
  struct county *c; //array of counties
  int counties; //number of counties in state
  int population; //total population of state
};

//function prototypes
bool is_valid_arguments(int, char **);
state *get_state_data(int);
void get_state_data(state *, int, ifstream &);
county *create_counties(int);
state *create_states(int);
void get_county_data(county *, int, ifstream &);
void delete_info(state **, int);
string largest_state_pop(state *, int);
string largest_county_pop(county *, int);
bool is_int(string);
float stof(string);
bool is_float(string);
int stoi(string);
bool is_int(string);
county *income_above(state *, int, int *);
float *avg_household_cost(state *, int);
void alphebetically(string *, int);
void sort_int(int *, int);
int find_file_index(int, char **);
int find_int_index(int, char **);
bool to_file_input();
char *get_file_name();
string counties_above_return(state *, int);
void alphebatize_print(state *, int,ofstream &);
void alphebatize_write(state *, int);
void sort_pop_print(state *, int);
void sort_pop_write(state *, int,ofstream &);
void to_file(state *, int);
void to_screen(state *, int);
