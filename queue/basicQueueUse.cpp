#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	queue<int> myQ;
	for (int i = 0; i < 100; i ++) {
		myQ.push(i);
	}
	while (myQ.size() > 15) {
		cout << myQ.front() << " " << myQ.back() << endl;
		myQ.pop();
	}
	return 0;
}