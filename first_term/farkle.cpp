/*********************************************************************
** File Name: farkle
** Author: Thomas Weathers
** Description: this program plays the game farkle with the amount of players the user desires
** Input: user input to select dice
** Output: multiple print statements to respond and prompt input as game goes on
** Date: 3/2/18
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//set score to 0, sets length of score, gets num of players.
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
** Function:print_dice()
** Description:prints an array as dice, surrounded by []
** Parameters: int pointer, and integer size of the pointer
** Pre-Conditions: size is the length of the pointer
*********************************************************************/
void print_dice(int *dice_roles, int size){
  for(int i  = 0; i < size; i++){
    cout<<"["<<dice_roles[i]<<"] ";
  }
  cout<<"\n";
}

/*********************************************************************
** Function:initialize()
** Description:sets array of integers to 0
** Parameters: int pointer, and integer size of the pointer
** Pre-Conditions: size is the length of the pointer
*********************************************************************/
void initialize(int *score, int size){
  for(int i = 0; i < size; i++){
    score[i] = 0;
  }
}

/*********************************************************************
** Function:num_of_players()
** Description: asks the number of players that are playing
*********************************************************************/
int num_of_players(){
  string player_num_string;
  int player_num;
  do{
    cout<<"how many players are there?"<<endl;
    cin>>player_num_string;
  }while (stoi(player_num_string) < 1 && is_int(player_num_string) == false);
  player_num = stoi(player_num_string);
  return player_num;
}

/*********************************************************************
** Function: roll_dice()
** Description: sets integer pointer to value of rolled dice, int is the number of dice to roll
** Parameters: int pointer, and integer num of dice to populate pointer
*********************************************************************/
void roll_dice(int numDice, int *array){
  srand(time(NULL));
  for(int i = 0; i < numDice; i++){
    array[i] = rand();
    array[i] = (array[i] % 6) + 1;
  }
}

/*********************************************************************
** Function:has_one
** Description: checks if there is a one in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool has_one(int *array){
  if (array[0] >= 1){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:has_five()
** Description: checks if there is a five in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool has_five(int *array){
  if (array[4] >= 1){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:has_two_one()
** Description: checks if there are two ones in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool has_two_one(int *array){
  if (array[0] == 2){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:has_two_five()
** Description: checks if there are two fives in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool has_two_five(int *array){
  if (array[4] == 2){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:is_single_triple()
** Description: checks if there are three of a dice in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_single_triple(int *array){
  int count = 0;
  for(int i = 0; i < 6; i++){
    if (array[i] == 3){
      count++;
    }
  }
  if(count == 1){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:is_two_triples()
** Description: checks if there are two triples in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_two_triples(int *array){
  int count = 0;
  for(int i = 0; i < 6; i++){
    if (array[i] == 3){
      count++;
    }
  }
  if(count == 2){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:is_quad()
** Description: checks if there are four of a kind in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_quad(int *array){
  for(int i = 0; i < 6; i++){
    if (array[i] == 4){
      return true;
    }
  }
  return false;
}

/*********************************************************************
** Function:is_five()
** Description: checks if there are five of a kind in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_five(int *array){
  for(int i = 0; i < 6; i++){
    if (array[i] == 5){
      return true;
    }
  }
  return false;
}

/*********************************************************************
** Function:is_six()
** Description: checks if there are six of a kind in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_six(int *array){
  for(int i = 0; i < 6; i++){
    if (array[i] == 6){
      return true;
    }
  }
  return false;
}

/*********************************************************************
** Function:is_quad_plus_two()
** Description: checks if there are a four of a kind and a pair in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_quad_plus_two(int *array){
  int countquad = 0;
  int countdouble = 0;
  for(int i = 0; i < 6; i++){
    if (array[i] == 4){
      countquad++;
    }
    else if(array[i] == 2){
      countdouble++;
    }
  }
  if (countdouble == 1 && countquad == 1){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:is_three_pairs()
** Description: checks if there are three pairs in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_three_pairs(int *array){
  int count = 0;
  for(int i = 0; i < 6; i++){
    if (array[i] == 2){
      count++;
    }
  }
  if (count == 3){
    return true;
  }
  else{
    return false;
  }
}

/*********************************************************************
** Function:is_straight()
** Description: checks if there is a straight in the dice tally given
** Parameters:int array of tally of dice
** Pre-Conditions:array is a tally of the dice, not actual dice
*********************************************************************/
bool is_straight(int *array){
  int count = 0;
  for(int i = 0; i < 6; i++){
    if(array[i] == 1){
      count++;
    }
  }
  if(count == 6){
    return true;
  }
  return false;
}

/*********************************************************************
** Function:=find_five()
** Description: finds the location of a five of a kind
** Parameters:int array of tally of dice
** Pre-Conditions: has a five of a kind in the tally dice
*********************************************************************/
int find_five(int *tally_array){
  for(int i = 0; i < 6; i++){
    if(tally_array[i] == 5){
      return i;
    }
  }
}

/*********************************************************************
** Function:=find_quad()
** Description: finds the location of a four of a kind
** Parameters:int array of tally of dice
** Pre-Conditions: has a four of a kind in the tally dice
*********************************************************************/
int find_quad(int *tally_array){
  for(int i = 0; i < 6; i++){
    if(tally_array[i] == 4){
      return i;
    }
  }
}

/*********************************************************************
** Function:=find_triple()
** Description: finds the location of a three of a kind
** Parameters:int array of tally of dice
** Pre-Conditions: has a three of a kind in the tally dice
*********************************************************************/
int find_triple(int *tally_array){
  for(int i = 0; i < 6; i++){
    if(tally_array[i] == 3){
      return i;
    }
  }
}

//must take in 6 length in dice rolls, and tally array
/*********************************************************************
** Function:=convert_to_tally()
** Description: finds the location of a four of a kind
** Parameters:int pointer of dice. int pointer of tallies, int length of dice
** Pre-Conditions: dice roles must be populated with dice, len must be len of dice array
**post-condiditons: the tally array is changed to be a tally of dice rolls
*********************************************************************/
void convert_to_tally(int *dice_roles, int *tally_array, int len_dice){
  //populate tally_array w/ zero's
  for(int i = 0; i < 6; i++){
    tally_array[i] = 0;
  }
  //will set tallies of num of each dice
  for(int a = 0; a < len_dice ; a++){
    for(int tally_num = 1; tally_num < 7; tally_num++){
      if(dice_roles[a] == tally_num){
        tally_array[tally_num-1] += 1;
      }
    }
  }
}


/*********************************************************************
** Function calculate_score()
** Description: takes in dice and tally and updates score
** Parameters:int array of tally, int array of dice, int pointer score
** Pre-Conditions: score has a value, tally and dice roll is populated
**post-conditions: update score with correct score
*********************************************************************/
void calculate_score (int *dice_roles, int *score, int *tally_array){
  //cout<<"into calculate score"<<endl;
  //cout<<"tally: "<<endl;
  //cout<<"start score: "<<*score<<endl;
  if(is_straight(tally_array) == true){
    *score = *score + 1500;
  }
  else if(is_three_pairs(tally_array) == true){
    *score = *score +1500;
  }
  else if(is_quad_plus_two(tally_array) == true){
    *score = *score + 1500;
  }
  else if(is_two_triples(tally_array) == true){
    *score = *score + 2500;
  }
  else if(is_six(tally_array) == true){
    *score = *score + 3000;
  }
  else if(is_five(tally_array) == true){
    *score = *score + 2000;
    if(has_one(tally_array) == true){
      *score = *score + 100;
    }
    else if(has_five(tally_array) == true){
      *score = *score + 50;
    }
  }
  else if(is_quad(tally_array) == true){
    *score = *score + 1000;
    if(has_two_one(tally_array) == true){
      *score = *score + 200;
    }
    else if(has_one(tally_array) == true){
      *score= *score + 100;
    }
    if (has_two_five(tally_array) == true){
      *score = *score +100;
    }
    else if(has_five(tally_array) == true){
      *score = *score + 50;
    }
  }

  else if(is_single_triple(tally_array) == true){
    int location = find_triple(tally_array);
    //cout<<"location: "<<location<<endl;
    if(location != 0){
      *score = *score + ((location + 1) * 100);
      if(has_two_one(tally_array) == true){
        *score = *score + 200;
      }
      else if(has_one(tally_array) == true){
        *score = *score + 100;
      }
      if (has_two_five(tally_array) == true && find_triple(tally_array) != 5){
        *score= *score + 100;
      }
      else if(has_five(tally_array) == true && find_triple(tally_array) != 5){
      *score = *score + 50;
      }
    }
    else{
      *score = *score + 300;
      if (has_two_five(tally_array) == true){
        *score = *score + 100;
      }
      else if(has_five(tally_array) == true){
        *score = *score + 50;
      }
    }
    }
  else if(has_one(tally_array) == true){
    if(has_two_one(tally_array) == true){
      *score = *score + 100;
    }
    if (has_two_five(tally_array) == true){
      *score = *score +100;
    }
    else if(has_five(tally_array) == true){
      *score  = *score + 50;
    }
    *score = *score + 100;
  }
  else if(has_five(tally_array)== true){
    if(has_two_five(tally_array) == true){
      *score = *score +50;
    }
    if (has_two_one(tally_array) == true){
      *score = *score + 200;
    }
    else if(has_one(tally_array) == true){
      *score = *score + 100;
    }
  *score = *score + 50;
  }
}
  //cout<<"got to end of Calc SCore"<<endl;

  /*********************************************************************
  ** Function is_a_farkle()
  ** Description: returns true if a farkle, false if not
  ** Parameters:int array of tally, int array of dice
  ** Pre-Conditions:tally and dice roll is populated
  *********************************************************************/
bool is_a_farkle(int *dice_roles, int *tally_array){
  //cout<<"testing is a farkle"<<endl;
  bool output = false;
  int *score = new int;
  *score = 0;
  calculate_score(dice_roles, score, tally_array);
  //cout<<"out of calc score in farkle"<<endl;
  if(*score == 0){
    output = true;
  }
  delete score;
  return output;
}

/*********************************************************************
** Function valid_input_for_dice()
** Description: checks that the user enters valid input
** Parameters: string input from user
*********************************************************************/
bool valid_input_for_dice(string input){
  for(int i = 0; i < input.length(); i++){
    if(input[i] != ' ' && (input[i] < 48 || input[i] >54))
      return false;
  }
  if(input.length() > 20){
    return false;
  }
  return true;
}

/*********************************************************************
** Function convert_cstring_to_int_array()
** Description: converts c-string into an int pointer array
** Parameters: c-strings
*********************************************************************/
int *convert_cstring_to_int_array(char *array){
  int *output[strlen(array)];
  for(int i = 0; i < strlen(array); i++){
    *output[i] = array[i] - 48;
  }
  return *output;
}

/*********************************************************************
** Function num_of_dice_to_save()
** Description: returns integer of number of dice to save for reroll
*********************************************************************/
int num_of_dice_to_save(){
  int numDice = 0;
  string input = "";
  do{
    cout<<"how many dice do you want to save?: "<<endl;
    cin>>input;
  }
  while(is_int(input) == false && (stoi(input) < 1 || stoi(input) > 5));
  numDice =stoi(input);
  return numDice;
}

/*********************************************************************
** Function dice_to_save()
** Description: finds which dice to save, and updates the savedice pointer
** Parameters:int array of savedice, int array of dice, int of number of dice to save
** Pre-Conditions:dice roll is populated and num of dice to save > 0
*********************************************************************/
void *dice_to_save(int *dice_roles, int num_of_dice_to_save, int *savedice){
  string input = "";
  initialize(savedice,num_of_dice_to_save);
  int count = 0;
  for(int b = 0; b < 6; b++){
    do{
      cout<<"do you want to save dice "<<b + 1<<"? (1 for yes, 2 for no)"<<endl;
      cin>>input;
    }while(is_int(input) == false && (stoi(input) < 1 || stoi(input) > 2));
    if(stoi(input) == 1){
      savedice[count] = dice_roles[b];
      count++;
    }
    if (count == num_of_dice_to_save){
      break;
    }
  }
}

/*********************************************************************
** Function has_val()
** Description: returns true if it has a value by calling calc_score, false if not
** Parameters:int array of tally
** Pre-Conditions:tally is populated
*********************************************************************/
bool has_val(int *tally_array){
  if(is_straight(tally_array) == true){
    return true;
  }
  else if(is_three_pairs(tally_array) == true){
    return true;
  }
  else if(is_quad_plus_two(tally_array) == true){
    return true;
  }
  else if(is_two_triples(tally_array) == true){
    return true;
  }
  else if(is_six(tally_array) == true){
    return true;
  }
  else if(is_five(tally_array) == true){
    return true;
  }
  else if(is_quad(tally_array) == true){
    return true;
  }
  else if(is_single_triple(tally_array) == true){
    return true;
  }
  else if(has_one(tally_array) == true){
    return true;
  }
  else if(has_five(tally_array)== true){
    return true;
  }
  return false;
}

/*********************************************************************
** Function copy_array()
** Description: copies one array into another array
** Parameters:int array1, int array2, length of both
** Pre-Conditions: array and array2 roll are populated
**post-condiditon: array 2 has populated same as array 1
*********************************************************************/
void copy_array(int *array1, int *array2, int len){
  for(int i = 0; i < len; i++){
    array2[i] = array1[i];
  }
}

/*********************************************************************
** Function reroll()
** Description: does the sequence of rerolling dice and updating the temp score
** Parameters:int pointer array dice roles, int tally array, int pointer temp score
** Pre-Conditions: all arrays are populated, temp score is positive
**post-condiditon: dice roles, rerolls, and temp score are all updated
*********************************************************************/
int *reroll(int *dice_roles, int *tally_array, int *temp_score){
  int num_of_dice_to_s = 0;
  int *savedice;
  int *temp;
  savedice = new int[6];
    do{
      num_of_dice_to_s = num_of_dice_to_save();
      //cout<<"num of dice to save"<<num_of_dice_to_s<<endl;
      savedice = new int[num_of_dice_to_s];
      //temp = new int[6-num_of_dice_to_s];
      dice_to_save(dice_roles, num_of_dice_to_s, savedice);
      convert_to_tally(savedice,tally_array, num_of_dice_to_s);
    }while(has_val(tally_array)==false);
    //initialize(temp,6-num_of_dice_to_s);
    calculate_score(savedice,temp_score,tally_array);
    cout<<*temp_score<<endl;
    dice_roles = new int[6-num_of_dice_to_s];
    //cout<<"should be resized temp"<<endl;
    //print_dice(temp,6-num_of_dice_to_s);
    roll_dice(6 - num_of_dice_to_s,dice_roles);
    //cout<<"rerolled dice"<<endl;
    print_dice(dice_roles,6-num_of_dice_to_s);
    //copy_array(d,dice_roles, 6-num_of_dice_to_s);
    convert_to_tally(dice_roles, tally_array, 6-num_of_dice_to_s);
    delete savedice;
    return dice_roles;
}

/*********************************************************************
** Function evaluate_roll()
** Description: prints out the possible options for the user
** Parameters:int pointer tally array
*********************************************************************/
void evaluate_roll(int *tally_array){
  if(is_straight(tally_array) == true){
    cout<<"you have a straight (1500 points)"<<endl;
  }
  else if(is_three_pairs(tally_array) == true){
    cout<<"you have three pairs (1500 points)"<<endl;
  }
  else if(is_quad_plus_two(tally_array) == true){
    cout<<"you have four of a kind and a pair (1500 points)"<<endl;
  }
  else if(is_two_triples(tally_array) == true){
    cout<<"you have two triples (2500 points)"<<endl;
  }
  else if(is_six(tally_array) == true){
    cout<<"you have 6 of a kind (3000 points)"<<endl;
  }
  else if(is_five(tally_array) == true){
    cout<<"you have 5 of a kind (2000 points)"<<endl;
    //check if other one is a one or five
  }
  else if(is_quad(tally_array) == true){
    cout<<"you have 4 of a kind (1000 points)"<<endl;
    //check if other two have one or five or both
  }
  else if(is_single_triple(tally_array) == true){
    int location = find_triple(tally_array);
    int score2;
    if(location != 0){
      score2 = (location + 1) * 100;
    }
    else{
      score2 = 300;
    }
    cout<<"you have a triple of "<<location+1<<"'s' ("<<score2<<" points) "<<endl;
    //CHECK IF THERE ARE OTHER SINGLES IN NOT FOUND DICE
  }
  else if(has_one(tally_array) == true){
    cout<<"you have at least one 1 (100 points)"<<endl;
    //CHECK FOR TWO ONES THAT CAN BE SCORED SEPARATELY
  }
  else if(has_five(tally_array)== true){
    cout<<"you have at least one 5 (50 points)"<<endl;
    //CHECK FOR TWO FIVES THAT CAN BE SCORED SEPARATELY
  }
}

/*********************************************************************
** Function player_turn()
** Description: simulates one persons full turn
** Parameters:
**post-condiditon: one person's turn is taken
*********************************************************************/
int player_turn(){
  string input;
  int storage_temp_score;
  int *temp_score = &storage_temp_score;
  int *dice_roles = new int[6];
  int tally_array[6];
  int *rerolled;
  initialize(dice_roles, 6);
  roll_dice(6,dice_roles);
  print_dice(dice_roles,6);
  convert_to_tally(dice_roles,tally_array,6);
  evaluate_roll(tally_array);
  if (has_val(tally_array) == true){
    do{
      do{
        cout<<"\n";
        cout<<"would you like to reroll any dice? (1 for yes, 2 for no)"<<endl;
        cin>>input;
      }while(is_int(input) == false && (stoi(input) != 1 || stoi(input) != 2));
        //yes they want to reroll and can
        if(stoi(input) == 1){
            rerolled = reroll(dice_roles,tally_array,temp_score);
            //cout<<"OUT OF REROLL"<<endl;
            evaluate_roll(tally_array);
            if(is_a_farkle(rerolled, tally_array) == true){
              cout<<"you got a farkle, you get 0 points"<<endl;
              temp_score = 0;
              delete[]dice_roles;
              return 0;
            }
        }
        //no they dont want to reroll
        else if(stoi(input) == 2){
            //out<<"got here"<<endl;
            calculate_score(dice_roles, temp_score, tally_array);
            cout<<"score this round: "<<*temp_score<<endl;
            if(is_a_farkle(rerolled, tally_array) == true){
              cout<<"you got a farkle, you get 0 points"<<endl;
              temp_score = 0;
              delete[]dice_roles;
              return 0;
            }
          delete[]dice_roles;
          return *temp_score;
        }
      }while(true);
    }
    else{
      cout<<"you got a farkle, you get 0 points"<<endl;
      delete[]dice_roles;
      return 0;
    }
  }

  /*********************************************************************
  ** Function find_highest()
  ** Description: finds the highest of the scores to find a winner
  ** Parameters: global scoreboard, and the length of the scoreboard
  *********************************************************************/
int find_highest(int *score, int score_length){
  int highest = 0;
  for(int i  = 1; i < score_length; i++){
    if(score[i] > score[highest]){
      highest  = i;
    }
  }
  return highest;
}

int main(){
  int *player_num = new int;
  int *temp_score = new int;
  *temp_score = 0;
  int count = 0;
  *player_num = num_of_players();
  int *score = new int;
  *score = *player_num;
  initialize(score, *player_num);
  int turn = 0;
  do{
    for(int i = 0; i < *player_num; i++){
      cout<<"it is player "<<i + 1<<"'s turn"<<endl;
      *temp_score = player_turn();
      if (*temp_score > 500){
        score[i] += *temp_score;
      }
      else{
        cout<<"you didnt have enough points to save to the scoreboard for this turn."<<endl;
      }
      if (score[i] >= 10000){
        count = 100000 - *player_num;
      }
      cout<<"\n";
      cout<<"NEXT TURN"<<endl;
      cout<<"\n";
      cout<<"total scoreboard"<<endl;
      print_dice(score,*player_num);
    }
  }while(count < 100000);
  int highest = find_highest(score, *player_num);
  cout<<"congratulations player "<<highest +1<<" you won with "<<score[highest]<<" points"<<endl;
  cout<<"thanks for playing!!"<<endl;
  delete temp_score;
  delete score;
  delete player_num;
  return 0;
}
