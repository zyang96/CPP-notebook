#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <string>
using namespace std;

int main()
{
	int a = 12;
	string x = to_string(a);
	x.append("asd");
	string y;
	y = x.substr(0,2);
	char *xx = new char; //xx has to be a C string (connected array with enough space, could be dynamic or static assigned. Dynamic is better, because it won't  have stack overflow issue)
	xx = strcat(xx,"sdasddassd"); //return a pointer to xx, can give a new pointer, or just give back to xx itself
	cout << x << endl;
	cout << y << endl;
	cout << xx << endl;
	cout << *xx << " " << *(xx+1) << endl;
}
