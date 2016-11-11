#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;
/*
Will be stored in static/global memory. It will kept in the whole lifecycle of the program. During the program, it will not be destroyed

1. use as global variable declaration
global variable has larger scope, because it can be accessed by linker to share with other files

static global has smaller scope, which can only be accessed by the current file, which is called file scope

2. use in function. It will only be initialized once and will be accessible everytime the function has been called again.
3. use as class member, will be shared by all the instance.
*/
//=========================================

static int globalVariabel(100);

int foo() {
	static int output = 10;
	return output++;
}

int main() {
	cout << "==================1. using it as global variable===============" << endl;
	cout << globalVariabel << endl;
	cout << "==================2. static variable in function ===============" << endl;
	for (int i = 0; i < 5; i++)
		cout << foo() << endl;
	cout << "==================3. member of class (has to be shown in separate header and main function)===============" << endl;


	return 0;
}