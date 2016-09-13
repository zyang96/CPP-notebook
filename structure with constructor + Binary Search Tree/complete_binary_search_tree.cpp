// Binary search tree with node insertion, node search
#include <iostream>

using namespace std;
struct bstNode
{
	double value;
	bstNode * leftNode;
	bstNode * rightNode;
	bstNode(double val = 0,bstNode * lNode = NULL, bstNode * rNode = NULL): value(val), leftNode(lNode), rightNode(rNode) // assign values
	{
		//do things
	}
};

bstNode* createNewNode(double val)
{
	bstNode* newNode = new bstNode(val);
	return newNode;
}
bstNode* insertNode(bstNode* root, double val)
{
	if(root == NULL)
	{
		root = createNewNode(val);
	}
	
	else if(root->value < val)
	{
		root->rightNode = insertNode(root->rightNode,val);
	}
	else
	{
		root->leftNode = insertNode(root->leftNode,val);
	}
	return root;
}

bstNode* findMinNodeOnRightTree(bstNode* root)
{
	cout << "find the min node value = "<< root->value << endl;
	while(root->leftNode != NULL)
		root = root->leftNode;
	cout << "find the min node value = "<< root->value << endl;

	return root;
}
bstNode* remove(bstNode* root, double target)
{
	if(root == NULL)
	{
	}
	else if(root->value < target)
	{
		root->rightNode = remove(root->rightNode,target);
	}
	else if(root->value > target)
	{
		root->leftNode = remove(root->leftNode,target);
	}
	else
	{
		//case 1, the node fount is a leaf
		if(root->leftNode == NULL && root->rightNode == NULL)
		{
			delete root; //root is a pointer to the Node that has the target value => deallocate that Node (free the memory in heap for that found Node pointed by root)
			root = NULL; // root pointer point to NULL
		}
		//case 2(a), found node with a right single tree
		else if(root->leftNode == NULL)
		{
			bstNode* mid = root;
			root = root->rightNode;
			delete mid;
			mid = NULL;
		}
		//case 2(b), found node with a left single tree
		else if(root->rightNode == NULL)
		{
			bstNode* mid = root;
			root = root->leftNode;
			delete mid;
			mid = NULL;
		}
		//case 3, found node has 2 children
		else
		{
			bstNode* minNode = findMinNodeOnRightTree(root->rightNode);
			root->value = minNode->value;
			root->rightNode = remove(root->rightNode,minNode->value);
		}
	}
	return root;
}
void findNode(bstNode* root, double target)
{
	if(root->value == target)
	{
		cout << 0;
	}
	else if(root->value < target)
	{
		cout << "r";
		findNode(root->rightNode,target);
	}
	else
	{
		cout << "l";
		findNode(root->leftNode,target);
	}
}
int main()
{
	bstNode * root;
	root = NULL;
	root = insertNode(root,100);
	root = insertNode(root,210);
	root = insertNode(root,11);
	root = insertNode(root,90);
	root = insertNode(root,50);
	root = insertNode(root,70);
	root = insertNode(root,151);
	root = insertNode(root,91);
	root = insertNode(root,300);
	root = insertNode(root,510);
	root = insertNode(root,51);
	root = insertNode(root,23);
	root = insertNode(root,41);
	root = insertNode(root,21);
	root = insertNode(root,1);
	root = insertNode(root,96);
	root = insertNode(root,80);
	root = insertNode(root,92);
	root = insertNode(root,64);
	root = insertNode(root,1000);
	root = insertNode(root,310);
	root = insertNode(root,340);
	
	// cout << root->leftNode->rightNode->leftNode->rightNode->leftNode->rightNode->value;
	findNode(root,310);
	cout<<endl;
	root = remove(root,510);
	findNode(root,1000);
	// cout<<endl;
	// findNode(root,340);
}