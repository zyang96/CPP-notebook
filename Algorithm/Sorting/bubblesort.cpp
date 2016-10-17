// This program use insertion sort to sort a sequence of numbers
#include <iostream>
#include <ctime>

using namespace std;

void bubbleSort(int* arr, int arraySize);

int main() {
	srand(time(NULL));
	int arraySize = 10;
	int sequence[arraySize];
	for(int i=0; i<arraySize; i++) // generate a sequence with 100 length
	{
		sequence[i] = rand()%1000;
	}
	for (int i=0;i<arraySize;i++)
	{
		cout<<sequence[i]<<endl;
	}
	
	cout <<"\nnewsequence"<<endl;
    bubbleSort(sequence, arraySize);
	for (int i=0;i<arraySize;i++)
	{
		cout<<sequence[i]<<endl;
	}
	

	return 0;
}


void bubbleSort(int* arr, int arraySize)
{
	int finishedTill = arraySize-1;
	while(finishedTill > 0) 
	{
		for(int i=0; i < finishedTill; i++)
		{
			if(arr[i]>arr[i+1])
			{
				int mid = arr[i];
				arr[i] = arr[i+1];
				arr[i+1]  =mid;
			}
		}
		finishedTill--;
	}
}