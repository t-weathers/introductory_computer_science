#include <iostream>
#include <string>
using namespace std;

int main() {
	string my_str;
	cout << "Please give a string without spaces: ";
	cin >> my_str;
	int length = my_str.length();
	bool flag = false;
	for(int i=0; i<(length/2); i++) {
		if (my_str.at(i) == my_str.at(length-(i+1))) {
			flag = true;
		}
	}
	if (flag == true) {
		cout << "It's a palindrome" << endl;
	}
	else {
		cout << "It's not a palindrome"<< endl;
	}

	return 0;
}
