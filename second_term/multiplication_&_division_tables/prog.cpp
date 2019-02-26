#include "mult_div.h"
using namespace std;

int main(int argc, char** argv){
  int rows = 0;
  int cols = 0;
  int input = -1;
  if(is_valid_diminsions(argv[1],argv[2])){
    rows=atoi(argv[1]);
    cols=atoi(argv[2]);
  }
  else{
    set_new(&rows, &cols);
  }
  do{
    if(input == 0){
      set_new(&rows,&cols);
    }
    mult_div_values **table = create_table(rows,cols);
    input = -1;
    set_mult_values(table,rows,cols);
    set_div_values(table,rows,cols);
    print_mult_table(table,rows,cols);
    print_div_table(table,rows,cols);
    delete_table(table,rows);
    cout<<"would you like to see a different size matrix? (0 for yes, 1 for no)"<<endl;
    cin>>input;
  }while(input == 0);
  return 0;
}
