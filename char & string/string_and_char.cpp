#include <iostream>
// #include <String>
using namespace std;

int main() {
	string x = "1234567890";
	cout << "===========sub string============" << endl;
	string y = x.substr(2,8); //this will take the index 2 as the beginning and the next 8 elements which including the element on index 2, and the second parameter can go above the bound of the x size, but it will just take the sub string of the maximum string size.
	cout << x << endl;
	cout << y << endl;
	
	cout << "===========initialize string with same chars============" << endl;
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
	cout << "length of my char: " << strlen(myChar) << endl;
	
	cout << "==========use of strcat function============" << endl;
	//container must be a char array, or a pointer
	strcat(myChar, "eee");
	cout << myChar << endl;
	
	cout << "==========append string===========" << endl;
	x.append("appending");
	cout << x << endl;
	
	delete[] myChar;
	return 0;
}