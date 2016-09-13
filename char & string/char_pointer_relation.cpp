#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	char *myString0 = new char[3];
	// char myString1[5] = {'s','a','c','w','g'};
	// char myString2[] = {'s','a','c','w','g'};
	
	cout << "size of char array: " << sizeof(myString0) << endl; //size of a type (a pointer is 8 bit)
	
	myString0[0] = 'a';
	myString0[1] = 'b';
	myString0[2] = 'c';
	string string2 = "qweqw";
	*myString0 = 'p';
	// myString0 = "dsadasds";
	
	int len = strlen(myString0);
	// myString[0] = 's';
	// myString[1] = 'e';
	cout << "size of char array: " << len << endl;
	cout << "size of char array: " << myString0.length() << endl;
	cout << myString0 << endl;
	cout << string2 << endl;
	// cout << size(myString0) << endl;
	// myString0 = NULL;
	delete[] myString0;
	cout << INT_MAX<<endl;
}