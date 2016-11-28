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
	
	
	cout << "===================lower bound===================" << endl;
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=70;
	mymap['z']=80;
	mymap['e']=100;
	
	// comparating the key not the value
	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('c');   // itup points to d (not !c)
	cout << "itup points to d not c's value, itup->second = mymap['d'] =" << itup->second << endl;
	// if mymap.upper_bound('z'), it will points to mymap.end();
	if (mymap.upper_bound('z') == mymap.end()) cout << "it cannot find a upper bound that is larger than mymap['z'] = 80" << endl;

	mymap.erase(itlow,itup);        // erases [itlow,itup) // exclude itup

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	return 0;
	
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