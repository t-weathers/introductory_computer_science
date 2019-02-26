#include <iostream>
#include <string>

using namespace std;

void add(int *a, int *b){
  *a = *a + *b;
  *b = *b + *a;
}
void addstring(string *a, string *b){
  *a += *b;
  *b += *a;
}

void multiply(float *a, float *b){
  *a *= *b;
  *b *= *a;
}


int main(){
  int *a = new int;
  int *b = new int;
  *a = 1;
  *b = 2;
  add(a,b);
  cout<<"a: "<<(*a)<<endl;
  cout<<"b: "<<(*b)<<endl;

  string *c = new string;
  string *d = new string;
  *c = "hello";
  *d = "hi";
  addstring(c,d);
  cout<<"c: "<<(*c)<<endl;
  cout<<"d: "<<(*d)<<endl;

  float *e = new float;
  float *f = new float;
  *e = 3.45;
  *f = 4.51;
  multiply(e,f);
  cout<<"e: "<<(*e)<<endl;
  cout<<"f: "<<(*f)<<endl;

  delete a;
  delete b;
  delete c;
  delete d;
  delete e;
  delete f;

  return 0;
}
