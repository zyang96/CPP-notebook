//Single Linked list
#include <iostream>

using namespace std;
template<class T>
class Node
{
public:
	T data;
	Node<T> * next;
};

void insert(int newData, int location, Node<int> *head)
{
	Node<int> *t, *mid;
	t = head;
	for (int i = 0; i< location; i++)
	{
		t = t->next;
	}
	mid = t->next;
	t->next = new Node<int>;
	t->next->data = newData;
	t->next->next = mid;
}

void deletion(int location, Node<int> *head)
{
	Node<int> *t;
	t = head;
	for (int i = 0; i< location; i++)
	{
		t = t->next;
	}
	t->next = t->next->next;
}
int main()
{
	// need to define a struct/class (here I use class because of template)
	Node<int>* n; // new/next node
	Node<int>* t; // temperal node
	Node<int>* h; //head node
	n = new Node<int>;
	n->data = 0;
	t = n; // temperate points to the current node before move the n Node
	h = n; // head points to the first Node
	for (int i = 1; i < 100; i++)
	{
		n = new Node<int>; // move the n Node to the next Node
		n->data = i;
		t->next = n;
		t = t->next;
	}
	n->next = NULL;
	t = h;
	insert(10000,20,h);
	deletion(10,h);
	while(t!=NULL)
	{
		cout << t->data << endl;
		t = t->next;
	}
	return 0;
}
