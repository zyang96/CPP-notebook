#include <iostream>
#include <time.h>
using namespace std;


int main() {
	// generate random number by using srand and time(NULL)
	srand(time(NULL));
	cout << (double)((rand()%10000)/10000) << endl;
	cout << (double)(rand()%10000)/10000 << endl;
	cout << ((double)(rand()%100000))/100000 << endl;
	return 0;
}

