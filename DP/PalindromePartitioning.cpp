#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_cut(string &s)
{
	int l = s.size();
	if(l == 0)
	{
		return 0;
	}
	int cut[l];
	bool t[l][l];
	int minval = 0;
	for(int i=1;i<l;i++)
	{
		minval = i;
		for(int j=0;j<=i;j++)
		{
			if(s[i] == s[j] && (i < j+1 || t[i-1][j+1]))
			{
				t[i][j] = true;
				minval = min(minval,(j==0 ? 0 : 1+cut[j-1]));
			}
		}
		cut[i] = minval;
	}
	return cut[l-1];
}

int main()
{
	string s = "abcbm";
	cout<<min_cut(s)<<"\n";
	return 0;
}