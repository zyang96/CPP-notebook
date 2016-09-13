#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int * maxDepth = new int[3];
	*maxDepth = 100;
	*(maxDepth+1) = 2000;
	maxDepth[2] = 50;
	cout << *(maxDepth+1) << endl;
	cout << maxDepth[2] << endl;
	
	int * anotherVal = new int(123);
	cout << *anotherVal << endl;
	
	int x = 10;
	/*&x is also a pointer don't forget that!!!*/
	int * x_p = &x; 
	cout << *x_p << endl;
	cout << *&x << endl;
	return 0;
}