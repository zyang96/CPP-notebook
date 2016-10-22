#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
	unordered_map<char,int> container = {{'s',12},{'b',21}};
	container.insert(make_pair('a',23));
	cout << container['s'] << endl;
	cout << container['a'] << endl;
	unordered_map<char,int>::iterator itr = container.find('a');
	if(itr != container.end())
	{
		cout << itr->first <<" " << itr->second << endl;
	}
	cout << container.begin()->first << endl;
	
	//============without using insertion==========
	unordered_map<int,char> map;
	map[1] = 's';
	map[2] = 'a';
	map[3] = 'd';
	cout << map[1] << endl;
	
}

// #include <string>
// #include <iostream>
// #include <unordered_map>
//
// int main ()
// {
//     std::unordered_map<int, std::string> dict = {{1, "one"}, {2, "two"}};
//     dict.insert({3, "three"});
//     dict.insert(std::make_pair(4, "four"));
//     dict.insert({{4, "another four"}, {5, "five"}});
//
//     bool ok = dict.insert({1, "another one"}).second;
//     std::cout << "inserting 1 -> \"another one\" "
//               << (ok ? "succeeded" : "failed") << '\n';
//
//     std::cout << "contents:\n";
//     for(auto& p: dict)
//         std::cout << " " << p.first << " => " << p.second << '\n';
// }