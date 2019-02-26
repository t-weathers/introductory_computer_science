#include <iostream>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct mult_div_values{
  int mult;
  float div;
};

bool is_valid_diminsions(char *, char *);
mult_div_values** create_table(int, int);
void set_mult_values(mult_div_values **, int,int);
void set_div_values(mult_div_values **, int, int);
void delete_table(mult_div_values **, int);
void print_mult_table(mult_div_values **, int,int);
void print_div_table(mult_div_values **,int, int);
void set_new(int *, int *);
