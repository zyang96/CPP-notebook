#include <iostream>
#include <vector>
using namespace std;

//cout << "=================== =======================" << endl;
bool comp1(int a, int b) {
	return abs(a) < abs(b); //sorting by absolute value from smaller to larger
}

bool comp2(int a, int b) {
	return abs(a) > abs(b); //sorting by absolute value from larger to smaller
}

int main() {
	int arr[6] = {1,2,3,-5,-2,-4};
	vector<int> vec;
	vec.assign(arr, arr + sizeof(arr)/sizeof(int));
	
	cout << "===================sort vector with comp =======================" << endl;
	sort(vec.begin(), vec.end(), comp1);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	
	cout << "===================sort array with comp =======================" << endl;
	sort(arr, arr+sizeof(arr)/sizeof(int), comp2);
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
