#include <iostream>
using namespace std;

/*********************************************************************
** Function: a_to_i
** Description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returned the decimal value of the character
*********************************************************************/
int atoi(char character){
    int output = (int)(character);
    return output;
}

char itoa(int integer){
    char output = (char)(integer);
    return output;
}
int main(){
    char char1;
    int int1;
    cout <<"(atoi) give a char: ";
    cin >> char1;
    cout <<atoi(char1)<< endl;

    cout <<"(itoa) give a decimal value: ";
    cin >> int1;
    cout << itoa(int1) << endl;

    return 0;
}
