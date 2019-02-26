#include <stdlib.h>
#include<exception>
#include <stdexcept>


template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }

      ~vector(){
	     delete [] v;
      }

      int size() {
	     return s;
      }

      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }

vector(vector<T> &other){
		this->s = other.s;
		v = new T[s];
		for(int i = 0; i < other.s; i++){
			this->v[i] = other.v[i];
		}

}
void operator=(vector<T> &other){
		if(v != NULL){
			delete [] v;
		}
		s = other.s;
		v = new T[s];
		for(int i = 0; i < other.s; i++){
			v[i] = other.v[i];
		}
}

T operator [] (int a){
    return v[a];
}

T at(int a){
    if(a>=s || a <0){
      throw std::out_of_range("out of vector bounds");
    }
    else
      return v[a];
  }

};
