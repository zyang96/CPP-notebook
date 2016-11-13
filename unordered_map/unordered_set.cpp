#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
int main()
{
	unordered_set<string> myset = {"red", "green", "blue"};
	unordered_set<string>::iterator itr = myset.find ("gresen");
	if (itr != myset.end()) // if doesnt find, return the end ,searching using iterator in unordered_set
		cout << *itr << endl; // iterator can be accessed as pointer
	myset.insert("yellow");
	vector<string> vec = {"purple", "pink", "pink"}; // can push repeted elements
	myset.insert(vec.begin(),vec.end()); // insert by vector
	cout << "load factor = " << myset.load_factor() << endl;
	string x= "pink";
	cout << x << " is in bucket #" << myset.bucket(x) << endl;
	cout << "total bucket #" << myset.bucket_count() << endl;
	

//************iterating over unordered_set*********
	
	unordered_set<string> myset1 = {"red", "green", "blue"};
	for (unordered_set<string>::iterator itr = myset1.begin(); itr != myset1.end(); itr++) {
		cout << *itr << endl;
	}
//************indexing unordered_set or unordered_map*********
	cout << "===============indexing the unordered_set or map (opposite order as the order inserted in)===========" << endl;
	unordered_set<string>::iterator itr111101 = next(myset1.begin(), 0);
	cout << *itr111101 << endl;
	itr111101 = next(myset1.begin(), 1);
	cout << *itr111101 << endl;
	itr111101 = next(myset1.begin(), 2);
	cout << *itr111101 << endl;
	
	cout << "=========================================" << endl;

//************Delete single element*********
	//remove by itr
	itr = myset1.find("green");
	myset1.erase(itr);
	for (unordered_set<string>::iterator itr = myset1.begin(); itr != myset1.end(); itr++) {
		cout << *itr << endl;
	}
	//remove by element
	myset1.erase("blue");
	for (unordered_set<string>::iterator itr = myset1.begin(); itr != myset1.end(); itr++) {
		cout << *itr << endl;
	}
	
//************ clear set && check empty unordered_set*********
	myset1.clear();
	if (myset1.empty()) cout << "is empty" << endl;
	else cout << "not empty" << endl;
//************accessing element's function use (*itr) *********
	itr = myset.find("green");
// 	cout << (*itr).size() << endl; //parenthesis is required to access the function of the *itr, and it is general for all iterators
	cout << "================swap two set or map=========================" << endl;
	unordered_set<string> st1113171;
	unordered_set<string> st1113172;
	swap(st1113171, st1113172);
	
	return 0;
}
