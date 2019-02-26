#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int stoi(string input){
        int val;
        int res = 0;
        for(int i = (input.length()-1); i >= 0; i--) {
                val = ((int) input[i]) - 48;
                res +=  val * pow(10,(input.length() - i -1));
        }
}

void print_array(int **array, int initial_disk){
  for(int i = 0; i < initial_disk; i++ ){
    for(int b = 0; b < 3; b++){
      cout<<array[i][b];
      cout<<" ";
    }
    cout<<"\n";
  }
  cout<<"-----"<<endl;
}

void move(int initial_disk, int disks, int **b, int from_col, int to_col){
  int initrow;
  int recievingrow;
  for(int i = 0; i < initial_disk ; i++){
    if(b[i][from_col] != 0){
      initrow = i;
      break;
    }
  }
  for(int i = 0; i < initial_disk - 1; i++){
    if(b[i+1][to_col] != 0){
      recievingrow = i;
      break;
    }
    if(i == initial_disk - 2 && b[i+1][to_col] == 0){
      recievingrow = i + 1;
      break;
    }
  }
  int temp = b[initrow][from_col];
  b[initrow][from_col] = 0;
  b[recievingrow][to_col] = temp;

}

void towers(int initial_disk, int disks, int **b, int from_col, int to_col, int spare){
  if(disks >= 1){
     towers(initial_disk, disks-1, b, from_col, spare, to_col);
     move(initial_disk, disks,b,from_col,to_col);
     print_array(b, initial_disk);
     towers(initial_disk, disks-1, b, spare, to_col, from_col);
  }
}


int main(int argc, char** argv){
  int disks = stoi(argv[1]);
  cout<<"[TOWERS OF HANOI]"<<endl;
  cout<<"\n";
  int **board;
  board = new int*[disks];
  for(int i = 0; i < disks; i++){
    board[i] = new int[3];
  }
  cout<<"\n"<<endl;
  for(int rows = 0; rows < disks; rows++){
    for(int collumns = 0; collumns < 3; collumns++){
      if(collumns == 0){
        board[rows][collumns] = rows +1;
      }
      else{
        board[rows][collumns] = 0;
      }
    }
  }
  towers(disks, disks, board, 0,2,1);

  for(int i = 0; i < disks; i++){
    delete [] board[i];
  }
  delete[] board;
  return 0;
}
