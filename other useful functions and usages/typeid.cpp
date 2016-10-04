#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <string.h>
using namespace std;

int main() {

	cout << "=========check the type of the data typeinfo==========" << endl;
	string x = "asd";
	char * charArr = new char[100];
	strcat(charArr, "char pointer dynamically initialized");
	cout << "charArray type is "<< typeid(charArr).name() << endl;
	
	if (strcmp(typeid(charArr).name(), "Pc") == 0) {
			cout << "the charArr type matched as Pc" << endl;
	}
	return 0;
	
}