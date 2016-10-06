#include <iostream>
#include <queue>
#include <time.h>
using namespace std;

//======for customized class priority queue========
class Toast
{
public:
	int bread;
	int butter;

	Toast(int bread, int butter)
		: bread(bread), butter(butter)
	{

	}
};
// define comparator for customized class
struct ToastCompare
{
	bool operator()(const Toast &t1, const Toast &t2) const
	{
		int t1value = t1.bread * 1000 + t1.butter;
		int t2value = t2.bread * 1000 + t2.butter;
		return t1value < t2value;
	}
};
//=========================================
int main() {
	// default priority queue, sorted by larger number at top, smaller at bottom
	cout << "=====default priority queue========" << endl;
	srand(time(NULL));
	priority_queue<int> defaultQ;
	for (int i = 0; i < 10; i++) {
		defaultQ.push(rand()%100);	
	}
	for (int i = 0; i < 10; i++) {
		cout << defaultQ.top() << endl;
		defaultQ.pop();
	}
	
	cout << "=====customized priority queue type 1========" << endl;
	priority_queue<int, vector<int>> customQ1;
	for (int i = 0; i < 10; i++) {
		customQ1.push(rand()%100);	
	}
	for (int i = 0; i < 10; i++) {
		cout << customQ1.top() << endl;
		customQ1.pop();
	}
	
	cout << "=====customized priority queue type 2========" << endl;
	priority_queue<int, vector<int>, greater<int>> customQ2;
	for (int i = 0; i < 10; i++) {
		customQ2.push(rand()%100);	
	}
	for (int i = 0; i < 10; i++) {
		cout << customQ2.top() << endl;
		customQ2.pop();
	}
	
	cout << "=====customized priority queue type 3========" << endl;
	priority_queue<int, vector<int>, less<int>> customQ3;
	for (int i = 0; i < 10; i++) {
		customQ3.push(rand()%100);	
	}
	for (int i = 0; i < 10; i++) {
		cout << customQ3.top() << endl;
		customQ3.pop();
	}
	
	cout << "=====customized priority queue type 4========" << endl;
	struct myComparator1 //standard approach
	{
	  bool operator()(const int& x1, const int& x2) const
	  {
	    return x1 > x2; //smaller on top
	  }
	};

	struct myComparator2
	{
	  bool operator()(int x1, int x2)
	  {
	    return x1 < x2; //larger on top
	  }
	};
	priority_queue<int, vector<int>, myComparator1> customQ4;
	for (int i = 0; i < 10; i++) {
		customQ4.push(rand()%100);
	}
	for (int i = 0; i < 10; i++) {
		cout << customQ4.top() << endl;
		customQ4.pop();
	}
	
	cout << "=====priority queue with customized class========" << endl;
	cout << "priority queue comparator need use struct and define a bool operator inside comparator" << endl;
	cout << "and the comparison is the opposite of the vector comparator" << endl;
	cout << " priority_queue<int, vector<int>, comparator>" << endl;
	Toast toast1(2, 200);
	Toast toast2(1, 30);
	Toast toast3(1, 10);
	Toast toast4(3, 1);

	//priority_queue<Toast> queue;
	priority_queue<Toast, vector<Toast>, ToastCompare> queue;

	queue.push(toast1);
	queue.push(toast2);
	queue.push(toast3);
	queue.push(toast4);

	while (!queue.empty())
	{
		Toast t = queue.top();
		cout << "bread " << t.bread << " butter " << t.butter << std::endl;
		queue.pop();
	}
	return 0;
}

