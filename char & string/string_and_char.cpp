#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <string>
using namespace std;

int main() {
	cout << "===========stack will not overflow here, but will overflow after===========" << endl;
	char str2[] = {'a','b'};
	strcat(str2,"dsa");
	cout << str2 << endl;
	
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
	
	char * str = new char[100]; //it's a pointer a array of char or (actually its a string)  <==roughly but not the same, especially for multi-dimentional pointer with multi-dimentional array===> char * str = new char[100]
	strcat(str,"asd"); // it will automatically extend the size of array because str is dynamically allocated
	cout << str << endl;
	cout << str[0] << endl;
	
	cout << "==========append string===========" << endl;
	x.append("appending");
	x.append("e"); //only string allowed
	cout << x << endl;
	
	
	cout << "==========string find substring===========" << endl;
	string str4 = "ababababcbc";
	int ind1 = str4.find("bcb");
	cout << ind1 << " is the first matching pattern, and the first index of the searched patter" << endl;
	cout << "it can find string with \"pattern\"(can be a string or a single letter\"b\"), or a single char using \'b\'" << endl;
	delete[] myChar;
	
	cout << "===========stack \"may\" overflow here, but will overflow at the top===========" << endl;
	char str3[] = {'a','b'};
	strcat(str3,"dsa");
	cout << str3 << endl;
	
	cout << "==========string compare strcmp()============" << endl;
	string str5 = "abcdefg";
	string str6 = "abcdefg";
	cout << str5.compare(str6) << endl; 
	//return 0 if the same, otherwise not the same
	
	cout << "==========use char pointer as a string============" << endl;
	char * charString = new char[100]; //can give without initialized  size of char array in heap, then it will concatenate with other contiguous memroy in heap (problematic)
	// charString = {"asd"}; //not legal, but ok
	//alternatively, use charString.strcat("asd")
	strcat(charString, "abcdefg");
	cout << charString << endl;
	return 0;
}