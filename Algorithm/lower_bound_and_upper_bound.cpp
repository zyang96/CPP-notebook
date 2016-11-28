#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
	cout << "==================lower_bound and upper_bound===============" << endl;
    int myints[] = {10,20,30,30,20,10,10,20};
    std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

    std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

    std::vector<int>::iterator low,up;
	// the lower bounnd that not less than 20
    low=std::lower_bound (v.begin(), v.end(), 20); // 
	//the uppe bound that are not greater than 20       ^
    up= std::upper_bound (v.begin(), v.end(), INT_MAX); //                   ^

    std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
	cout << "================== ===============" << endl;

	return 0;
}