#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
using namespace std;
//=========================================
class myClass {
public:
	int a, b;
	myClass(int aa, int bb) : a(aa), b(bb) { //shortcut for constructor, don't use a = aa
		cout << "tested" << endl;
	}
};
int main() {
	myClass obj(1,2);
	cout << "=================shortcut constructor=========================" << endl;
	cout << obj.a << " " << obj.b << endl;
}
