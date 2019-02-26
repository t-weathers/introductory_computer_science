#include <iostream>
#include <sys/time.h>
#include <cstdlib>
using std::cout;
using std::endl;
using namespace std;

int fib_iter(int n){
  int output = 0;
  int minus2 = 1, minus1 = 1;
  if (n == 0){
    return 0;
  }
  if (n == 1 || n == 2){
    return 1;
  }
  for(int i  = 3; i <n; i++){
    int temp = minus2;
    minus2 += minus1;
    minus1 = temp;
  }
  output = minus1 + minus2;
  return output;
}

int fib_recur(int n){
  if(n == 0){
    return 0;
  }
  if(n == 1 || n == 2){
    return 1;
  }
  return fib_recur(n-1) + fib_recur(n -2);
}

int staircounter(int n){
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return 1;
  }
  if(n == 2){
    return 2;
  }
  return staircounter(n-1) + staircounter(n -2);
}



int main(){
  int input;
  cout<<"give a stair number: "<<endl;
  cin>>input;

  /*typedef struct timeval time;
  time stop, start;
  cout<<"iterative: "<<endl;
  gettimeofday(&start, NULL);
  cout<<fib_iter(input)<<endl;
  gettimeofday(&stop, NULL);
  if(stop.tv_sec > start.tv_sec)
    cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
  else
    cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;

  cout<<"recursive: "<<endl;
  gettimeofday(&start, NULL);
  cout<<fib_recur(input)<<endl;
  gettimeofday(&stop, NULL);
  if(stop.tv_sec > start.tv_sec)
    cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
  else
    cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
    */
  cout<<staircounter(input)<<endl;
  return 0;
}
