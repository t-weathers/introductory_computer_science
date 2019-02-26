#include "./mult_div.h"
using namespace std;

bool is_valid_diminsions(char *m, char *n){
  bool output = false;
  bool a = false;
  bool b = false;
  if(*m >= 49 && *m <= 57){
    a = true;
  }
  if (*n >= 49 && *n <= 57){
  b = true;
  }
  if (a == true && b == true){
    output = true;
  }
  return output;
}

mult_div_values** create_table(int m, int n){
  mult_div_values** matrix = new mult_div_values*[m];
  for(int i = 0; i < m; i++){
    matrix[i] = new mult_div_values[n];
  }
  return matrix;
}

void set_mult_values(mult_div_values **table, int m, int n){
  for(int i = 0; i < m;i++){
    for(int b = 0; b < n; b++){
      (table[i][b]).mult = (i+1) * (b+1);
    }
  }
}

void set_div_values(mult_div_values **table, int m, int n){
  for(int i = 0; i < m;i++){
    for(int b = 0; b < n; b++){
      (table[i][b]).div = (i+1) * (1/((float)(b+1)));
    }
  }
}

void delete_table(mult_div_values **table, int m){
  for(int i = 0; i < m; i++){
    delete [] table[i];
  }
  delete [] table;
}

void print_mult_table(mult_div_values **table, int m, int n){
  cout<<"multiplication table"<<endl;
  cout<<"\n";
  for(int i = 0; i < m;i++){
    for(int b = 0; b < n; b++){
      cout<<(table[i][b]).mult;
      cout<<"  ";
    }
    cout<<'\n';
  }
}
void print_div_table(mult_div_values **table, int m, int n){
  cout<<"division table"<<endl;
  cout<<"\n";
  for(int i = 0; i < m;i++){
    for(int b = 0; b < n; b++){
      cout<<setprecision(2)<<(table[i][b]).div;
      cout<<"  ";
    }
    cout<<'\n';
  }
}

void set_new(int *row, int *col){
  int rowtemp = 0;
  int coltemp = 0;
  do{
    cout<<"please give a valid row: "<<endl;
    cin>>rowtemp;
    cout<<"please give a valid col: "<<endl;
    cin>>coltemp;
  }while((rowtemp < 0 || rowtemp > 9) || (coltemp < 0 || coltemp > 9));
  *row=rowtemp;
  *col=coltemp;
}
