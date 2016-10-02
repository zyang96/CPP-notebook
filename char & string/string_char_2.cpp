#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;
//=========================================
// start from 0,0 to n-1, n-1

int main() {
	string a = "abcdefg";
	int end = a.size() - 1;
	string b = a.substr(1,end);
	char str[] = {'1','2'}; //it's a pointer a array of char or (actually its a string)  <==roughly but not the same, especially for multi-dimentional pointer with multi-dimentional array===> char * str = new char[100]
	strcat(str,"asd"); // it will automaticallt extend the size of array because str is dynamically allocated
	cout << str << endl;
}
