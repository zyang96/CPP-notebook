// vector
#include <iostream>
#include <unordered_map>
#include <vector>
#include <typeinfo>

using namespace std;
void printVec(vector<int> vec) {
	for (auto itr : vec) {
		cout << itr << " ";
	}
	cout << endl;
}
bool cmp(const int& a, const int& b) {
    return a > b;
}
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> vec,first, second, third, fourth, fifth;
	vec.assign(arr,arr+10); //Assign with array
	// cout << vec.size() << endl;
	vector<int>::iterator itrBegin, itrToThePoint, itrEndPointer, itrEndIndex, itrSearch;
	itrBegin = vec.begin();
	itrToThePoint = vec.begin()+5;
	itrEndPointer = vec.end()-1;
	itrEndIndex = vec.end();
	cout << "begin() itr = " << *itrBegin << " itrEndPointer itr = "<< *itrEndPointer << " itrEndIndex itr = " << *itrEndIndex << endl;
	cout << endl;
	
	// assign vector with vector
	first.assign(itrBegin,itrEndIndex);//use itrator as index to load the vector with these index. vec.begin() no need to plus one, vec.end() need to -1
	second.assign(itrBegin,itrEndPointer);
	third.assign(itrBegin,itrToThePoint);
	cout << "size of vector with itrEndIndex : " << first.size() << endl;

	cout << "size of vector with itrEndPointer : " << second.size() << endl;
	
	cout << "size of vector with itrToThePoint : " << third.size() << endl;
	for (int i = 0; i < first.size(); i++)
	{
		cout << "endIndex column " << first[i] << "  endPointer column " << second[i] << " toThePinter Column " << third[i] << endl;
	}
	cout << endl;
	
	
	//Play with index for iterator
	fourth.assign(itrEndPointer, itrEndPointer + 1);
	cout << "size of fourth is " << fourth.size() << " with value = " << fourth.front() << endl;
	cout << endl;
	
	
	// play with find (find is from std::)
	int target = 5;
	itrSearch = find(itrBegin, itrEndIndex, target);
	if (itrSearch == itrEndIndex) {
		cout << "could not find the value" << endl;
	}
	cout << "find the value = " << *itrSearch << endl;
	cout << "type of the itr is " << typeid(itrSearch).name() << endl;
	//find array[]
	int * arrayItr = find(arr, arr + 10, target); //****!!!!
	if (arrayItr == arr + 10) {
		cout << "could not find the value" << endl;
	}
	cout << "find the value = " << *arrayItr << endl;
	cout << "type of the itr is " << typeid(arrayItr).name() << endl;
	cout << endl;
	
	//Play with insert for both vector and array
	//insert one element, (push the previous one backward)
	vec.insert(vec.begin(), 100); //insert with begin() + 2, it's like put new value at index 2, and pushback the previous one to index 3
	vec.insert(vec.end(),200); //insert end(), it's like put a new elements at index = vec.size() or say add one at the back end. 
	vec.insert(vec.end()-1,300); //insert end() - 1, it's like insert new elements at index vec.size() - 1, and pushback the previous one to index vec.size()
	vec.insert(vec.begin() + 1,300);
	
	//insert repetitive elements
	vec.insert(vec.begin() + 5, 2,1000);
	
	//insert with an array
	int newArray[] = {50, 51, 52, INT_MAX};
	vec.insert(vec.begin(), newArray, newArray + 3); //insert array with array elements specified
	
	//insert with another vector
	vector<int> newVec(5,54321);
	vec.insert(vec.end() - 1, newVec.begin(), newVec.end() - 1);
	printVec(vec);
	cout << endl;
	
	//Reuse assign to the same vector, to see if it will be overwrite. Yes it will be overwritten
	newVec.assign(arr,arr+10);
	printVec(newVec);
	
	
	cout << "=========vector sorting=========" << endl;
	sort(vec.begin(), vec.end());
	printVec(vec);
	
	cout << "=========vector sorting by sorting comparator=========" << endl;
	sort(vec.begin(), vec.end(), cmp);
	printVec(vec);
	

	cout << "=========remove last element=========" << endl;
	vec.erase(vec.end() - 1);
	printVec(vec);
	
	cout << "=========remove second last element=========" << endl;
	vec.erase(vec.end() - 2);
	printVec(vec);
	
	cout << "=========remove first element=========" << endl;
	vec.erase(vec.begin());
	printVec(vec);
	
	cout << "=========remove last element by using pop_back()=========" << endl;
	vec.pop_back();
	printVec(vec);
	
	cout << "=========for loop iterating=========" << endl;
	for (vector<int>::iterator it = vec.begin() ; it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "=========front(), back() access element=========" << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	
	cout << "=========begin(), end() access iterators=========" << endl;
	cout << "it can be used for finding => if found, itr == end()" << endl;
	cout << "it can also be used to insert" << endl;
	vector<int>::iterator itr = vec.begin();
	cout << *itr << endl;
	itr = vec.end()-1;
	cout << *itr << endl;
	return 0;
}
