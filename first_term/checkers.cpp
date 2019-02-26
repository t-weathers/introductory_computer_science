/*********************************************************************
** File Name: checkers.cpp
** Author: Thomas Weathers
** Description: creates a working w player version of checkers
** Input: user input the moves they would like to make by coordinate markings
** Output: the board is outputted to the user for their next moves
** Date: 3/17/18
*********************************************************************/
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
//player 1 is x (top)
//player 2 is o (bottom)

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
** Function: check_valid_cmdline
** Description: checks if command line arguments are valid, if not, prompts user for correct
*********************************************************************/
int check_valid_cmdline(char **array, int argc){
  string temp = "";
  int row = 0;
  string input = "";
  if (argc >= 2){
    temp += array[1][0];
    temp += array[1][1];
    row = stoi(temp);
  }
  if((row != 8 && row != 10 && row != 12) || strlen(array[1]) <= 1){
      do{
        cout<<"Please give a valid size of the board: (8,10 or 12)"<<endl;
        cin>>input;
      }while(stoi(input) != 8 && stoi(input)!= 10 && stoi(input)!= 12);
      row = stoi(input);
      cin.ignore();
    }
  return row;
}

/*********************************************************************
** Function: print_board
** Description: prints the complete board
*********************************************************************/
void print_board(char **board, int rows, int collumns){
  cout<<"   ";
  for(int b = 0; b < rows; b++){
    if (b + 1 >= 10)
      cout<<"  "<<b + 1;
    else
      cout<<"  "<<b + 1<<" ";
  }
  cout<<"\n";
  for(int i=0; i<rows; i++){
    cout<<(char)(i + 65)<<"  ";
    for(int j=0; j<collumns; j++) {
        if (i%2 == 0 && j%2 == 0){
          cout << "|\033[30;47m " << board[i][j] << " ";
        }
        else if (i%2 == 1 && j%2 == 1){
          cout << "|\033[30;47m " << board[i][j] << " ";
        }
        else
          cout << "|\033[0m "<< board[i][j] << " ";
        cout << "\033[0m";
      }
      cout << endl;
    }
  }

  /*********************************************************************
  ** Function: initialize_board
  ** Description: initializes the board with spaces to fill it to its capacity
  *********************************************************************/
void initialize_board(char **board, int rows, int collumns){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < collumns; j++){
      board[rows] = new char[rows];
      board[i][j] = ' ';
    }
  }
}

//populate with 'x' and 'o'
/*********************************************************************
** Function: first_populate
** Description: populates the board with x's and o's in their appropriate locations
*********************************************************************/
void first_populate(char **board, int rows, int collumns){
    for(int i = 0;i < rows - (rows / 2 + 1); i++){
      for(int l = 0; l < rows; l++){
        if((i + l) % 2 == 1){
          board[i][l] = 'x';
        }
      }
    }
    for(int b = rows - (rows/ 2 - 1); b < rows; b++){
      for(int k = 0; k < rows; k++){
        if((b + k) % 2 == 1){
          board[b][k] = 'o';
        }
      }
    }
}

/*********************************************************************
** Function: count_pieces
** Description: counts the pieces of the given character to determine if the game is over
*********************************************************************/
int count_pieces(char piece,char **board, int rows, int collumns){
  int count = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < collumns; j++){
      if (board[i][j] == piece){
        count++;
      }
    }
  }
  return count;
}

//will produce [1,1,0,5,5]
//takes in an already approved cstring of coordinates
//need to be uppercase
/*********************************************************************
** Function: parse_move
** Description: parses a move into an oputput integer array of the locations on the board in index values
*********************************************************************/
int *parse_move(int *output, char *fullstring){
  for(int x = 0; x < strlen(fullstring); x++){
  }
  cout<<endl;
  output[5];
  string temp = "";
  int location = 0;
  for(int i = 0; i < 5; i++){
    output[i] = 0;
  }
  output[0] = (int)(fullstring[0]) - 65;
  //one digit first y cord
  if(fullstring[2] == ' '){
    output[1] = (int)(fullstring[1]) - 49;
    location = 3;
  }
  //two digit first y cord
  else{
    temp += fullstring[1];
    temp += fullstring[2];
    output[1] = stoi(temp) - 1;
    location = 4;
  }
  temp = "";
  output[2] = 0;
  output[3] = (int)(fullstring[location]) - 65;
  //one digit second y coord
  if(fullstring[location + 2] == '\0'){
    output[4] = (int)(fullstring[location + 1]) - 49;
  }
  else{
    temp += fullstring[location + 1];
    temp += fullstring[location + 2];
    output[4] = stoi(temp) - 1;
  }
  return output;
}

/*********************************************************************
** Function: check_open
** Description: checks if a space on the board is free or not
*********************************************************************/
bool check_open(int *end, char** board){
  cout<<endl;
  if (board[end[0]][end[1]] == ' '){
    return true;
  }
  else{
    return false;
  }
}

//check for "X" or "O"
/*********************************************************************
** Function: check_if_king
** Description: checks if a piece on the board is a king or not
*********************************************************************/
bool check_if_king(int *location, char **board){
  if(board[location[0]][location[1]] == 'X' || board[location[0]][location[1]] == 'O'){
    return true;
  }
  else
    return false;
}

/*********************************************************************
** Function: grant_king
** Description: changes a piece to a kinge
**postcondition: piece is now a king
*********************************************************************/
void grant_king(int *location, char**board){
  if (board[location[0]][location[1]] == 'x'){
    board[location[0]][location[1]] = 'X';
  }
  else if(board[location[0]][location[1]] == 'O'){
    board[location[0]][location[1]] = 'O';
  }
}

/*********************************************************************
** Function: down_left_valid()
** Description: checks if a move down-left is valid or not
*********************************************************************/
bool down_left_valid(int *start, int *end, int player, char**board){
  if (player == 1){
    if(check_if_king(start,board) == false)
      return false;
  }
  if (end[0] == start[0] + 1 && end[1] == start[1] -1){
    if (check_open(end,board) == true)
      return true;
  }
  else if(end[0] == start[0] + 2 && end[1] == start[1] - 2){
    if(player == 0){
      if(board[end[0] + 1][end[1] - 1] == 'o' || board[end[0] + 1][end[1] - 1] == 'O'){
        if (check_open(end,board) == true)
          return true;
      }
    }
    if (player == 1){
      if(board[end[0] + 1][end[1] - 1] == 'x' || board[end[0] + 1][end[1] - 1] == 'X'){
        if (check_open(end,board) == true)
          return true;
      }
    }
  }
  return false;
}

/*********************************************************************
** Function: down_right_valid()
** Description: checks if a move down-right is valid or not
*********************************************************************/
bool down_right_valid(int  *start, int *end, int player, char**board){
  if (player == 1)
    if(check_if_king(start,board) == false)
      return false;
  if (end[0] == start[0] + 1 && end[1] == start[1]  + 1){
    if (check_open(end,board) == true)
      return true;
  }
  else if(end[0] == start[0] + 2 && end[1] == start[1] + 2){
    if(player == 0){
      if(board[end[0] + 1][end[1] + 1] == 'o' || board[end[0] + 1][end[1] + 1] == 'O'){
        if (check_open(end,board) == true)
          return true;
      }
    }
    if (player == 1){
      if(board[end[0] + 1][end[1] + 1] == 'x' || board[end[0] + 1][end[1] + 1] == 'X'){
         if (check_open(end,board) == true)
           return true;
      }
    }
  }
  return false;
}

/*********************************************************************
** Function: up_left_valid()
** Description: checks if a move up-left is valid or not
*********************************************************************/
bool up_left_valid(int *start, int *end, int player, char**board){
  if (player == 0)
    if(check_if_king(start,board) == false)
      return false;
  if (end[0] == start[0] - 1 && end[1] == start[1]  +-1){
    if (check_open(end,board) == true)
      return true;
  }
  else if(end[0] == start[0] - 2 && end[1] == start[1] - 2){
    if(player == 0){
        if(board[end[0] - 1][end[1] - 1] == 'o' || board[end[0] - 1][end[1] - 1] == 'O'){
          if (check_open(end,board) == true)
            return true;
        }
    }
    if (player == 1){
      if(board[end[0] - 1][end[1] - 1] == 'x' || board[end[0] - 1][end[1] - 1] == 'X'){
         if (check_open(end,board) == true)
           return true;
      }
    }
  }
  return false;
}

/*********************************************************************
** Function: up-up_right_valid()
** Description: checks if a move up-right is valid or not
*********************************************************************/
bool up_right_valid(int *start, int *end, int player, char**board){
  if (player == 0)
    if(check_if_king(start,board) == false)
      return false;
  if (end[0] == start[0] - 1 && end[1] == start[1] + 1){
      if (check_open(end,board) == true)
        return true;
  }
  else if(end[0] == start[0] - 2 && end[1] == start[1] + 2){
    if(player == 0){
      if(board[end[0] - 1][end[1] + 1] == 'o' || board[end[0] - 1][end[1] + 1] == 'O'){
        if (check_open(end,board) == true)
          return true;
      }
    }
    if (player == 1){
      if(board[end[0] - 1][end[1] + 1] == 'x' || board[end[0] - 1][end[1] + 1] == 'X'){
        if (check_open(end,board) == true)
          return true;
      }
    }
  }
  return false;
}

/*********************************************************************
** Function: check_correct_players_piece
** Description: this checks if the user is selecting the correct piece and if they can move it or not
*********************************************************************/
bool check_correct_players_piece(int *start, char **board, int player){
  if ((board[start[0]][start[1]] == 'o' && player == 0) || (board[start[0]][start[1]] == 'O' && player == 1)){
    cout<<"you are selecting a piece that is not yours"<<endl;
    return false;
  }
  if((board[start[0]][start[1]] == 'x' && player == 1) || (board[start[0]][start[1]] == 'X' && player == 1)){
    cout<<"you are selecting a piece that is not yours"<<endl;
    return false;
  }
  return true;
}

/*********************************************************************
** Function: initialize_start_and_end
** Description: changes a location array into smmaller start and end arrays
*********************************************************************/
void initialize_start_and_end(int *start, int *end, int *full_locations){
  start[0] = full_locations[0];
  start[1] = full_locations[1];
  end[0] = full_locations[3];
  end[1] = full_locations[4];
}

/*********************************************************************
** Function: valid_move
** Description: determines if a move is valid by calling many other boolean functions
**precondition: move is parsed into locations of integers with a 0 in betweem
*********************************************************************/
bool valid_move(int *locations, int player, char **board){
  int *start = new int[2];
  int *end = new int[2];
  initialize_start_and_end(start,end,locations);
  if (check_correct_players_piece(start,board,player) == true){
    //up left
    if(end[0] < start[0] && end[1] < start[1]){
      return up_left_valid(start,end,player,board);
    }//up left
    if (end[0] < start[0] && end[1] > start[1]){
      return up_right_valid(start,end,player,board);
    }
    //down right
    if (end[0] > start[0] && end[1] > start[1]){
      return down_right_valid(start,end,player,board);
    }
    //down left
    if (end[0] > start[0] && end[1] < start[1]){
      return down_left_valid(start,end,player,board);
    }
  }
  delete start;
  delete end;

  return false;
}

/*********************************************************************
** Function: jumped_piece_position
** Description: finds the piece to remove in a jump
**precondition: is a valid move
*********************************************************************/
void jumped_piece_position(int *output, char **board, int *start, int *end){
  output[2];
  output[0] = -1;
  output[1] = -1;
  //up left
  if(end[0] == start[0] - 2 && end[1] == start[1] - 2){
    output[0] = start[0] - 1;
    output[1] = start[1] - 1;
  }//up left
  else if (end[0] == start[0] - 2 && end[1] == start[1] + 2){
    output[0] = start[0] - 1;
    output[1] = start[1] + 1;
  }
  //down right
  else if (end[0] == start[0] + 2 && end[1] == start[1] + 2){
    output[0] = start[0] + 1;
    output[1] = start[1] + 1;
  }
  //down left
  else if (end[0] == start[0] + 2 && end[1] == start[1] - 2){
    output[0] = start[0] + 1;
    output[1] = start[1] - 1;
  }
}

//removes piece at location given
/*********************************************************************
** Function: remove_jumped
** Description: removes the piece when it gets jumped over
**postcondition: the spot of the jumped piece is now empty
*********************************************************************/
void remove_jumped(char **board, int *position){
  board[position[0]][position[1]] = ' ';
}

//moves piece and replaces old space with empty
/*********************************************************************
** Function: move_piece()
** Description: moves a piece where it is intended, then deletes piece from origional space
**postcondition: piece's starting spot is not blank, piece is in new spot
*********************************************************************/
void move_piece(char **board, int *start, int *end){
  board[end[0]][end[1]] = board[start[0]][start[1]];
  board[start[0]][start[1]] = ' ';
}

/*********************************************************************
** Function: is_a_jump()
** Description: determines whether the user is making a jump or just moving
*********************************************************************/
bool is_a_jump(int *start, int *end){
  //jump up left
  if(end[0] == start[0] - 2 && end[1] == start[1] - 2){
    cout<<"jump UL"<<endl;
    return true;
  }
  //jump up right
  else if (end[0] == start[0] - 2 && end[1] == start[1] + 2){
    cout<<"jump UR"<<endl;
    return true;
  }
  //jump down right
  else if (end[0] == start[0] + 2 && end[1] == start[1] + 2){
    cout<<"jump DR"<<endl;
    return true;
  }
  //jump down left
  else if (end[0] == start[0] + 2 && end[1] == start[1] - 2){
    cout<<"jump DR"<<endl;
    return true;
  }
  return false;
}


/*********************************************************************
** Function: needs_to_be_kinged()
** Description: determines if a piece has been moved to a square that needs it to be kinged
*********************************************************************/
bool needs_to_be_kinged(int *end,char **board, int player, int rows){
  if (end[0] == 0 && player == 1)
    return true;
  else if ((end[0] == rows - 1) && player == 0){
    return true;
  }
  return false;
}

/*********************************************************************
** Function: string_to_cstring()
** Description: converts a string into a cstring of correct length()
**postcondition: charray is now the string a in  c string form
*********************************************************************/
void string_to_cstring(string a, char *charray){
  charray = new char[a.length()];
  for(int i = 0; i < a.length(); i++){
    charray[i] = a.at(i);
  }
  charray[a.length()] = '\0';
}

/*********************************************************************
** Function: player_turn()
** Description: this function simulates a full player turn of movement and checks for kingings
*********************************************************************/
void player_turn(char **board, int player, int rows, int collumns){
    string input;
    print_board(board,rows,collumns);
    char *move = new char[20];
    int *move_location = new int[5];
    int *start = new int[2];
    int *end = new int[2];
    int *jumped_piece = new int[2];
    cout<<"player "<<player + 1<<"'s turn"<<endl;
    do{
      cin.clear();
      cout<<"move:"<<endl;
      cin.getline(move,20);
      move_location = parse_move(move_location,move);
    }while(valid_move(move_location,player,board) != true);
    initialize_start_and_end(start,end,move_location);
    if(is_a_jump(start,end) == true){
      int *position = new int[2];
      jumped_piece_position(position,board,start,end);
      remove_jumped(board,position);
      delete position;
    }
    move_piece(board,start,end);
    if(needs_to_be_kinged(end,board,player,rows) == true){
      grant_king(end,board);
    }
    delete start;
    delete end;
    delete move;
    delete move_location;
    delete jumped_piece;
  }
  /*********************************************************************
  ** Function: delete_board()
  ** Description: deletes the board from existence
  *********************************************************************/

/*********************************************************************
** Function: delete_board
** Description: deletes the board from existence
*********************************************************************/
void delete_board(char **board){
  for(int i = 0; i < strlen(*board); i++){
    delete board[i];
  }
  delete board;
}

int main(int argc, char **argv){
  int *players = new int[2];
  players[0] = 0;
  players[1] = 1;
  int rows = check_valid_cmdline(argv,argc);
  int collumns = rows;
  char **board = new char*[collumns];
  for(int i = 0; i < rows; i++){
    board[i] = new char;
  }
  initialize_board(board,rows,collumns);
  first_populate(board,rows,collumns);
  while(true){
    for(int i = 0; i < 2; i++){
      if (count_pieces('x',board,rows,collumns) == 0 && count_pieces('X',board,rows,collumns) == 0 ){
        cout<<"player 2 has won the game"<<endl;
        break;
      }
      else if(count_pieces('o',board,rows,collumns) == 0 && count_pieces('O',board,rows,collumns) == 0){
        cout<<"player 1 has won the game"<<endl;
        break;
      }
      player_turn(board,players[i],rows,collumns);
    }
  }
  delete_board(board);
  return 0;
}
