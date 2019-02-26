/*********************************************************************
** File Name: asgn4
** Author: Thomas Weathers
** Description: four different caluculators, a standard calculator, a binary converter to decimal, a decimal converter to binary, and a grade calculator
** Input: user input as strings for calculator entries
** Output: multiple print statements to respond and prompt input and int/float calculator returns
** Date: 2/15/18
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

/*********************************************************************
** Function: print_menu()
** Description: prints the 5 user options to direct to the correct calculator
*********************************************************************/
void print_menu(){
  cout<<"Press the following numbers to access the corresponding programs"<<endl;
  cout<<"1. Standard Calculator"<<endl;
  cout<<"2. Binary to Decimal Conversion Calculator"<<endl;
  cout<<"3. Deciomal to Binary Conversion Calculator"<<endl;
  cout<<"4. Grade Calculator"<<endl;
  cout<<'\n';
  cout<<"5. Quit"<<endl;
}

/*********************************************************************
** Function: is_int()
** Description: checks if given string is an integer
** Parameters: string a
*********************************************************************/
//implemented from my assignment 3
bool is_int(string a){
  int len = a.length();
  for(int i = 0; i < len; i++){
    if ((((char)(a[i]) > 57)) || ((char)(a[i]) < 48)) {
        return false;
    }
  }
  return true;
}

/*********************************************************************
** Function:stof()
** Description: takes a string and turns it into a float
** Parameters: string input
** Pre-Conditions: the string taken in only contains numbers, decimal point, or negative
*********************************************************************/
//implemented from my work in lab 5
float stof(string input){
    int len = input.length();
    float output = 0.0,temp = 0.0;
    bool neg = false;
    int indexdeci = input.length();
    for(int b = 0; b < len; b++){
      if ((char)(input[b]) == 46){
        indexdeci = b;
      }
    }
    //ints before the decimal
    for(int i = 0; i < indexdeci; i++){
      //ints before the decimal
      if(((char)(input[i]) != 46)){
        if(input[i]== 45){
          neg = true;
        }
        else{
        temp = (float)(input[i] - 48);
        output += temp * pow(10, indexdeci - (i+1));
      }
      }
    }
    //ints after decimal
    if (indexdeci != 0){
      for(int c = indexdeci + 1; c < len; c++){
        if(((char)(input[c]) != 46)){
          temp = (float)(input[c] - 48);
          output += temp * (1 / pow(10,c - indexdeci));
        }
    }
    if(neg == true){
      output *= -1;
    }
    return output;
  }
}

/*********************************************************************
** Function:is_float()
** Description: checks if given string is a float
** Parameters: string a
*********************************************************************/
//implemented from my work in lab 5
bool is_float(string input){
        int count  = 0;
        for(int i=0; i<input.length(); i++){
                if (input[i] < '0' || input[i] > '9') {
                        if (input[i] == '.') {
                                count++;
                                if (count > 1) {
                                        return false;
                                }
                        }
                        else {
                                return false;
                        }
                }
        }
        return true;
}

/*********************************************************************
** Function:stoi()
** Description: takes in a string and converts to an integer
** Parameters: string input
** Pre-Conditions: the string that is input contains only numbers
*********************************************************************/
//implemented from my work in lab 5
int stoi(string input){
        int val;
        int res = 0;
        for(int i = (input.length()-1); i >= 0; i--) {
                val = ((int) input[i]) - 48;
                res +=  val * pow(10,(input.length() - i -1));
        }
}

/*********************************************************************
** Function: check_if_binary()
** Description: checks if the given string contains only 1's and 0's
** Parameters: string suspectedBinarys
*********************************************************************/
//implemented from given code in lecture notes on binary conversion
bool check_if_binary(string suspectedBinary){
  bool output = true;
  for(int i = 0; i < suspectedBinary.length(); i++){
    if (suspectedBinary[i] != '1' && suspectedBinary[i] != '0'){
      output = false;
    }
  }
  return output;
}

/*********************************************************************
** Function:convert_binary()
** Description:converts unsigned binary binary to an integer value thats equivalent
** Parameters: string
** Pre-Conditions: string that is input must be only 1's and 0's
*********************************************************************/
//implemented from given code in lecture notes on binary conversion
int convert_binary(string binaryString){
  int length = binaryString.length();
  int output = 0;
  for(int i = 0; i < length; i++){
    if (binaryString[i] == '1'){
      output += pow(2,length - i - 1);
    }
  }
  return output;
}

/*********************************************************************
** Function:add()
** Description: adds the two floats given
** Parameters: float 1 and float 2
*********************************************************************/
float add(float a, float b){
  float output = a + b;
  return output;
}

/*********************************************************************
** Function: subtract()
** Description: subtracts the second float from the first float
** Parameters: float 1 and float 2
*********************************************************************/
float subtract(float a, float b){
  float output = a - b;
  return output;
}

/*********************************************************************
** Function:multiply
** Description:multiplies the two given floats
** Parameters: float 1 and float 2
*********************************************************************/
float multiply(float a, float b){
  float output = a * b;
  return output;
}

/*********************************************************************
** Function:divide()
** Description: divides the two given floats, with integer division if they are whole numbers, and regular division if not
** Parameters: float 1 and float 2
*********************************************************************/
float divide(float a, float b){
  int a1, b1, temp;
  float output;
  if(a - (int)a == 0 && b - (int)b == 0){
    a1 = (int)(a);
    b1 = (int)(b);
    temp = a1 / b1;
    output = (float)(temp);
  }
  else{
    output = a / b;
  }
  return output;
}

/*********************************************************************
** Function: convert_deci_binary_recursive()
** Description: a recursive function that converts integer to binary
** Parameters: integer decimal value
** Pre-Conditions: decimal must be an unsigned positive integer
** Post-Conditions: print the binary of the decimal
*********************************************************************/
void convert_deci_binary_recursive(int decimal){
  int rem = decimal%2;
  decimal = decimal / 2;
  if (decimal > 0){
    convert_deci_binary_recursive(decimal);
  }
  cout<<rem;
}

/*********************************************************************
** Function: run_deci_binary_converter()
** Description: this runs the decimal to binary converter by calling the appropriate functions
*********************************************************************/
void run_deci_binary_converter(){
  string input;
  string output;
  do{
    cout<<"[DECIMAL TO BINARY CONVERSION CALCULATOR]"<<endl;
    cout<<'\n'<<endl;
    cout<<"please provide an integer value to be converted to binary: "<<endl;
    cin>>input;
  }while(is_int(input) == false);
  convert_deci_binary_recursive(stoi(input));
  cout<<"\n";
}

/*********************************************************************
** Function:run_binary_converter()
** Description: this runs the binary conversion calculator, by looping and calling appropriate functions
*********************************************************************/
void run_binary_converter(){
  string input;
  int output;
  do{
    cout<<"[BINARY CONVERSION CALCULATOR]"<<endl;
    cout<<'\n';
    cout<<"please provide an unsigned positive binary number: "<<endl;
    cin>>input;
  }while (check_if_binary(input) == false);
  output = convert_binary(input);
  cout<<output<<endl;
}

/*********************************************************************
** Function:apply_weight_to_grade
** Description: applies the weight to the function that the user gives
** Parameters: float average
** Pre-Conditions: float average is a decimal value
** Post-Conditions: the decimal value is changed to be weighted
*********************************************************************/
void apply_weight_to_grade(float &avg){
  string input2;
  string weight;
  char input2Char = ' ';
  string weightStr = "";
  do{
    cout<<"do you want a weighted average?"<<endl;
    cout<<"(enter 1 for yes, 2 for no)"<<endl;
    cin>>input2;
  }while(is_int(input2) == false && (stoi(input2) > 0) && (stoi(input2) < 3));
  if (stoi(input2) == 1){
    do{
      cout<<"please give a weight to apply to the average(as a decimal percentage): "<<endl;
      cin>>weight;
    }while(is_float(weight) == false && stof(weight) > 0.0);
    avg *= stof(weight);
    avg = avg / 100.00;
  }
}

/*********************************************************************
** Function: letters_present()
** Description: checks if there are letters present in the string given
** Parameters: string sentence
*********************************************************************/
//implemented from asgn3
bool letters_present(string sentence){
  int len = sentence.length();
  for(int i = 0; i < len; i++){
    if  ((sentence[i]>= 65 && sentence[i] <= 90) || (sentence[i] >= 97 && sentence[i] <= 122)){
      return true;
    }
  }
  return false;
}

/*********************************************************************
** Function: check_for_valid_char()
** Description: this checks if there are valid characters for the standard calculator to determine if the given string is an equation
** Parameters: string sentence
*********************************************************************/
bool check_for_valid_char(string sentence){
  for(int i = 0; i< sentence.length();i++){
    if ((sentence.at(i) >= 33 && sentence.at(i)<= 41) || (sentence.at(i) >= 58)|| sentence[i] == 44) {
        return false;
    }
  }
  return true;
}

/*********************************************************************
** Function:calculate_grade()
** Description: this is the main function for the grade calculator that calculates user grade inputs
** Post-Conditions:prints the grade given
*********************************************************************/
void calculate_grade(){
  string totalGrades;
  string input;
  float total = 0.0, avg = 0.0;
  cout<<"[GRADE CALCULATOR]"<<endl;
  cout<<'\n';
  do{
    cout<<"how many grades would you like to enter? "<<endl;
    cin>>totalGrades;
  }while((is_int(totalGrades)==false) && (stoi(totalGrades) <= 0));
  for(int i  = 0; i < stoi(totalGrades); i++){
    do{
      cout<<"grade "<<i+1<< " (as a percent in decimal form): "<<endl;
      cin>>input;
    }while((is_float(input) == false) && (stof(input) <= 0.0));
    total += stof(input);
  }
  avg = total / stof(totalGrades);
  apply_weight_to_grade(avg);
  cout<<"total grade: "<<avg<<'%'<<endl;
}

/*********************************************************************
** Function:check_for_valid_numbers()
** Description: this checks that in the user equation, there is only the correct numbers
** Parameters: string equation
*********************************************************************/
bool check_for_valid_numbers(string equation){
  if (letters_present(equation) == true){
    return false;
  }
  if (check_for_valid_char(equation) == false){
    return false;
  }
  return true;
}

/*********************************************************************
** Function: num_of_operators()
** Description: this counts the number operators in the equation
** Parameters: string equation
*********************************************************************/
int num_of_operators(string equation){
  int count = 0;
  for(int i =0; i <equation.length(); i++){
    if (equation.at(i) == 42){
      count++;
    }
    else if(equation.at(i)  == 43){
      count++;
    }
    else if(equation.at(i) == 47){
      count++;
    }
    else if (equation.at(i) == 45 && equation.at(i+1) == 32){
      count++;
    }
  }
  return count;
}

/*********************************************************************
** Function: check_if_valid_equation()
** Description: this checks that the equation is valid because it has the right characters of an equation
** Parameters:string equation
*********************************************************************/
bool check_if_valid_equation(string equation){
  bool op = false,num1 = false,num2 = false, spaces = false;
  int opindex = 0;
  for (int i = 2; i < equation.length(); i++){
    if (equation[i] == '-' || equation[i] == '+' || equation[i] == '/' || equation[i] == '*'){
      op = true;
      opindex = i;
      cout<<"op: "<<opindex<<endl;
      break;
    }
  }
  if (op == true){
    if (equation.at(opindex - 2) >= 48 && equation.at(opindex - 2) <= 57){
      num1 = true;
    }
    if((equation[opindex + 2] >= 48 && equation[opindex + 2] <= 57) || (equation[opindex + 2] == '-')){
      num2 = true;
      cout<<"num2: "<<num2<<endl;
    }
    if (equation[opindex - 1] == ' ' && equation[opindex + 1] == ' '){
      spaces = true;
    }
  }
  if (op == true && num1 == true && num2 == true && spaces == true && check_for_valid_numbers(equation) == true){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:modstof()
** Description: this is a modification of stof that searches for the next space
** Parameters: string equation
** Pre-Conditions: the equation has spaces between the operator and the numbers
*********************************************************************/
//uses stof to cut off at the first time there is a space
float modstof(string equation){
    int i = 0;
    for(i = 0; i< equation.length(); i++){
      if(equation[i] == ' '){
        break;
      }
    }
    string temp = equation.substr(0,i);
    return stof(temp);
}

/*********************************************************************
** Function: parse_string()
** Description: this parses the given equation and prints the answer of the equation
** Parameters: string equation
** Pre-Conditions: the equation has a string
** Post-Conditions: the equation erases the math functions that it completes
*********************************************************************/
void parse_string(string &equation){
  float equation1 = 0.0,equation2 = 0.0, val = 0;
  char op;
  equation1 = modstof(equation);
  equation.erase(0,equation.find_first_of(' ',0)+1);
  do{
    op = equation[0];
    equation.erase(0,2);
    equation2 = modstof(equation);
    cout<<"equation1: "<<equation1<<endl;
    cout<<"equation2: "<<equation2<<endl;
    if (op == '+'){
      equation1 = add(equation1, equation2);
    }
    else if (op == '-'){
      equation1 = subtract(equation1, equation2);
    }
    else if(op == '*'){
      equation1 =multiply(equation1, equation2);
    }
    else if(op == '/'){
      equation1 = divide(equation1, equation2);
    }
    equation.erase(0,equation.find_first_of(' ',0)+1);

  }while(num_of_operators(equation) > 0);
    cout<<equation1<<endl;
  }

  /*********************************************************************
  ** Function:
  ** Description:
  ** Parameters:
  ** Pre-Conditions:
  ** Post-Conditions:
  *********************************************************************/

  /*********************************************************************
  ** Function: run_standard_calc()
  ** Description: this runs the standard calculator by providing a loop for the correct inputs
  *********************************************************************/
void run_standard_calc(){
  string equation = "";
  do{
    cout<<"[STANDARD CALCULATOR]"<<endl;
    cout<<"\n";
    cout<<"please provide a full equation separated by spaces between operators: "<<endl;
    getline(cin,equation);
  }while(check_if_valid_equation(equation) == false);
  parse_string(equation);
}



int main(){
  bool cont = true;
	string functionCall;
do{
  do{
      print_menu();
      cin>>functionCall;
    }
while(is_int(functionCall) == false && (stoi(functionCall) <= 0 || stoi(functionCall) >= 6));
    if (stoi(functionCall) == 1){
      run_standard_calc();
    }
    else if(stoi(functionCall) == 2){
      run_binary_converter();
    }
    else if(stoi(functionCall) == 3){
      run_deci_binary_converter();
    }
    else if(stoi(functionCall) == 4){
      calculate_grade();
  }
    //quit the program
    else{
      cont = false;
    }
  }while(cont == true);

  return 0;
}
