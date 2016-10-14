#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <string.h>
using namespace std;

int main() {

	cout << "=========check upper case==========" << endl;
	char x = 'A';
	if (isupper(x)) {
		cout << "upper case A" << endl;
	}
	x = 'a';
	if (!isupper(x)) {
		cout << "lower case a" << endl;
	}
	if (islower(x)) {
		cout << "lower case a" << endl;
	}
	x = 'A';
	if (!islower(x)) {
		cout << "upper case A" << endl;
	}
	cout << "=========upper to lower case==========" << endl;
	char y = tolower('A'); //if it is already lower case, do nothing
	cout << "upper A to lower case: " << y <<endl;
	
	cout << "=========lower to upper case==========" << endl;
	char z = tolower('a'); //if it is already lower case, do nothing
	cout << "lower A to upper case: " << z <<endl;
	return 0;
	
}