//O(n!)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void permute_string(string s, vector<int> &count, vector<char> &result, int level, vector<string> &result_list)
{
	if(level == result.size())
	{
		string temp(result.begin(),result.end());
		result_list.push_back(temp);
		return;
	}
	for(int i=0;i<s.size();i++)
	{
		if(count[i] == 0)
		{
			continue;
		}
		result[level] = s[i];
		count[i]--;
		permute_string(s,count,result,level+1,result_list);
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
	vector<string> result_list;
	permute_string(s,count,result,0,result_list);
	for(int i=0;i<result_list.size();i++)
	{
		cout<<result_list[i]<<endl;
	}
	return 0;
}