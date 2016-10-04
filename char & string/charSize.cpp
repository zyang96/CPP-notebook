#include <iostream>
#include <vector>
using namespace std;
//=========================================
void testArray (int array[], int * pt) { //array[] and *pt can both be deemed as pointer to the int array head
	cout <<array << endl;
	cout << pt << endl;
	cout <<*array << endl;
	cout << pt[0] << endl;
	cout <<array[0] << endl;
	cout << *(pt+1) << endl;
}
int main() {
	int array[] = {1,3,1,1,1};
	for (int i:array) {
		cout << i << " ";
	}
	cout << endl;
	cout << sizeof(array)/sizeof(int);
	cout << endl;
	cout << *array << endl;
	cout << *(array+1) << endl;
	testArray(array, array);
	return 0;
}