#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool string_interleaving(string &s1, string &s2, string &s3)
{
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if(n1+n2 != n3)
	{
		return false;
	}
	vector< vector<bool> > t(n1+1,vector<bool>(n2+1));
	t[0][0] = true;
	for(int i=1;i<=n1;i++)
	{
		if(s3[i-1] == s1[i-1])
		{
			t[i][0] = t[i-1][0];
		}
		else
		{
			t[i][0] = false;
		}
	}

	for(int i=1;i<=n2;i++)
	{
		if(s3[i-1] == s2[i-1])
		{
			t[0][i] = t[0][i-1];
		}
		else
		{
			t[0][i] = false;
		}
	}

	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s3[i+j-1] == s1[i-1])
			{
				t[i][j] = t[i-1][j];
			}
			else if(s3[i+j-1] == s2[j-1])
			{
				t[i][j] = t[i][j-1];
			}
			else
			{
				t[i][j] = false;
			}
		}
	}
	return t[n1][n2];
}

int main()
{
	string s1 = "axy";
	string s2 = "aab";
	string s3 = "aaxaby";
	cout<<string_interleaving(s1,s2,s3)<<"\n";
	return 0;
}