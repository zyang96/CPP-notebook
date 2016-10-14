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
	string aString(10,'a');
	cout << aString << endl;
	
	cout << "==========size of string============" << endl;
	cout << "size of the string is " << aString.size() << endl;
	
	
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
	
	
	cout << "===========stack \"may\" overflow here, but will not overflow at the top===========" << endl;
	char str3[] = {'a','b'};
	strcat(str3,"dsa");
	cout << str3 << endl;
	
	cout << "==========string compare()============" << endl;
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
	
	cout << "==========use strlen() to find length of char array (string is not allowed)=======" << endl;
	char myName[] = "my name is Zhongtao";
	char name1[] = {'a','b','c'};
	char * name2 = new char[100];
	strcat(name2, "char pointer dynamically initialized");
	cout << "the length of char array myName is " << strlen(myName) << endl;
	cout << "the length of char array name1 is " << strlen(name1) << endl;
	cout << "the length of char array name2 is " << strlen(name2) << endl;
	
	cout << "=========strcmp to compare two char arrays==========" << endl;
	char a[] = "sameCharArray";
	char b[] = "sameCharArray";
	cout << strcmp(a,b) << endl;
	cout << "=========strcmp to compare one char array and a string==========" << endl;
	cout << strcmp(a,"sameCharArray") << endl; //***cannot take a single char
	
	cout << "=========strcmp to compare one char array pointers==========" << endl;
	char *aa = new char[10];
	char *bb = new char[10];
	strcat(aa, "sameCharArray");
	strcat(bb, "sameCharArray");
	cout << strcmp(aa, bb) << endl;
	cout << "=========strcmp to compare one char array and char array pointer==========" << endl;	
	cout << strcmp(aa, aa) << endl;
	
	cout << "====assign char array pointer with char one by one and printed as a full string=====" << endl;
	char *c = new char[2]; //insufficient allocation
	c[0] = 'C';
	c[1] = 'H';
	c[2] = 'N';
	cout << c << endl;
	
	cout << "===========string.find()============" << endl;
	string s1 = "asd";
	cout << "if found, return index of the first found sub string" << endl;
	cout << s1.find("s") << endl;
	cout << "if it cannot find, it return a largest number in long long type" << endl;
	cout << s1.find("b") << endl;
	
	cout << "==========string find substring===========" << endl;
	string str4 = "ababababcbc";
	int ind1 = str4.find("bcb");
	cout << ind1 << " is the first matching pattern, and the first index of the searched patter" << endl;
	cout << "it can find string with \"pattern\"(can be a string or a single letter\"b\"), or a single char using \'b\'" << endl;

	cout << "==========indexing string elemnt is a char===========" << endl;
	string string10141 = "abcdefg";
	if (string10141[0] == 'a') {
		cout << "the first element is a" << endl;
	}
	cout << "==========reverse a string===========" << endl;
	reverse(string10141.begin(), string10141.end());
	cout << string10141 << endl;
	
	return 0;
}