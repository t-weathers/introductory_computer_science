#include <cmath>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){

  int numNumbers;
  int numUpperCase;
  int lowerBool;
  int numLowerCase;
  int upLetters;
  char output;
  int output2;
  srand(time(NULL));


  cout << "how long do you want the password to be? " << endl;
  int length;
  cin >> length;

  cout << "do you want letters? (0-no, 1-yes) " << endl;
  int letters;
  cin >> letters;
    //yes letters
    if (letters == 1){
        cout << "do you want uppercase letters? (0-no, 1-yes) " << endl;
        cin >> upLetters;

          //yes uppercase letters
        if(upLetters == 1){
            cout << "how many uppercase letters do you want? " <<endl;
            cin >> numUpperCase;
        }

        //lowecase letters
        cout<<"do you want lowercase letters? (0-no, 1-yes) " << endl;
        cin >> lowerBool;

        if (lowerBool == 1){
            cout <<"how many lowercase letters do you want? " <<endl;
            cin >> numLowerCase;

        }
  }
  //numbers
  cout <<"do you want numbers? (0-no, 1-yes) " << endl;
  int numBool;
  cin >> numBool;

  if (numBool == 1){
      cout<< "how many of the characters should be numbers? " << endl;
      cin >> numNumbers;
  }

  if (letters == 1 && upLetters == 1){
    for (int i = 0; i < numUpperCase; i++){
        output = (char)(rand() % 26 + 65);
        cout << output;
    }
  }
  if (letters == 1 && lowerBool == 1){
    for (int b = 0; b < numLowerCase; b++){
        output = (char)(rand() % 26 + 97);
        cout << output;
    }
  }
  if(numBool == 1){
    for (int c = 0; c < numNumbers; c++){
        output2 = rand() % 10;
        cout << output2;
    }
  }
return 1;
}
