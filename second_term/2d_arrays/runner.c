#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int **prompt_input(){
  int width = 0;
  int length = 0;
  int j = 0;
  int to_add;
  int c = 0;
  do{
    printf("width: \n");
    scanf("%d",&width);
    printf("length: \n");
    scanf("%d",&length);
  }while(length <= 0 || width > 10 || length > 10 || width<= 0);
  int **array = (int**) malloc(sizeof(int *)* width);
  for(j = 0; j < width; j++){
    array[j] = (int *)malloc(sizeof(int) * length);
  }
  populate_array(length,width,array);
  print_array(length,width,array);
  to_add = get_new_value();
  add_to_array(length,width,to_add,array);
  print_array(length,width,array);
  return array;
  for(c = 0; c < width; c++){
    free(array[c]);
  }
  free(array);
}

void populate_array(int length, int width, int **array){
  int i = 0;
  int b = 0;
  for(i = 0; i < width; i++){
    for(b = 0; b < length; b++){
        array[b][i] = (rand()% 50) + 1;
    }
  }
}

void add_to_array(int length, int width,int to_add, int **array){
  int i = 0;
  int b = 0;
  for(i = 0; i < width; i++){
    for(b = 0; b < length; b++){
      array[b][i] = array[b][i] + to_add;
    }
  }
}

int get_new_value(){
  int input;
  do{
    printf("number to add: \n");
    scanf("%d",&input);
  }while(input < 0 || input > 10);
  return input;
}

void print_array(int length, int width, int **array){
  int i = 0;
  int b = 0;
  for(i = 0; i < width; i++){
    for(b = 0; b < length; b++){
      printf("[%d] ",array[i][b]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(){
  srand(time(0));
  int **array = prompt_input();
  return 0;
}
