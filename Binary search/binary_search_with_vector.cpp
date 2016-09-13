//Binary search // return -1 if not found, return index if found
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> origin = {0,12,21,32,152,211,311,511,611,811,822,833,844,851,1000};
    int index,maxIndex = origin.size()-1,minIndex = 0;
	double target = 150;
    index = maxIndex/2;
	int preMaxIndex = maxIndex;
	int preMinIndex = minIndex;
    while (origin[index] != target && maxIndex != minIndex) {
		if(origin[index] < target)
		{
			minIndex = index+1;
			index = (maxIndex+index)/2;
		}
		else
		{
			maxIndex = index-1;
			index = (index+minIndex)/2;
		}
		if(preMaxIndex == maxIndex && preMinIndex == minIndex)
		{
			index = -1;
			cout << index;
			return 0;
		}
		preMaxIndex = maxIndex;
		preMinIndex = minIndex;
    }
	if(maxIndex == minIndex)
	{
		if(origin[maxIndex]==target)
		index = maxIndex;
		else
			index = -1;
	}
	cout << index;
	return 0;
}