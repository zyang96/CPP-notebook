#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;



void func(int *p, int *&rp) {
	p++;
	rp = rp + 1; //*** incremented based on size of int. if int type consists of 4 bytes, then ,it increases by 4 in memory address number (bytes based)
}
int main() {
	int val = 10;
	int * x = &val; // x is pointer to val
	cout << &val << endl; //val's memory address 
	cout << x << endl; // without dereferencying *, x is the memory address of pointed variable val.
	cout << *x << endl; //with dereferencing, it is the value in the memory address that x pointed to
	cout << &x << endl; //pointer x's memory address
	
	int ** y = &x; //pointer to the pointer x
	cout << y << endl; //without dereferencing, y is x's memory address
	cout << *y << endl; //with dereferencing, *y is the value in the memory address that y pointed to, which is x, the memory address of the val *y = x
	cout << **y << endl; // **y = *(*y) = *x = value of val
	
	//==============reference to pointer *&============
	int *a = &val;
	int *b = &val;
	cout << "before function call:" << endl;
	cout << "pointer a/b = " << a << " with pointed value of a/b= " << *a << endl;
	
	a[1] = 20; // this specify the value in the next int memory address
	func(a, b);
	cout << "after function call:" << endl;
	cout << "pointer a = " << a << " with pointed valoe of a = " << *a << endl;
	cout << "pointer b = " << b << " with pointed valoe of a = " << *b << endl;// it will point to a different memory address which is 4 bytes after the original, and the value in that address, *b, will be ramdom if not specified. If specified, it will be the specified value (e.g in line 33)
	return 0;
}

