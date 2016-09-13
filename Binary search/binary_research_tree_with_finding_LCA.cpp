// Binary search tree with node insertion, node search, find LCA
#include <iostream>

using namespace std;
struct bstNode
{
	double value;
	bstNode * leftNode;
	bstNode * rightNode;
	bstNode(double value = 0,bstNode * lNode = NULL, bstNode * rNode = NULL): value(value), leftNode(lNode), rightNode(rNode) // assign values
	{
		//do things
	}
};

bstNode* createNewNode(double value)
{
	bstNode* newNode = new bstNode(value);
	return newNode;
}
bstNode* insertNode(bstNode* root, double value)
{
	if(root == NULL)
	{
		root = createNewNode(value);
	}
	
	else if(root->value < value)
	{
		root->rightNode = insertNode(root->rightNode,value);
	}
	else
	{
		root->leftNode = insertNode(root->leftNode,value);
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
bstNode* findNode(bstNode* root, double target) // returns the pointer to the found node
{
	bstNode* ret;
	if(root->value == target)
	{
		cout << 0;
		return root;
	}
	else if(root->value < target)
	{
		cout << "r";
		ret = findNode(root->rightNode,target);
	}
	else
	{
		cout << "l";
		ret = findNode(root->leftNode,target);
	}
	return ret;
}
bstNode* findLCA(bstNode* root, bstNode* p, bstNode* q) // used to find lowest common ancestor of a binary search tree
{
	while((root->value <= p->value) == (root->value <= q->value))
	{
		if(root->value == p->value)
		{
			return root;
		}
		else if(root->value == q->value)
		{
			return root;
		}
		if(root->value < p->value)
		{
			root = root->rightNode;
		}
		else
		{
			root = root->leftNode;
		}
	}
	return root;
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
	bstNode * p = findNode(root,64);
	bstNode * q = findNode(root,91);
	cout << endl << findLCA(root,p,q)->value; // returns the LCA of two nodes
	

}

