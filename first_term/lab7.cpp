#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void get_string(char *origional,int num){
  cout<<"Please give a sentence: "<<endl;
  //cin.ignore(256, '\n');
  cin.getline(origional,num);
}

void set_replace_string(char *origional, char *dash){
  for(int i = 0; i< (sizeof(origional)/sizeof(char)); i++){
    if(origional[i] != ' '){
      (dash)[i] = '-';
    }
  }
}

char prompt_input2(){
  char letter[2];
  fflush(stdin);
  cout<<"please give a letter: "<<endl;
  cin.getline(letter,2);
  return letter[0];
}

int get_search_replace(char letter,char *origional,char *a){
  int count = 0;
  for(int i = 0; i < (sizeof(a) / sizeof(char)); i++){
    if((origional)[i] == letter){
      a[i] = letter;
      count++;
    }
  }
  return count;
}

int main(){
  int num = 11;
  cout<<"how many characters do you want in your word?: "<<endl;
  char temp[20];
  cin.getline(temp, 20);
  num = atoi(temp);
  fflush(stdin);
  char *origional = new char[num+1];
  get_string(origional,num);
  fflush(stdin);
  char *dash_copy = new char[num+1];
  for (int i  = 0; i < num; i++){
    (dash_copy[i]) = origional[i];
  }
  set_replace_string(origional,dash_copy);
  fflush(stdin);
  //cout<<dash_copy<<endl;
  int b = get_search_replace(prompt_input2(),origional,dash_copy);
  //cout<<dash_copy<<endl;
  cout<<"number of letters replaced: "<<b<<endl;
  delete [] origional;
  delete [] dash_copy;
}
