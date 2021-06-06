#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(string &s1, string &s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	vector< vector<int> > T(l1+1, vector<int> (l2+1));
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0 || j==0)
			{
				T[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1])
			{
				T[i][j] = T[i-1][j-1] + 1;
			}
			else
			{
				T[i][j] = max(T[i-1][j], T[i][j-1]);
			}
		}
	}
	return T[l1][l2];
}

int main()
{
	string s1;
	cout<<"Enter the first string:\n";
	cin>>s1;
	string s2;
	cout<<"Enter the second string:\n";
	cin>>s2;
	cout<<"Length of the longest common subsequence: "<<lcs(s1,s2)<<endl;
	return 0;
}