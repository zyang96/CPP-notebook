// This program use merge sort to sort a sequence of numbers
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void quickSort(vector<int> &arr, int left, int right);
void printVector(vector<int> * vec)
{
	for(auto itr : *vec)
	{
		cout << itr << endl;
	}
}
int main() {
	vector<int> sequence,ret;
	int arraySize = 10;
	for(int i=0; i<arraySize; i++) 
	{
		sequence.push_back(rand() % 100);
	}
	// printVector(&sequence);
	
	clock_t begin = clock();
	cout << "start" << endl;
	quickSort(sequence, 0, arraySize - 1);
	ret = sequence;
	clock_t end = clock();
	double elapsed_time = double(end - begin);
	cout << elapsed_time/1000000 << " sec" <<endl;
	cout << "after sorting" << endl;
	printVector(&ret);
	
	
	return 0;
}

void quickSort(vector<int> &arr, int left, int right) {
	int pivot = arr[left + (right - left) / 2];
	int i = left, j = right;
	while (i <= j) {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j) swap(arr[i++], arr[j--]);
	}
	if (left < j) quickSort(arr, left, j);
	if (right > i) quickSort(arr, i, right);
}

// void quickSort(vector<int> &arr, int left, int right)
// {
// 	int pivot = arr[(left + right) / 2];
// 	int i = left, j = right;
// 	while (i <= j) {
// 		while (arr[i] < pivot) i++;
// 		while (arr[j] > pivot) j--;
// 		if (i <= j) {
// 			int temp = arr[i];
// 			arr[i] = arr[j];
// 			arr[j] = temp;
// 			i++;
// 			j--;
// 		}
// 	}
// 	if (left < j) quickSort(arr, left, j);
// 	if (i < right) quickSort(arr, i, right);
// }