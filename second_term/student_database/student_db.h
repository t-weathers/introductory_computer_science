#include <string.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct student{
  string first_name;
  string last_name;
  int ID;
  string major;
};

student *create_student_db(int);
void get_student_db_info(student *, int, fstream &);
void delete_student_db_info(student **, int);
void alphebetically(string *, int);
int num_of_unique_majors(student *,int);
int *create_list_of_ID(student *,int);
string *create_list_of_names(student *, int);
void sort_ID(int *, int);
int stoi(string);
