#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//=========================================
// start from 0,0 to n-1, n-1


int main() {
	cout << "==================2 dimention array===============" << endl;
	int rowCount = 10;
	int** ary = new int*[rowCount];
	for(int i = 0; i < rowCount; ++i)
	    ary[i] = new int[rowCount];
	ary[0][0] = 10;
	cout << ary[0][0] << endl;
	
	cout << "==================3 dimention array===============" << endl;
	int dim1 = 10;
	int dim2 = 10;
	int dim3 = 10;
	int *** arr = new int**[10];
	for (int i = 0; i < dim1; i++) {
		arr[i] = new int*[dim2];
		for (int j = 0; j < dim3; j++) {
			arr[i][j] = new int[dim3];
		}
	}
	for (int i = 0; i < dim1; i++) {
		for (int j = 0; j < dim2; j++) {
			for (int k = 0; k < dim3; k++) {
				arr[i][j][k] = k + 1 + j * dim2 + i * dim1 * dim1;
			}
		}
	}
	// print
	for (int i = 0; i < dim1; i++) {
		for (int j = 0; j < dim2; j++) {
			for (int k = 0; k < dim3; k++) {
				cout << arr[i][j][k] << endl;
			}
		}
	}
	return 0;
}