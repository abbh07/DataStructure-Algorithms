#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool word_break(string &s, unordered_set<string> &dict)
{
	int l = s.size();
	vector<bool> t(l+1);
	t[0] = true;
	for(int i=1;i<=l;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(t[j] && dict.count(s.substr(j, (i-j) ) ) )
			{
				t[i] = true;
				break;
			}
		}
	}

	return t[l];
}

int main()
{
	string s = "Iamace";
	unordered_set<string> dict;
	dict.insert("I");
	dict.insert("a");
	dict.insert("am");
	dict.insert("ace");
	cout<<word_break(s,dict)<<"\n";
	return 0;
}