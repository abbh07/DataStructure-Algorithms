/*
4 5
0 0 1 1 1
1 0 1 1 1
0 1 1 1 1
1 0 1 1 1
o/p:
3
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_subsquare(vector< vector<int> > &v, int r, int c)
{
	vector< vector<int> > t(r+1,vector<int>(c+1));
	int dimension = INT_MIN;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(v[i-1][j-1] == 1)
			{
				t[i][j] = min(min(t[i-1][j-1],t[i-1][j]),t[i][j-1]) + 1;
			}
			if(t[i][j] > dimension)
			{
				dimension = t[i][j];
			}
		}
	}
	return dimension;
}

int main()
{
	int r;
	cin>>r;
	int c;
	cin>>c;
	vector< vector<int> > v(r,vector<int>(c));
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>v[i][j];
		}
	}
	cout<<max_subsquare(v,r,c)<<"\n";
	return 0;
}