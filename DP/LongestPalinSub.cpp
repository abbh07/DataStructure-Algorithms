#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lps(string s)
{
	int len = s.size();

	vector< vector<int> > t(len, vector<int> (len));
	for(int i=0;i<len;i++)
	{
		t[i][i] = 1;
	}

	for(int l = 1;l<len;l++)
	{
		for(int i= 0;i<len-l;i++)
		{
			int j = i + l;

			if(l == 1 && s[i] == s[j])
			{
				t[i][j] = 2;
			}
			else if(s[i] == s[j])
			{
				t[i][j] = t[i+1][j-1] + 2;
			}
			else
			{
				t[i][j] = max(t[i][j-1], t[i+1][j]);
			}
		}
	}

	return t[0][len-1];
}

int main()
{
	string s = "agbdba";
	cout<<lps(s)<<endl;
	return 0;
}