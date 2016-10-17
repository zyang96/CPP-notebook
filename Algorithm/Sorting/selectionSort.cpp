// This program use insertion sort to sort a sequence of numbers
#include <iostream>
#include <ctime>

using namespace std;

void selectionSort(int* arr, int arraySize);

int main() {
	srand(time(NULL));
	int arraySize = 100000;
	int sequence[arraySize];
	for(int i=0; i<arraySize; i++) // generate a sequence with 100 length
	{
		sequence[i] = rand()%1000;
	}
	// for (int i=0;i<arraySize;i++)
	// {
	// 	cout<<sequence[i]<<endl;
	// }
	
	// cout <<"\nnewsequence"<<endl;
	clock_t begin = clock();
	cout << "start" << endl;
    selectionSort(sequence, arraySize);
	clock_t end = clock();
	double elapsed_time = double(end - begin);
	cout << elapsed_time/1000000 << " sec" <<endl;
	// for (int i=0;i<arraySize;i++)
	// {
	// 	cout<<sequence[i]<<endl;
	// }
	

	return 0;
}


void selectionSort(int* arr, int arraySize)
{
	// int *array = new int(arraySize);
	int smallIndex;
	for(int i=0; i<arraySize-1; i++) 
	{
		smallIndex = i;
		for(int j=i; j<arraySize; j++)
		{
			if(arr[j]<arr[smallIndex])
			{
				smallIndex = j;
			}
		}
		swap(arr[i],arr[smallIndex]);
	}
}