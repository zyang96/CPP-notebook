// This program use merge sort to sort a sequence of numbers
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> arr);
void printVector(vector<int> * vec)
{
	for(auto itr : *vec)
	{
		cout << itr << endl;
	}
}
int main() {
	vector<int> sequence,ret;
	int arraySize = 1000000;
	for(int i=0; i<arraySize; i++) 
	{
		sequence.push_back(rand());
	}
	// printVector(&sequence);
	
	clock_t begin = clock();
	cout << "start" << endl;
   ret = mergeSort(sequence);
	clock_t end = clock();
	double elapsed_time = double(end - begin);
	cout << elapsed_time/1000000 << " sec" <<endl;
	// cout << "after sorting" << endl;
	// printVector(&ret);
	
	
	return 0;
}

vector<int> mergeSort(vector<int> arr)
{
	int arraySize = arr.size();
	vector<int> subArray1, subArray2,ret,ret1,ret2;
	if(arraySize > 1)
	{
		int mid;
		if(arraySize%2 == 0)
		{
			mid = arraySize/2-1;
		}
		else
		{
			mid = arraySize/2;
		}
		subArray1.insert(subArray1.begin(),arr.begin(), arr.begin()+mid+1);
		subArray2.insert(subArray2.begin(),arr.begin()+mid+1,arr.end());
		ret1 = mergeSort(subArray1);
		ret2 = mergeSort(subArray2);
	}
	else
	{
		ret.push_back(arr[0]);
		return ret;
	}
	for(int i=0; i<arraySize; i++)
	{
		
		if(ret1.size() != 0 && ret2.size() != 0 && ret1.front() <= ret2.front())
		{
			ret.push_back(ret1.front());
			ret1.erase(ret1.begin());
		}
		else if(ret1.size() != 0 && ret2.size() != 0 && ret1.front() > ret2.front())
		{
			ret.push_back(ret2.front());
			ret2.erase(ret2.begin());
		}
		else if(ret1.size() == 0 && ret2.size() != 0)
		{
			ret.push_back(ret2.front());
			ret2.erase(ret2.begin());
		}
		else if(ret2.size() == 0 && ret1.size() != 0)
		{
			ret.push_back(ret1.front());
			ret1.erase(ret1.begin());	
		}
	}
	return ret;
}