#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;

int main() {


	int bytes;
	cout <<"how many bytes? : " <<endl;

	cin >> bytes;

	int maxS = pow(2,bytes - 1);
	int minS = pow(2,bytes - 1) - 1;
	int minUn = 0;
	int maxUn = pow(2,bytes) - 1;


	cout <<"min number (signed): " << minS <<endl;
	cout <<"max number (signed): "<< maxS << endl;
	cout << "min number (unsigned): " << minUn <<endl;
	cout << "max number (unsigned): " << maxUn <<endl;




	//Part 2
	
	int x;
	srand(time(NULL));

	x = rand();
	cout << "x = " << x << endl;
	
	int output = x % 6;
	
	cout << "random number is: " << output << endl;
	
	if(output == 0){
		cout << "Bummer, I'm zero" << endl;
	}
	else{
		if(output % 2 == 1 ){
			cout << "i'm an odd number" << endl;
		}
		else{
			cout << "i'm an even number" << endl;
		}
	}
	return 0;
}
