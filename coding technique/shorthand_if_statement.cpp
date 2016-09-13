//short hand if statement : (condition) ? (if_true) : (if_false)
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;


int main()
{
	int i=2;
	int j = 3;
	i > j ? i = i: i=j;
	cout << i << endl;
	return 0;
}