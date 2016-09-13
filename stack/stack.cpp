// 7 functions
// pop, push, size, swap, top,empty,emplace(similar to push but make no temporary copy of the pushed item)
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> x;
	x.push(1);
	x.emplace(2);
	x.push(3);
	x.push(4);
	x.emplace(5);
	cout << "size of the stack: " << x.size() << endl;
	while(!x.empty())
	{
		cout << x.top() << endl;
		x.pop();
	}
	
}