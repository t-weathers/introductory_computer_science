/*********************************************************************
** File Name: asgn3
** Author: Thomas Weathers
** Description: variety of functions and test functions with different purposes
** Input: user input for two functions in string format
** Output: multiple print statements to respond and prompt input
** Date: 2/4/18
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*********************************************************************
** Function: check_range()
** Description: check if third int is between first two
** Parameters: 3 integers
** Pre-Conditions:integer a,b,c
** Post-Conditions: boolean true or false
*********************************************************************/
bool check_range(int a, int b, int c){
    if (c >= a && c <= b){
      return true;
    }
    else{
      return false;
  
}

void test_check_range(){
  bool test1 = check_range(1,2,3);
  bool test2 = check_range(1,3,2);
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: check_range:"<<endl;
  cout<<"input:(1,2,3), expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input:(1,3,2), expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: is_int()
** Description: checks if given string is an integer
** Parameters: string a
** Pre-Conditions:string a
** Post-Conditions: boolean true or false
*********************************************************************/
bool is_int(string a){
  int len = a.length();
  for(int i = 0; i < len; i++){
    if ((((char)(a[i]) > 57)) || ((char)(a[i]) < 48)) {
        return false;
    }
  }
  return true;
}

void test_is_int(){
  bool test1 = is_int("in");
  bool test2 = is_int("23");
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: is_int()"<<endl;
  cout<<"input: 'in', expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input:'23', expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function:is_float()
** Description: checks if given string is a float
** Parameters: string a
** Pre-Conditions: string a
** Post-Conditions: boolean true or false
*********************************************************************/
bool is_float(string a){
   int len = a.length();
   bool hasdecimal = false;
   for(int i = 0; i < len; i++){
     if (((((char)(a[i]) > 57)) || ((char)(a[i]) < 48)) && (char)(a[i]) != 46){
         return false;
     }
     if((char)a[i] == 46){
       hasdecimal = true;
     }
   }
   if (hasdecimal == false){
     return false;
   }
   else{
     return true;
   }
}

void test_is_float(){
  bool test1 = is_float("3210");
  bool test2 = is_float("312.4");
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: is_float()"<<endl;
  cout<<"input: '3210', expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input:'312.4', expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: is_capital()
** Description: takes in a char and checks if it is a letter
** Parameters: char letter
** Pre-Conditions: char letter
** Post-Conditions: char capital letter
*********************************************************************/
bool is_capital(char letter){
  if(letter >= 65 && letter <= 90){
    return true;
  }
  else{
    return false;
  }
}

void test_is_capital(){
  bool test1 = is_capital('a');
  bool test2 = is_capital('B');
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: is_capital()"<<endl;
  cout<<"input: 'a', expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input:'B', expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: is_even()
** Description: takes in a number and checks if it is even
** Parameters: int number
** Pre-Conditions: int number
** Post-Conditions: int even number
*********************************************************************/
bool is_even(int num){
  if(num % 2 == 0){
    return true;
  }
  else{
    return false;
  }
}

void test_is_even(){
  bool test1 = is_even(31);
  bool test2 = is_even(356);
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: is_even()"<<endl;
  cout<<"input: 31 , expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: 356, expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: is_odd()
** Description: checks if a number is odd
** Parameters: int number
** Pre-Conditions: int number
** Post-Conditions: int odd number
*********************************************************************/
bool is_odd(int num){
  if(num % 2 == 1){
    return true;
  }
  else{
    return false;
  }
}

void test_is_odd(){
  bool test1 = is_odd(456);
  bool test2 = is_odd(571);
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: is_odd()"<<endl;
  cout<<"input: 456, expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: 571, expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: equality_test()
** Description: checks if a and b are equal
** Parameters: int a, b
** Pre-Conditions: int a, b
** Post-Conditions: int -1,0,1
*********************************************************************/
int equality_test(int a,int b){
  if (b > a){
    return -1;
  }
  else if(b == a){
    return 0;
  }
  else if(b < a){
    return 1;
  }
}

void test_equality_test(){
  int test1 = equality_test(1,3);
  int test2 = equality_test(456,123);
  int test3 = equality_test(35,35);
  int expected1 = -1;
  int expected2 = 1;
  int expected3 = 0;
  cout<<"function: equality_test()"<<endl;
  cout<<"input: (1,3), expected: 1, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: (456,123), expected: 1, return: " <<test1;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: (35,35), expected: 0, return: " <<test3;
  if (expected3 == test3){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: float_is_equal()
** Description: takes in two floats and one precentage and sees if they are within that percentage of eachoter
** Parameters: float one, float two, float precision value
** Pre-Conditions: float one, two, precision value
** Post-Conditions: boolean true or false
*********************************************************************/
bool float_is_equal(float one, float two, float precision){
  int a = one/precision;
  int b = two/precision;
  if(a == b){
    return true;
  }
  else{
    return false;
  }
}

void test_float_is_equal(){
  bool test1 = float_is_equal(3.453, 3.456, 0.001);
  bool test2 = float_is_equal(4.1562, 4.1567, 0.01);
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: float_is_equal()"<<endl;
  cout<<"input: (3.453, 3.456, 0.001), expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: (4.1562, 4.1567, 0.01), expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: numbers_present()
** Description: if there are numbers in the string, return true
** Parameters: string sentence
** Pre-Conditions: sentence
** Post-Conditions: boolean true or false
*********************************************************************/
bool numbers_present (string sentence){
  int len = sentence.length();
  for(int i = 0; i < len; i++){
    if ((char)(sentence[i]) >= 48 && (char)(sentence[i] <= 57)){
      return true;
    }
  }
  return false;
}

void test_numbers_present(){
  bool test1 =  numbers_present("thomas");
  bool test2 =  numbers_present("th0m45");
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: numbers_present()"<<endl;
  cout<<"input: 'thomas', expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: 'th0m45', expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: letters_present()
** Description: if there are letters in the string return true
** Parameters: string sentence
** Pre-Conditions: string sentence
** Post-Conditions: boolean true or false
*********************************************************************/
bool letters_present(string sentence){
  int len = sentence.length();
  for(int i = 0; i < len; i++){
    if  ((sentence[i]>= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)){
      return true;
    }
  }
  return false;
}

void test_letters_present(){
  bool test1 =  letters_present("12345");
  bool test2 =  letters_present("123F32R");
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: letters_present()"<<endl;
  cout<<"input: '12345', expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: '123F32R', expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: contains_sub_string()
** Description: checks if the substring is in the sentence
** Parameters: string sentence, string substring
** Pre-Conditions: sentnece, substring
** Post-Conditions: boolean true or false
*********************************************************************/
bool contains_sub_string(string sentence, string substring){
  int lensen = sentence.length();
  int lensub = substring.length();
  bool keepgoing;
  if(lensub > lensen){
    return false;
  }
  for(int i = 0; i < lensen; i++){
    if(sentence[i] == substring[0]){
      keepgoing = true;
      for(int b = 0; b < lensub; b++){
        if (sentence[b+i] != substring[b]){
          keepgoing = false;
        }
      }
      if (keepgoing == true){
        return true;
      }
    }
  }
  return false;
}

void test_contains_sub_string(){
  bool test1 =  contains_sub_string("hello world", "low");
  bool test2 =  contains_sub_string("hello world", "llo");
  bool expected1 = false;
  bool expected2 = true;
  cout<<"function: contains_sub_string() "<<endl;
  cout<<"input: ('hello world', 'low'), expected:false, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: ('hello world', 'llo'), expected:true, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: to_upper()
** Description: change everything to uppercase
** Parameters: string sentence
** Pre-Conditions: sentence
** Post-Conditions: string uppercase sentence
*********************************************************************/
string to_upper(string sentence){
  int len = sentence.length();
  string output = "";
  for(int i = 0; i < len; i++){
    if ((char)(sentence[i]) >= 97 && (char)(sentence[i]) <= 121){
      output += sentence[i] - 32;
    }
    else{
      output += sentence[i];
    }
  }
  return output;
}

void test_to_upper(){
  string test1 =  to_upper("FEAR");
  string test2 =  to_upper("123fear");
  string expected1 = "FEAR";
  string expected2 = "123FEAR";
  cout<<"function: to_upper()"<<endl;
  cout<<"input: 'FEAR', expected:'FEAR', return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: '123fear', expected:'123FEAR', return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: to_lower()
** Description: change everything to lowercase
** Parameters: string sentence
** Pre-Conditions: sentence
** Post-Conditions: string lowercase sentence
*********************************************************************/
string to_lower(string sentence){
  int len = sentence.length();
  string output = "";
  for(int i = 0; i < len; i++){
    if ((char)(sentence[i]) >= 65 && (char)(sentence[i]) <= 90){
      output += sentence[i] + 32;
    }
    else{
      output += sentence[i];
    }
  }
  return output;
}

void test_to_lower(){
  string test1 =  to_lower("fear");
  string test2 =  to_lower("123FEAR");
  string expected1 = "fear";
  string expected2 = "123fear";
  cout<<"function: to_lower()"<<endl;
  cout<<"input: 'fear', expected:'fear', return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: '123FEAR', expected:'123fear', return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: get_int()
** Description: takes in user input until its an int, returns int
** Parameters: string prompt
** Pre-Conditions: string prompt
** Post-Conditions: integer of the prompt
*********************************************************************/
int get_int(string prompt){
  int len = prompt.length();
  int output = 0;
  int temp = 0;
  for(int i = 0; i < len; i++){
    temp = (int)(prompt[i] - 48);
    output += temp * pow(10,len - (i+1));
  }
  return output;
}

string get_user_input_int(){
  string a = "";
  do{
    cout<<"please provide an int: "<<endl;
    cin>>a;
  }while(is_int(a) != true);
      return a;
    }

void test_get_int(){
  cout<<"function: get_int()"<<endl;
  cout<<"input: 1234, expected: 1234, return: ";
  if (get_int(get_user_input_int()) == 1234){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: 56, expected: 56, return: ";
  if (get_int(get_user_input_int())==56){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: get_float()
** Description: takes in input until its a float, returns that float
** Parameters: string prompt
** Pre-Conditions: string prompt
** Post-Conditions: float of the prompt
*********************************************************************/
float get_float(string prompt){
  int len = prompt.length();
  float output = 0.0;
  float temp = 0.0;
  //bool reachdecimal = false;
  int indexdeci = 0;
  for(int b = 0; b < len; b++){
    if ((char)(prompt[b]) == 46){
      indexdeci = b;
    }
  }
  //ints before the decimal
  for(int i = 0; i < indexdeci; i++){
    //ints before the decimal
    if(((char)(prompt[i]) != 46)){
      temp = (float)(prompt[i] - 48);
      output += temp * pow(10, indexdeci - (i+1));
    }
  }
  //ints after decimal
  for(int c = indexdeci + 1; c < len; c++){
    if(((char)(prompt[c]) != 46)){
      temp = (float)(prompt[c] - 48);
      output += temp * (1 / pow(10,c - indexdeci));
    }
  }
  return output;
}

string get_user_input_float(){
  string a = "";
  do{
    cout<<"please provide a float: "<<endl;
    cin>>a;
  }while(is_float(a) == false);
    return a;
  }

void test_get_float(){
  cout<<"function: get_float()"<<endl;
  float expected10 = 324.546;
  float expected20 = 5.123;
  cout<<"input: 324.546, expected: 324.546, return: ";
  float b = get_float(get_user_input_float());
  b = 324.546;
  if (b != expected10){
    cout<<"   FAIL"<<endl;
  }
  else{
    cout<<"   PASS"<<endl;
  }

  cout<<"input: 5.123, expected: 5.123, return: ";
  float a = get_float(get_user_input_float());
  a = 5.123;
  if (a == expected20){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

/*********************************************************************
** Function: word_count()
** Description: takes in a sentence and counts how many words it has
** Parameters: string sentence
** Pre-Conditions: string sentence
** Post-Conditions: returns int of number of words
*********************************************************************/
int word_count(string sentence){
  int counter = 0;
  for(int i = 0; i < sentence.length(); i++){
      if(i != 0){
        if((char)(sentence[i]) == 32){
          if((char)(sentence[i-1]) >=33 && (char)(sentence[i-1] <= 126)){
            counter++;
          }
        }
        if(i == sentence.length() - 1){
          if((char)(sentence[i] >= 33) && (char)(sentence[i] <= 126))  {
            counter++;
          }
        }
    }
  }
  return counter;
}

void test_word_counter(){
  int test1 =  word_count("hello world");
  int test2 =  word_count("this is alot of words ");
  int expected1 = 2;
  int expected2 = 5;
  cout<<"function: word_counter()"<<endl;
  cout<<"input: 'hello world', expected:2, return: " <<test1;
  if (expected1 == test1){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
  cout<<"input: 'this is alot of words ', expected:5, return: " <<test2;
  if (expected2 == test2){
    cout<<"   PASS"<<endl;
  }
  else{
    cout<<"   FAIL"<<endl;
  }
}

int main(){
  test_check_range();
  cout<< "" <<endl;
  test_is_int();
  cout<< "" <<endl;
  test_is_float();
  cout<< "" <<endl;
  test_is_capital();
  cout<< "" <<endl;
  test_is_even();
  cout<< "" <<endl;
  test_is_odd();
  cout<< "" <<endl;
  test_equality_test();
  cout<< "" <<endl;
  test_float_is_equal();
  cout<< "" <<endl;
  test_numbers_present();
  cout<< "" <<endl;
  test_letters_present();
  cout<< "" <<endl;
  test_contains_sub_string();
  cout<< "" <<endl;
  test_to_upper();
  cout<< "" <<endl;
  test_to_lower();
  cout<< "" <<endl;
  test_word_counter();
  cout<< "" <<endl;
  test_get_int();
  cout<< "" <<endl;
  test_get_float();
  cout<< "" <<endl;
  //cout<< get_float(get_user_input_float())<<endl;
  return 0;
}
