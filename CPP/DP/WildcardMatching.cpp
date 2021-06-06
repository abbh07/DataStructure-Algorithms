#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool wildcard_match(string str, string pattern)
{
	int l1 = str.size();
	int l2 = pattern.size();
	
	//Remove multiple * from the pattern 
	//a***b is same as a*b
	bool isfirst = true;
	int index = 0;
	for(int i=0;i<l2;i++)
	{
		if(pattern[i] == '*')
		{
			if(isfirst)
			{
				pattern[index++] = pattern[i];
				isfirst = false;
			}
		}
		else
		{
			pattern[index++] = pattern[i];
			isfirst = true;
		}
	}
	l2 = index;

	vector< vector<bool> > t(l1+1,vector<bool>(l2+1,false));
	//Empty string matches empty pattern
	t[0][0] = true;

	if(pattern[0] == '*')
	{
		t[0][1] = true;
	}

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
			{
				t[i][j] = t[i-1][j-1];
			}
			else if(pattern[j-1] == '*')
			{
				t[i][j] = t[i-1][j] || t[i][j-1];
			}
			else
			{
				t[i][j] = false;
			}
		}
	}
	return t[l1][l2];

}

int main()
{
	string str = "xaylmz";
	string pattern = "x?y*z";
	//str = "ab";
	//pattern = "a***b";
	cout<<wildcard_match(str,pattern)<<endl;
	return 0;
}