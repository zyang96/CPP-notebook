// This program use insertion sort to sort a sequence of numbers
#include <iostream>
#include <ctime>

using namespace std;

void insertionSort(int* arr, int arraySize);

int main() {
	srand(time(NULL));
	int arraySize = 10;
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
    insertionSort(sequence, arraySize);
	for (int i=0;i<arraySize;i++)
	{
		cout<<sequence[i]<<endl;
	}
	

	return 0;
}


void insertionSort(int* arr, int arraySize)
{
	int currentIndex;
	for(currentIndex = 1; currentIndex< arraySize; currentIndex++)
	{
		int currentHolder = arr[currentIndex];
		for(int i = currentIndex; i >= 0; i--)
		{
			if (i == 0) {
				arr[i] = currentHolder;
			}
			if(currentHolder<arr[i-1])
			{
				arr[i] = arr[i-1];
			}
			else
			{
				arr[i] = currentHolder;
				break;
			}
		}
	}
}