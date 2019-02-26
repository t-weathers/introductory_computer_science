#include "student_db.h"
using namespace std;

int stoi(string input){
        int val;
        int res = 0;
        for(int i = (input.length()-1); i >= 0; i--) {
                val = ((int) input[i]) - 48;
                res +=  val * pow(10,(input.length() - i -1));
        }
}

student *create_student_db(int len){
  student *students = new student[len];
  return students;
}

void get_student_db_info(student *students, int len, fstream &file){
  string temp;
  char *temp2 = new char[256];
  for(int i = 0; i < len; i++){
    file>>students[i].ID;
    file>>students[i].first_name;
    file>>students[i].last_name;
    file>>students[i].major;
  }
}
void delete_student_db_info(student **students, int len){
  /*for(int i = 0; i < len; i++){
    delete students[i];
  }*/
  delete [] (*students);
}

void alphebetically(string *list, int len){
  bool keepgoing = false;
  do{
    keepgoing = false;
    for (int i = 0; i < len-1; i++){
      if(list[i] > list[i+1]){
        list[i].swap(list[i+1]);
        keepgoing = true;
        break;
      }
    }
  }while(keepgoing);
}

void sort_ID(int *list, int len){
  int temp;
  bool keepgoing = false;
  do{
    keepgoing = false;
    for(int i = 0; i< len-1; i++){
      if(list[i] > list[i+1]){
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
        keepgoing = true;
        break;
      }
    }
  }while(keepgoing);
}

int num_of_unique_majors(student *students, int len){
  int count = 0;
  bool unique;
  for(int i = 0;i < len; i++){
    unique  = true;
    for(int b = 1; b < len; b++){
      if(students[i].major == students[b].major){
        unique = false;
      }
    }
    if(unique == true){
      count++;
    }
  }
  return count;
}

int *create_list_of_ID(student *students, int len){
  int *IDlist = new int[len];
  for(int i = 0; i < len; i++){
    IDlist[i] = students[i].ID;
  }
  return IDlist;
}
string *create_list_of_names(student *students, int len){
  string *LastNameList = new string[len];
  for(int i = 0; i < len; i++){
    LastNameList[i] = students[i].last_name;
  }
  return LastNameList;
}
