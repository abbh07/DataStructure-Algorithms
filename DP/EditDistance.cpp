#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(string s1, string s2)
{
	int l1 = s1.size();
	int l2 = s2.size();

	vector< vector<int> > t(l1+1, vector<int> (l2+1));
	
	for(int i=0;i<=l1;i++)
		t[i][0] = i;
	for(int i=0;i<=l2;i++)
		t[0][i] = i;

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				t[i][j] = t[i-1][j-1];
			}
			else
			{
				t[i][j] = min(t[i-1][j-1] , min(t[i][j-1], t[i-1][j])) + 1;
				//t[i][j] = min(t[i][j], t[i-1][j-1]) + 1;
			}
		}
	}

	return t[l1][l2];
}

int main()
{
	string s1 = "abcdef";
	string s2 = "azced";
	cout<<edit_distance(s1,s2)<<endl;
	return 0;
}