// Binary search tree
#include <iostream>

using namespace std;
struct bsTree
{
	double value;
	bsTree * leftTree;
	bsTree * rightTree;
	bsTree(double val = 0,bsTree * lTree = NULL, bsTree * rTree = NULL): value(val), leftTree(lTree), rightTree(rTree) // assign values
	{
		//do things
	}
};

int main()
{
	bsTree * root;
	root = new bsTree;
	
}