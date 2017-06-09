//O(2^n)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void print_str(vector<char> v, int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<v[i];
	}
	cout<<endl;
}

void string_subset(string s, vector<int> &count, int pos, vector<char> &result, int len)
{
	print_str(result,len);
	for(int i=pos;i<s.size();i++)
	{
		if(count[i] == 0)
			continue;
		result[len] = s[i];
		count[i]--;
		string_subset(s,count,i,result,len+1);
		count[i]++;
	}
}

int main()
{
	string s = "cbaa";
	map<char,int> m;
	int l = s.size();	
	vector<char> result(l);
	for(int i=0;i<s.size();i++)
	{
		m[s[i]]++;
	}
	s = "";
	int j = 0;
	vector<int> count(m.size());
	for(auto i=m.begin();i!=m.end();i++)
	{
		s += i->first;
		count[j++] = i->second;
	}
	string_subset(s,count,0,result,0);
	return 0;
}