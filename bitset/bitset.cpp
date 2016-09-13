// bitset<class> is a datatype that stores binary number, that can count how many bits in val.
#include <iostream>
using namespace std;
int main()
{
	bitset<32> b(10);
	cout << b << endl << "total numbers of 1's are :" << b.count();
}