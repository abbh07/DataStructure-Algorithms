#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_common_substring(string s1, string s2)
{
	int l1 = s1.size();
	int l2 = s2.size();
	vector< vector<int> > t(l1+1, vector<int> (l2+1));

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				t[i][j] = t[i-1][j-1] + 1;
			}
			else
			{
				t[i][j] = 0;
			}
		}
	}
	int result = INT_MIN;
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			result = max(result,t[i][j]);
		}
	}
	return result;
}

int main()
{
	string s1 = "abcdaf";
	string s2 = "zbcdf";
	cout<<longest_common_substring(s2,s1)<<endl;
	return 0;
}