#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string,long> my_map;
	
	//Different ways to insert values into a map
	my_map["Aakash"] = 140911418;
	my_map.insert(pair<string,long>("Suvimal",140911394));
	my_map.insert(make_pair("Aman",140911358));

	my_map.erase("Aakash");

	for(auto i = my_map.begin();i!=my_map.end();i++)
	{
		cout<<i->first<<" : "<<i->second<<endl;
	}

	//Counting occurences of a character in a string
	//This technique is useful in many string related problems
	string s;
	cin>>s;
	map<char,int> char_map;

	for(int i=0;i<s.length();i++)
	{
		char_map[s[i]]++;
	}
	for(auto i = char_map.begin();i!=char_map.end();i++)
	{
		cout<<i->first<<" : "<<i->second<<endl;
	}
	cout<<char_map.size()<<endl;
	cout<<char_map.empty()<<endl;
	char_map.clear();
	cout<<char_map.empty()<<endl;

	cout<<"Multimap:\n";
	//Multimap allows duplicate keys
	multimap<char,int> m;
	m.insert(make_pair('a',1));
	m.insert(make_pair('a',2));
	m.insert(make_pair('b',3));
	m.insert(make_pair('c',2));

	/*Not allowed
	m['a'] = 1;
	m['a'] = 2;
	m['b'] = 3;
	m['c'] = 2;
	*/

	cout<<m.count('a')<<endl;
	cout<<m.count('b')<<endl;
	cout<<m.count('c')<<endl;

	for(auto i =m.begin();i!=m.end();i++)
	{
		cout<<i->first<<" : "<<i->second<<endl;
	}
	m.clear();

	return 0;
}