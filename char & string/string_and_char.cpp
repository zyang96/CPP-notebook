#include <iostream>
// #include <String>
using namespace std;

int main() {
	string x = "1234567890";
	string y = x.substr(2,10-2); //This will go from third of x string to last element. and 10 is the length of the whole x (not the index of the last element), 2 is the beginning "INDEX" of the starting substring
	cout << x << endl;
	cout << y << endl;
	
	cout << "===========initialize string with same char============" << endl;
	string a(10,'a');
	cout << a << endl;
	
	cout << "==========size of string============" << endl;
	cout << "size of the string is " << a.size() << endl;
	
	
	cout << "==========size of char pointer============" << endl;
	char * myChar = new char[3];
	myChar[0] = 'a';
	myChar[1] = 'b';
	myChar[2] = 'c';
	cout << *(myChar+1)<< endl;
	cout << strlen(myChar) << endl;
	
	delete[] myChar;
	return 0;
}