#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;
/*
detailed explanation:
http://en.cppreference.com/w/cpp/language/enum

An enumeration is a distinct type whose value is restricted to a range of values (see below for details), 
which may include several explicitly named constants ("enumerators"). The values of the constants are values 
of an integral type known as the underlying type of the enumeration.


Each enumerator is associated with a value of the underlying type. When initializers are provided in the enumerator-list, the values of enumerators are defined by those initializers. If the first enumerator does not have an initializer, the associated value is zero. For any other enumerator whose definition does not have an initializer, the associated value is the value of the previous enumerator plus one.
*/
//===============build a enum without value assigned==========================
enum Color {
	red, // 0
	green, // 1
	blue // 2
};

//===============build a enum with value assigned==========================
enum Foo { a, b, c = 10, d, e = 1, f, g = f + c };
//a = 0, b = 1, c = 10, d = 11, e = 1, f = 2, g = 12



int main() {
	cout << "==================make a instance of enum===============" << endl;
	Color r = red;
	switch(r)
	{
	    case red  : std::cout << "red\n";   break;
	    case green: std::cout << "green\n"; break;
	    case blue : std::cout << "blue\n";  break;
	}

	return 0;
}