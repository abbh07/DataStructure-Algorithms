#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool regex_match(string str, string pattern)
{
	int l1 = str.size();
	int l2 = pattern.size();
	vector< vector<bool> > t(l1+1, vector<bool> (l2+1));
	t[0][0] = true;
	//For a*b* like cases which matches with an empty string
	for(int i=1;i<=l2;i++)
	{
		if(pattern[i-1] == '*')
		{
			t[0][i] = t[0][i-2];
		}
	}

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(str[i-1] == pattern[j-1] || pattern[j-1] == '.')
			{
				t[i][j] = t[i-1][j-1];
			}
			else if(pattern[j-1] == '*')
			{
				t[i][j] = t[i][j-2];
				if(str[i-1] == pattern[j-2] || pattern[j-2] == '.')
				{
					t[i][j] = t[i][j] || t[i-1][j];
				}
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
	string str = "xaabyc";
	string pattern = "xa*b.c";
	//str = "";
	//pattern = "a*b*";
	//str = "abbbbccc";
	//pattern = ".*bcc*";
	cout<<regex_match(str,pattern)<<endl;
	return 0;
}