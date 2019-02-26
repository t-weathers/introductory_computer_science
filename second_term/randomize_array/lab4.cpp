#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void randomize_array(int *array, int len, int upperbound,int lowerbound){
	for(int i = 0; i < len; i++){
		array[i] = (rand() % (upperbound - lowerbound) + lowerbound);
	}
	for(int i = 0; i < len; i++){
		if(array[i] < 300)
			array[i] += 10;
	}
	for(int i = 0; i< len; i++){
		//#ifdef DEBUG
		cout<<"["<<array[i]<<"] ";
		//#endif
	}
	cout<<endl;
}

int main(){
	srand(time(NULL));
	int *a = new int[10];
	randomize_array(a,10,400,200);
	delete [] a;
	return 0;
}
