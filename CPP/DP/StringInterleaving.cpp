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
	
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			if(i == 0 && j == 0)
			{
				t[i][j] = true;
			}
			else if(i == 0)
			{
				if(s3[i+j-1] == s2[j-1])
				{
					t[i][j] = t[i][j-1];
				}
			}
			else if(j == 0)
			{
				if(s3[i+j-1] == s1[i-1])
				{
					t[i][j] = t[i-1][j];
				}
			}
			else
			{
				t[i][j] = (s3[i+j-1] == s1[i-1] ? t[i-1][j] : false) || (s3[i+j-1] == s2[j-1] ? t[i][j-1] : false);
			}
		}
	}
	return t[n1][n2];
}

int main()
{
	//string s1 = "axy";
	string s1 = "XXXXY";
	//string s2 = "aab";
	string s2 = "YXXXY";
	//string s3 = "aaxaby";
	string s3 = "XYXXXXYXXY";
	cout<<string_interleaving(s1,s2,s3)<<"\n";
	return 0;
}